#include "App.h"
#include "Textures.h"
#include "GameWindow.h"

App::App(GameWindow *gameWindowP)
{
    this->gameWindowP = gameWindowP;
    this->TextureGroup = &this->gameWindowP->TextureGroup;
}
void App::render()
{
    this->queSprites(this->windowSpr);
}
void App::queSprites(sf::Sprite spr)
{
    this->gameWindowP->queSprites(spr);
}
void App::update()
{

}
sf::FloatRect App::getBounds()
{
    return this->windowSpr.getGlobalBounds();
}

bool App::isSetToClose()
{
    return this->toClose;
}

App::~App()
{
    this->gameWindowP = nullptr;
    this->TextureGroup = nullptr;
}

AppType App::getType()
{
    return this->type;
}
