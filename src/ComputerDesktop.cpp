#include "ComputerDesktop.h"
#include "GameWindow.h"
#include "Textures.h"
#include "Button.h"
#include "App.h"
#include "App_WebBrowser.h"

ComputerDesktop::ComputerDesktop()
{
}

ComputerDesktop::ComputerDesktop(GameWindow *gameWindowP)
{
    this->gameWindowP = gameWindowP;
    std::cout << "GAMEWINDOW: " << this->gameWindowP << std::endl;
    this->TextureGroup = &this->gameWindowP->TextureGroup;
    this->desktop.setTexture(this->TextureGroup->computer_Desktop);
    this->desktop.setOrigin(this->desktop.getGlobalBounds().width/2,this->desktop.getGlobalBounds().height/2);
    this->desktop.setPosition(this->gameWindowP->camera_Desktop.getCenter());

    this->appMenuButton = Button(this->gameWindowP,this->desktop.getGlobalBounds().left,this->desktop.getGlobalBounds().top + this->desktop.getGlobalBounds().height - this->gameWindowP->TextureGroup.TextureRects[TRAppMenuActive].height, BUTAppMenu);
    this->appMenu = AppMenu(this->gameWindowP,this);
    this->nextDayButton = Button(this->gameWindowP,this->desktop.getGlobalBounds().left+this->desktop.getGlobalBounds().width,this->desktop.getGlobalBounds().top + this->desktop.getGlobalBounds().height, ButNextDay);
}

sf::FloatRect ComputerDesktop::getAppButtonBounds()
{
    return this->appMenuButton.getBounds();
}

void ComputerDesktop::update()
{

    //std::cout << "DIALOGUELIST SIZE: " << this->dialogueList.size() << std::endl;

    if(this->gameWindowP->input == InMouseRight)
        std::cout << "MOUSE POS: " << this->gameWindowP->getMousePos().x << ", " << this->gameWindowP->getMousePos().y << std::endl;
    this->gameWindowP->camera_Desktop.setCenter(this->desktop.getGlobalBounds().left + (this->desktop.getGlobalBounds().width/2),
                                                this->desktop.getGlobalBounds().top + (this->desktop.getGlobalBounds().height/2));


        for(unsigned i = 0; i < this->dialogueList.size(); i++)
        {
            this->dialogueList[i].update();


            if(this->dialogueList.size() > 0)
            {
                if(this->dialogueList[i].setToDelete)
                {
                    this->dialogueList.erase(this->dialogueList.begin() + i);
                    //this->dialogueList.clear();
                    break;
                }
            }
            if(this->dialogueList.size() <= 0)
                break;

            this->render();
        }
        if(this->dialogueList.size() > 0)   //RETURN FROM UPDATE TO FORCE PLAYER INTERACTION WITH DIALOGUE BOX
            return;

    this->checkDesktopButtonPressed();

    this->appMenuButton.update();
    if(this->dailyPostDone)
        this->nextDayButton.update();

    if(this->appMenuButton.getActive())
    {
        if(!this->appMenu.getActive())
            this->appMenu.setActive(true);
        else
            this->appMenu.setActive(false);
    }
    if(this->nextDayButton.getActive())
    {
        this->gameWindowP->contMgr.ProgressToNextDay();
    }
    this->appMenu.update();
    if(this->appMenu.tempApp != 0)
    {
        this->activeApp = this->appMenu.tempApp;
        this->appMenu.tempApp = 0;
    }

    if(this->activeApp != 0)
    {
        if(this->activeApp->isSetToClose())
        {
            delete this->activeApp;
            this->activeApp = 0;
        }
        else
        {
            this->activeApp->update();
            this->activeApp->App::update();
        }

    }

    this->render();

}

void ComputerDesktop::queSprites(sf::Sprite spr)
{
    this->gameWindowP->queSprites(spr);
}

void ComputerDesktop::render()
{
    this->queSprites(this->desktop);
    if(this->activeApp != 0 && !this->activeApp->isSetToClose())
    {
        this->activeApp->App::render();
        this->activeApp->render();
    }
    this->appMenuButton.render();
    if(this->appMenu.getActive())
    {
        this->appMenu.render();
    }
    for(unsigned i = 0; i < this->dialogueList.size(); i++)
    {
        this->dialogueList[i].render();
    }
    if(this->dailyPostDone)
    {
        this->nextDayButton.render();
    }
}

void ComputerDesktop::checkDesktopButtonPressed()
{
    if(this->gameWindowP->input == InMouseLeft)
    {
        if(this->appMenuButton.getBounds().contains(this->gameWindowP->getMousePos()))
        {
            this->appMenuButton.Click();

        }
    }
}

unsigned ComputerDesktop::getDialogueListSize()
{
    return this->dialogueList.size();
}

void ComputerDesktop::spawnDialogueBox(dialogueBoxType type, Website* websiteP)
{
    this->dialogueList.push_back(DialogueBox(this->gameWindowP, this->TextureGroup, websiteP, 0, 0, type));
    std::cout << "SPAWNED A DIALOGUE BOX" << std::endl;

}


























