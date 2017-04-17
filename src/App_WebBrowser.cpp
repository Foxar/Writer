#include "App_WebBrowser.h"
#include "GameWindow.h"
#include "Website.h"

App_WebBrowser::App_WebBrowser(GameWindow *gameWindowP) : App(gameWindowP)
{
    this->windowSpr.setTexture(this->TextureGroup->app_WebBrowser);
    this->windowSpr.setPosition(this->gameWindowP->getViewRect().left, this->gameWindowP->getViewRect().top);
    this->type = APPBrowser;

    this->exitButton = Button(this->gameWindowP, this->windowSpr.getGlobalBounds().left, this->windowSpr.getGlobalBounds().top, ButAppUtilClose);

    this->websiteP = new Website(this->gameWindowP,this, this->defaultWebsite);
    this->urlSprite.setTexture(this->TextureGroup->tex_URL_homePage);
    this->urlSprite.setPosition(this->getBounds().left + this->getURLOffset().x,
                                this->getBounds().top + this->getURLOffset().y);
}

void App_WebBrowser::render()
{
    this->exitButton.render();
    if(this->websiteP != 0)
        this->websiteP->render();

    this->queSprites(this->urlSprite);
}

void App_WebBrowser::update()
{
    if(this->gameWindowP->input == InMouseLeft)
    {
        if(this->exitButton.getBounds().contains(this->gameWindowP->getMousePos()))
        {
            this->exitButton.Click();
        }
    }

    this->checkURL();

    this->exitButton.update();

    if(this->exitButton.getActive())
    {
        this->toClose = true;
    }

    this->websiteP->update();
    for(unsigned i = 0; i < this->websiteP->buttonList.size(); i++)
    {
        this->websiteP->buttonList[i].update(this);
        if(this->websiteP->buttonList[i].getActive() && this->websiteP->buttonList[i].getType() == ButHomeLink)
        {
            this->changeWebsite(this->websiteP->buttonList[i].getWebType());
        }
    }

}

App_WebBrowser::~App_WebBrowser()
{
    std::cout << "BROWSER DESTRUCTOR" << std::endl;
    delete this->websiteP;
    this->websiteP = 0;
    this->gameWindowP->Desktop.activeApp = 0;
}

sf::Vector2i App_WebBrowser::getWebPageOffset()
{
    return this->webPageOffset;
}

sf::Vector2i App_WebBrowser::getURLOffset()
{
    return this->URLOffset;
}

void App_WebBrowser::checkURL()
{
    if(this->websiteP != 0)
    {
        switch(this->websiteP->getPageType())
        {
        case WPBNN:
            {
                if(this->urlSprite.getTexture() != &this->TextureGroup->tex_URL_BNN)
                {
                    std::cout << "SET BNN" << std::endl;
                    this->urlSprite.setTexture(this->TextureGroup->tex_URL_BNN, true);
                }
            }
            break;
        case WPBlog:
            {
                if(this->urlSprite.getTexture() != &this->TextureGroup->tex_URL_blog)
                {
                    this->urlSprite.setTexture(this->TextureGroup->tex_URL_blog, true);
                }
            }
            break;
        case WPHome:
            {
                if(this->urlSprite.getTexture() != &this->TextureGroup->tex_URL_homePage)
                {
                    this->urlSprite.setTexture(this->TextureGroup->tex_URL_homePage, true);
                }
            }
            break;
        default:
            break;
        }
    }
}

void App_WebBrowser::changeWebsite(webPages websiteToChangeTo)
{
    this->websiteP->setToDelete = true;
    delete this->websiteP;
    this->gameWindowP->Desktop.dialogueList.clear();

    this->websiteP = new Website(this->gameWindowP,this, websiteToChangeTo);
}



