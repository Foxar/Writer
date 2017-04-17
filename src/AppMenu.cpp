#include "AppMenu.h"
#include "GameWindow.h"
#include "MainMenu.h"
#include "Button.h"
#include "ComputerDesktop.h"
#include "Textures.h"
#include "App_WebBrowser.h"

AppMenu::AppMenu()
{

}

AppMenu::AppMenu(GameWindow *win, ComputerDesktop *desk)
{
    this->active = false;
    this->desktopP = desk;
    this->gameWindowP = win;
    this->TextureGroup = &this->gameWindowP->TextureGroup;

    this->spr.setTexture(this->TextureGroup->app_Menu);
    this->spr.setPosition(this->desktopP->appMenuButton.getBounds().left,
                          this->desktopP->appMenuButton.getBounds().top - this->spr.getGlobalBounds().height - 1);

    this->APPBrowserIcon = Button(this->gameWindowP, this->spr.getGlobalBounds().left, this->spr.getGlobalBounds().top + 12, BUTAppIcon, APPBrowser);
    this->APPEmailIcon = Button(this->gameWindowP, this->spr.getGlobalBounds().left, this->APPBrowserIcon.getBounds().top + this->APPBrowserIcon.getBounds().height, BUTAppIcon, APPEmail);
    this->APPOptionsIcon = Button(this->gameWindowP, this->spr.getGlobalBounds().left, this->APPEmailIcon.getBounds().top + this->APPEmailIcon.getBounds().height, BUTAppOptions);
}

void AppMenu::queSprites(sf::Sprite spr)
{
    this->gameWindowP->queSprites(spr);
}

void AppMenu::update()
{
    if(!this->active)
        return;

    this->APPBrowserIcon.update();
    this->APPEmailIcon.update();
    this->APPOptionsIcon.update();


    if(this->APPBrowserIcon.getActive())
    {
//        this->active = false;
//        this->APPBrowserIcon.setActive(false);
//        this->desktopP->appMenuButton.setActive(false);
//        this->tempApp = new App_WebBrowser(this->gameWindowP);
    }
    if(this->APPOptionsIcon.getActive())
    {
        this->active = false;
        this->gameWindowP->changeState(settings, false);
        this->APPOptionsIcon.setActive(false);
    }

    return;

}

void AppMenu::render()
{
    this->queSprites(this->spr);
    this->APPBrowserIcon.render();
    this->APPEmailIcon.render();
    this->APPOptionsIcon.render();

    this->setActive(false);
}

bool AppMenu::getActive()
{
    return this->active;
}

void AppMenu::setActive(bool active)
{
    this->active = active;
}
