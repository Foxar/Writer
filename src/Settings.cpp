#include "Settings.h"
#include "GameWindow.h"
#include "Button.h"

Settings::Settings()
{

}

Settings::Settings(GameWindow* window)
{

    this->gameWindowP = window;

    this->fullscreenSwitchButton = Button(this->gameWindowP, this->gameWindowP->camera_MainMenu.getCenter().x - (this->gameWindowP->camera_MainMenu.getSize().x/2) + 200, this->gameWindowP->camera_MainMenu.getCenter().y, BUTSwitch);
    if(this->gameWindowP->Fullscreen)
        this->fullscreenSwitchButton.setActive(true);
    else
        this->fullscreenSwitchButton.setActive(false);


    this->label_fullscreen.setTexture(this->gameWindowP->TextureGroup.label_fullscreen);
    this->label_fullscreen.setOrigin(0,this->label_fullscreen.getGlobalBounds().height/2);
    this->label_fullscreen.setPosition(this->fullscreenSwitchButton.getBounds().left - this->label_fullscreen.getGlobalBounds().width - 5,this->fullscreenSwitchButton.getBounds().top + (this->fullscreenSwitchButton.getBounds().height/4));

    this->ExitText.setTexture(this->gameWindowP->TextureGroup.menu_Exit);
    this->ExitText.setPosition(this->gameWindowP->getViewCenter().x  + 50,
                               this->gameWindowP->getViewCenter().y + 50);



    this->Selector.setOutlineThickness(1);
    this->Selector.setOutlineColor(sf::Color::White);
    this->Selector.setPosition(this->ExitText.getGlobalBounds().left - 1,
                               this->ExitText.getGlobalBounds().top - 1);
    this->Selector.setSize(sf::Vector2f(this->ExitText.getGlobalBounds().width + 2,
                           this->ExitText.getGlobalBounds().height + 2));
}

void Settings::queSprites(sf::Sprite spr)
{
    this->gameWindowP->queSprites(spr);
}

void Settings::queShapes(sf::RectangleShape shape)
{
    this->gameWindowP->queShapes(shape);
}

void Settings::render()
{
    this->fullscreenSwitchButton.render();
    this->gameWindowP->queShapes(this->Selector);
    this->queSprites(this->label_fullscreen);
    this->queSprites(this->ExitText);
}

void Settings::update()
{

    if(this->gameWindowP->input == InMouseLeft)
    {
        if(this->gameWindowP->InGame)
        {
            if(this->ExitText.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
            {
                this->gameWindowP->changeState(desktop);
            }
        }
        else
        {
            if(this->ExitText.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
            {
                this->gameWindowP->changeState(mainMenu);
                std::cout << "MAIN MENU" << std::endl;
            }
        }
    }
    if(this->ExitText.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
    {
        this->chooseSelectorPosition(this->ExitText.getGlobalBounds());
        this->ExitText.setColor(sf::Color::Black);
        this->gameWindowP->setCursor(CURClick);
    }
    else
    {
        this->chooseSelectorPosition(sf::FloatRect(-1000,0,0,0));
        this->ExitText.setColor(sf::Color::White);
    }

    this->fullscreenSwitchButton.update();
    if(this->fullscreenSwitchButton.getActive() && !this->gameWindowP->Fullscreen)
    {
        this->gameWindowP->switchFullscreen(true);
    }
    else if(!this->fullscreenSwitchButton.getActive() && this->gameWindowP->Fullscreen)
    {
        this->gameWindowP->switchFullscreen(false);
    }


    this->render();
}

void Settings::chooseSelectorPosition(sf::FloatRect target)
{
    this->Selector.setPosition(target.left - 1,
                               target.top - 1);

    this->Selector.setSize(sf::Vector2f(target.width + 2,
                                        target.height + 2));
}
