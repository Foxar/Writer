#include "SplashScreen.h"
#include "GameWindow.h"

SplashScreen::SplashScreen()
{

}

SplashScreen::SplashScreen(GameWindow* windowPtr)
{
    this->setGameWindowPointer(windowPtr);

    this->spr.setTexture(this->gameWindowP->TextureGroup.splash_Screen);
    this->spr.setColor(sf::Color(0,0,0,0));
    this->opening = true;
}

void SplashScreen::update()
{
    std::cout << "SPLASH" << std::endl;
    if(this->spr.getColor().a >= 255)
        this->opening = false;
    if(this->opening)
        this->spr.setColor(sf::Color(255,255,255,this->spr.getColor().a + 1));
    else
        this->spr.setColor(sf::Color(255,255,255,this->spr.getColor().a - 1));

    if(this->spr.getColor().a <= 0 && !this->opening)
        this->gameWindowP->changeState(mainMenu);

    //sf::Drawable *temp = &this->spr;

    this->gameWindowP->queSprites(this->spr);
}

void SplashScreen::setGameWindowPointer(GameWindow* window)
{
    this->gameWindowP = window;
}
