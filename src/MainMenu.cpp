#include "MainMenu.h"
#include "GameWindow.h"

MainMenu::MainMenu()
{

}

MainMenu::MainMenu(GameWindow* windowPtr)
{
    this->gameWindowP = windowPtr;

    this->TitleSpr.setTexture(this->gameWindowP->TextureGroup.menu_Title);
    this->TitleSpr.setOrigin(this->TitleSpr.getGlobalBounds().width/2, this->TitleSpr.getGlobalBounds().height/2);
    this->TitleSpr.setPosition(this->gameWindowP->getViewCenter().x, this->gameWindowP->getViewCenter().y - (this->TitleSpr.getGlobalBounds().height * 2));

    this->PlayText.setTexture(this->gameWindowP->TextureGroup.menu_Play);
    this->PlayText.setOrigin(this->PlayText.getGlobalBounds().width/2, this->PlayText.getGlobalBounds().height/2);
    this->PlayText.setPosition(this->gameWindowP->getViewCenter().x, this->gameWindowP->getViewCenter().y);
    this->PlayText.setColor(sf::Color::Black);

    this->SettingsText.setTexture(this->gameWindowP->TextureGroup.menu_Settings);
    this->SettingsText.setOrigin(this->SettingsText.getGlobalBounds().width/2, this->SettingsText.getGlobalBounds().height/2);
    this->SettingsText.setPosition(this->gameWindowP->getViewCenter().x, this->PlayText.getGlobalBounds().top + this->PlayText.getGlobalBounds().height + 5);

    this->ExitText.setTexture(this->gameWindowP->TextureGroup.menu_Exit);
    this->ExitText.setOrigin(this->ExitText.getGlobalBounds().width/2, this->ExitText.getGlobalBounds().height/2);
    this->ExitText.setPosition(this->gameWindowP->getViewCenter().x, this->SettingsText.getGlobalBounds().top + this->SettingsText.getGlobalBounds().height + 5);

    this->Selector.setFillColor(sf::Color::White);
    this->Selector.setOutlineThickness(1);
    this->Selector.setOutlineColor(sf::Color::White);
    this->Selector.setPosition(this->PlayText.getGlobalBounds().left - 1,
                               this->PlayText.getGlobalBounds().top - 1);
    this->Selector.setSize(sf::Vector2f(this->PlayText.getGlobalBounds().width + 2,
                           this->PlayText.getGlobalBounds().height + 2));

}

void MainMenu::chooseSelectorPosition(sf::FloatRect target)
{
    this->Selector.setPosition(target.left - 1,
                               target.top - 1);

    this->Selector.setSize(sf::Vector2f(target.width + 2,
                                        target.height + 2));
}

void MainMenu::update()
{
    this->gameWindowP->setCamera(this->gameWindowP->camera_MainMenu);
    if(this->PlayText.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
    {
        this->chooseSelectorPosition(this->PlayText.getGlobalBounds());
        this->PlayText.setColor(sf::Color::Black);
        this->ExitText.setColor(sf::Color::White);
        this->SettingsText.setColor(sf::Color::White);
        this->Selected = MMOPlay;
    }
    else if(this->SettingsText.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
    {
        this->chooseSelectorPosition(this->SettingsText.getGlobalBounds());
        this->SettingsText.setColor(sf::Color::Black);
        this->ExitText.setColor(sf::Color::White);
        this->PlayText.setColor(sf::Color::White);
        this->Selected = MMOSettings;
    }
    else if(this->ExitText.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
    {
        this->chooseSelectorPosition(this->ExitText.getGlobalBounds());
        this->ExitText.setColor(sf::Color::Black);
        this->SettingsText.setColor(sf::Color::White);
        this->PlayText.setColor(sf::Color::White);
        this->Selected = MMOExit;
    }
    else
    {
        this->chooseSelectorPosition(sf::FloatRect(-1000,0,0,0));
        this->ExitText.setColor(sf::Color::White);
        this->SettingsText.setColor(sf::Color::White);
        this->PlayText.setColor(sf::Color::White);
        this->Selected = MMONone;
    }

    if(this->Selected != MMONone)
    {
        this->gameWindowP->setCursor(CURClick);
    }

    switch(this->gameWindowP->input)
    {
    case InMouseLeft:
        {
            if(this->Selected == MMOExit)
                this->gameWindowP->close();
            else if(this->Selected == MMOPlay)
                this->gameWindowP->changeState(desktop);
            else if(this->Selected == MMOSettings)
                this->gameWindowP->changeState(settings);
        }
        break;
    case InMouseRight:

        break;
    }

    this->render();
}


void MainMenu::queSprites(sf::Sprite spr)
{
    this->gameWindowP->queSprites(spr);

}

void MainMenu::render()
{
    this->gameWindowP->queShapes(this->Selector);
    this->queSprites(this->PlayText);
    this->queSprites(this->ExitText);
    this->queSprites(this->SettingsText);
    this->queSprites(this->TitleSpr);

}
