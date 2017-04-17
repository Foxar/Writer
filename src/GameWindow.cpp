#include "GameWindow.h"
#include "SplashScreen.h"
#include "ComputerLoading.h"
#include "Settings.h"
#include "enumController.h"
#include "ContinuityManager.h"

GameWindow* globalWindowPtr = 0;

GameWindow::GameWindow()
{
    this->start();
}

void GameWindow::start()
{
    //this->contMgr = ContinuityManager(this);

    globalWindowPtr = this;
    this->TextureGroup = Textures();

    this->Splash = SplashScreen(this);
    this->Handler = InputHandler(this);
    this->Menu = MainMenu(this);
    this->Loading = ComputerLoading(this);
    this->Desktop = ComputerDesktop(this);


    this->tex_cursor.loadFromFile("res//ui//cursor.png");
    this->tex_curClick.loadFromFile("res//ui//click.png");
    this->cursor.setTexture(tex_cursor);
    this->cursor.setPosition(this->camera_MainMenu.getCenter());

    if(sf::VideoMode::getDesktopMode().height < this->HEIGHT ||
       sf::VideoMode::getDesktopMode().width < this->WIDTH)
    {
        this->win.create(sf::VideoMode(this->WIDTH, this->HEIGHT, 32), "Writer");
        this->Fullscreen = false;
    }
    else
    {
//      this->win.create(sf::VideoMode(this->WIDTH, this->HEIGHT, 32), "Writer", sf::Style::Fullscreen);
        this->win.create(sf::VideoMode(this->WIDTH, this->HEIGHT, 32), "Writer", sf::Style::Close);
        this->Fullscreen = true;
    }

    this->startWin();

    this->spreadsheet.setSmooth(false);

    this->loadTextures();

    //this->camera_MainMenu.zoom(SCALE);
    this->camera_MainMenu.setSize(WIDTH/MENU_SCALE,
                                  HEIGHT/MENU_SCALE);
    this->camera_Desktop.setSize(WIDTH,HEIGHT);
    this->camera_Desktop.setCenter(WIDTH/2,
                                   HEIGHT/2);
    this->setCamera(this->camera_MainMenu);

    this->SettingsMenu = Settings(this);
    this->run();
}

void GameWindow::startWin()
{
    this->win.setActive(true);
    this->win.setFramerateLimit(60);
    this->win.setKeyRepeatEnabled(false);
    this->win.setVerticalSyncEnabled(true);
    this->win.setMouseCursorVisible(false);
    this->win.setView(this->camera_MainMenu);
}

void GameWindow::run()
{
    while(this->win.isOpen())
    {
        if(this->tickClock.getElapsedTime().asMilliseconds() > 1000/this->TPS)
        {
            this->tickClock.restart();
            this->handleInput();
            this->tick();
            this->render();
        }
    }
}

void GameWindow::render()
{
/*
    if(this->getWindowSize().x > 1920)
    {
        this->win.setSize(sf::Vector2u(1920,this->win.getSize().y));
    }
    if(this->getWindowSize().y > 1080)
    {
        this->win.setSize(sf::Vector2u(this->win.getSize().x, 1080));
    }
    if(this->getWindowSize().x < 1024)
    {
        this->win.setSize(sf::Vector2u(1024,this->win.getSize().y));
    }
    if(this->getWindowSize().y < 576)
    {
        this->win.setSize(sf::Vector2u(this->win.getSize().x, 576));
    }

*/
    if(this->State == mainMenu ||
       this->State == settings)
    {
        this->setLetterBox(&camera_MainMenu);
    }
    else
        this->setLetterBox(&camera_Desktop);

    if(this->renderClock.getElapsedTime().asMicroseconds() > 16666.66666666667)
    {
        win.clear(sf::Color::Black);
        win.draw(sf::RectangleShape(sf::Vector2f(50,50)));
        this->renderClock.restart();
        for(unsigned i = 0; i < this->spriteContainer.ShapeList.size(); i++)
        {
            win.draw(this->spriteContainer.ShapeList[i]);
        }
        for(unsigned i = 0; i < this->spriteContainer.SpriteList.size(); i++)
        {
            win.draw(this->spriteContainer.SpriteList[i]);
        }
        for(unsigned i = 0; i < this->spriteContainer.TextList.size(); i++)
        {
            win.draw(this->spriteContainer.TextList[i]);
            //std::cout << "WIDTH OF TEXT: " << this->spriteContainer.TextList[i].getGlobalBounds().width << std::endl;
        }
        for(unsigned i = 0; i < this->spriteContainer.SpriteListLayer2.size(); i++)
        {
            win.draw(this->spriteContainer.SpriteListLayer2[i]);
        }
        for(unsigned i = 0; i < this->spriteContainer.TextList2.size(); i++)
        {
            win.draw(this->spriteContainer.TextList2[i]);
        }
        sf::View tempView = win.getDefaultView();
        this->setLetterBox(&tempView);
        win.setView(tempView);
        this->cursor.setPosition(this->getMousePos());
        win.draw(this->cursor);

        win.display();
    }
    this->spriteContainer.SpriteList.clear();
    this->spriteContainer.ShapeList.clear();
    this->spriteContainer.TextList.clear();
    this->spriteContainer.SpriteListLayer2.clear();
    this->spriteContainer.TextList2.clear();

    this->setCursor(CURNormal);

}

void GameWindow::tick()
{
    switch(this->State)
    {
    case splash:
        this->win.setView(this->camera_MainMenu);
        this->Splash.update();
        break;
    case mainMenu:
        this->win.setView(this->camera_MainMenu);
        this->Menu.update();
        break;
    case computerLoading:
        this->win.setView(this->camera_MainMenu);
        this->Loading.update();
        break;
    case desktop:
        this->win.setView(this->camera_Desktop);
        this->Desktop.update();
        break;
    case settings:
        this->win.setView(this->camera_MainMenu);
        this->SettingsMenu.update();
        break;
    case nextDayScreen:
        {
            std::cout << " NEXT DAY SCREEN " << std::endl;
            std::cout << "NOTORIETY: " << this->contMgr.getNotoriety() << std::endl;
            std::cout << "FOLLOWERS: " << this->contMgr.getFollowers() << std::endl;
            this->win.setView(this->camera_MainMenu);
            if(this->splashClock.getElapsedTime().asSeconds() > 3)
                this->changeState(desktop);
            sf::Text dayTxt(sf::String("DAY "+std::to_string(this->contMgr.getNDay())), this->TextureGroup.articleFont,60);
            sf::Text dateTxt(sf::String(std::to_string(int(this->contMgr.getDate().day))+"."+std::to_string(static_cast<int>(this->contMgr.getDate().month))+"."+std::to_string(int(this->contMgr.getDate().year))), this->TextureGroup.articleFont,60);
            dayTxt.setScale(0.25,0.25);
            dateTxt.setScale(0.25,0.25);
            dayTxt.setOrigin(sf::Vector2f(dayTxt.getLocalBounds().width/2,dayTxt.getLocalBounds().height/2));
            dateTxt.setOrigin(sf::Vector2f(dateTxt.getLocalBounds().width/2, dateTxt.getLocalBounds().height/2));


            dayTxt.setPosition(this->camera_MainMenu.getCenter());
            dateTxt.setPosition(dayTxt.getPosition().x, dayTxt.getPosition().y + (dayTxt.getGlobalBounds().height/2) + (dateTxt.getGlobalBounds().height));

            this->queText(dayTxt);
            this->queText(dateTxt);

            this->camera_MainMenu.setCenter(dayTxt.getPosition());



        }
        break;
    default:
        break;

    }

}

void GameWindow::queSprites(sf::Sprite spr, int layer)
{
    if(layer == 1)
        this->spriteContainer.SpriteList.push_back(spr);
    else if(layer == 2)
        this->spriteContainer.SpriteListLayer2.push_back(spr);
}

void GameWindow::queShapes(sf::RectangleShape rec)
{
    this->spriteContainer.ShapeList.push_back(rec);
}

void GameWindow::queText(sf::Text tex, int layer)
{
    if(layer == 1)
        this->spriteContainer.TextList.push_back(tex);
    else if(layer == 2)
        this->spriteContainer.TextList2.push_back(tex);
}

void GameWindow::changeState(gameStates state, bool reinitialize)
{
    std::cout << "STATE: " << state << std::endl;
    if(this->State == desktop)
    {
        this->Desktop.appMenu.setActive(false);
    }
    if(state == nextDayScreen)
    {
        this->splashClock.restart();
    }
    this->State = state;
    if(reinitialize)
        this->reinitialize();

}

sf::Vector2f GameWindow::getViewCenter()
{
    sf::Vector2f center = this->win.getView().getCenter();
    return center;
}

sf::IntRect GameWindow::getViewRect()
{
    return sf::IntRect(this->win.getView().getCenter().x - (this->win.getView().getSize().x/2),
                       this->win.getView().getCenter().y - (this->win.getView().getSize().y/2),
                       this->win.getView().getSize().x,
                       this->win.getView().getSize().y);
}

void GameWindow::loadTextures()
{
    this->spreadsheet.loadFromFile("res//largeSize//spreadsheet.png");
}

void GameWindow::setCamera(sf::View cam)
{
    this->win.setView(cam);
}

bool GameWindow::pollEvent(sf::Event e)
{
    if(this->win.pollEvent(e))
        return true;
    else
        return false;
}

void GameWindow::close()
{
    this->win.close();
    return;
}

sf::RenderWindow* GameWindow::getPointer()
{
    return &this->win;
}

void GameWindow::handleInput()
{
    this->input = InNone;
    while(this->win.pollEvent(this->event))
    {
        if(this->event.type == sf::Event::MouseButtonPressed)
        {
            if(this->event.mouseButton.button == sf::Mouse::Left)
            {
                this->input |= InMouseLeft;
            }
            if(this->event.mouseButton.button == sf::Mouse::Right)
            {
                this->input |= InMouseRight;
            }
        }
        if(this->event.type == sf::Event::Closed)
        {
            this->close();
        }


    }
}

sf::Vector2f GameWindow::getMousePos()
{
    sf::Vector2f pixelPos = sf::Vector2f(sf::Mouse::getPosition(this->win).x, sf::Mouse::getPosition(this->win).y);
    sf::Vector2f worldPos = this->win.mapPixelToCoords(sf::Vector2i(pixelPos.x, pixelPos.y));
    return worldPos;
}

sf::Vector2u GameWindow::getWindowSize()
{
    return this->win.getSize();
}

void GameWindow::reinitialize()
{

    switch(this->State)
    {
    case desktop:
        this->InGame = true;
        this->win.setView(this->camera_Desktop);
        break;
    case settings:
        this->win.setView(this->camera_MainMenu);
        break;
    case mainMenu:
        this->InGame = false;
    default:
        break;
    }
}

sf::Vector2u GameWindow::getDefaultWindowSize()
{
    return sf::Vector2u(this->WIDTH,this->HEIGHT);
}

void GameWindow::setLetterBox(sf::View* camera)
{
/*
    if((this->getWindowSize().x < 1920 || this->getWindowSize().y < 1080) &&
        this->getWindowSize().x > 1600 && this->getWindowSize().y > 900)
    {
        camera->setSize(1600,900);
    }
    else if((this->getWindowSize().x < 1600 || this->getWindowSize().y < 900) &&
             this->getWindowSize().x > 1280 && this->getWindowSize().y > 720)
     {
        camera->setSize(1280,720);
     }
     else if((this->getWindowSize().x < 1280 || this->getWindowSize().y < 720) &&
             this->getWindowSize().x > 1024 && this->getWindowSize().y > 576)
    {
        camera->setSize(1024,576);
    }
*/
    float winRatio = (float)this->getWindowSize().x / (float)this->getWindowSize().y;
    float cameraRatio = (float)camera->getSize().x / (float)camera->getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontal = true;
    if(winRatio <  cameraRatio)
        horizontal = false;

    if(horizontal)
    {
        sizeX = cameraRatio/winRatio;
        posX = (1-sizeX) / 2.f;
    }

    else
    {
        sizeY = winRatio/cameraRatio;
        posY = (1-sizeY) / 2.f;
    }

    camera->setViewport(sf::FloatRect(posX,posY,sizeX,sizeY));

}

void GameWindow::setCursor(CursorTypes type)
{
    this->cursor = sf::Sprite();
    if(type == CURNormal)
        this->cursor.setTexture(tex_cursor);
    else if(type == CURClick)
    {
        this->cursor.setTexture(tex_curClick);
        this->cursor.setOrigin(4,0);
    }
}

void GameWindow::switchFullscreen(bool fullscreen)
{
    this->Fullscreen = fullscreen;
    if(fullscreen)
    {
        this->win.close();
        this->win.create(sf::VideoMode(this->WIDTH, this->HEIGHT, 32), "Writer", sf::Style::Fullscreen);
        this->startWin();
    }
    else
    {
        this->win.close();
        this->win.create(sf::VideoMode(this->WIDTH, this->HEIGHT, 32), "Writer");
        this->startWin();
    }
}


void GameWindow::dayProgressionReset()
{
    this->Desktop = ComputerDesktop(this);
}












