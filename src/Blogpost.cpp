#include "Blogpost.h"
#include "Website.h"
#include "GameWindow.h"

Blogpost::Blogpost(GameWindow* gameWindowP, Website* websiteP, ComputerDesktop* desktopP, Article* articleP)
{

    this->websiteP = websiteP;
    this->gameWindowP = gameWindowP;
    this->desktopP = desktopP;
    this->articleP = articleP;

    std::cout << "FLAGS: " << int(this->websiteP->blogFlags) << std::endl;
    if(this->websiteP->blogFlags & WFCriticize)
    {
        std::cout << "CRITICIZE" << std::endl;
        this->str_title = this->articleP->bc_title;
        this->str_p1 = this->articleP->bc_para1;
        if(this->websiteP->blogFlags & WFCrit1)
            this->str_p2 = this->articleP->bc_para2_1;
        if(this->websiteP->blogFlags & WFCrit2)
            this->str_p2 = this->articleP->bc_para2_2;
        if(this->websiteP->blogFlags & WFCrit3)
            this->str_p2 = this->articleP->bc_para2_3;
        this->str_p3 = this->articleP->bc_para3;
    }
    else if(this->websiteP->blogFlags & WFSupport)
    {
        this->str_title = this->articleP->bs_title;
        this->str_p1 = this->articleP->bs_para1;
        this->str_p2 = this->articleP->bs_para2;
        this->str_p3 = this->articleP->bs_para3;
    }


    this->Title.setCharacterSize(30);
    this->Title.setFont(this->gameWindowP->TextureGroup.articleFont);
    this->Title.setFillColor(sf::Color::Black);

    this->p1.setCharacterSize(15);
    this->p1.setFont(this->gameWindowP->TextureGroup.articleFont);
    this->p1.setFillColor(sf::Color::Black);

    this->p2.setCharacterSize(15);
    this->p2.setFont(this->gameWindowP->TextureGroup.articleFont);
    this->p2.setFillColor(sf::Color::Black);

    this->p3.setCharacterSize(15);
    this->p3.setFont(this->gameWindowP->TextureGroup.articleFont);
    this->p3.setFillColor(sf::Color::Black);

    this->Title.setString(this->str_title);
//    this->p1.setString(this->str_p1);
//    this->p2.setString(this->str_p2);
//    this->p3.setString(this->str_p3);

    this->Title.setPosition(this->websiteP->getBounds().left + 5, this->websiteP->getBounds().top + 5);
    this->p1.setPosition(this->websiteP->getBounds().left + 22, this->websiteP->getBounds().top + 75);
    this->p2.setPosition(this->p1.getGlobalBounds().left, this->p1.getGlobalBounds().top + this->p1.getGlobalBounds().height + 20);
    this->p3.setPosition(this->p2.getGlobalBounds().left, this->p2.getGlobalBounds().top + this->p2.getGlobalBounds().height + 20);


}

void Blogpost::render()
{
    this->gameWindowP->queText(this->Title);
    this->gameWindowP->queText(this->p1);
    this->gameWindowP->queText(this->p2);
    this->gameWindowP->queText(this->p3);

}

void Blogpost::typeText(sf::Text* txt, std::string* str)
{
    if(str->size() > txt->getString().getSize())
    {

        if(txt->getGlobalBounds().left + txt->getGlobalBounds().width + 10 >= this->websiteP->getBounds().left + this->websiteP->getBounds().width)
        {

            for(int i = txt->getString().getSize()-1; i >= 0; i--)
            {
                if(str->substr(i,1) == " ")
                {
                    str->replace(i,1, "\n");
                    txt->setString(str->substr(0, txt->getString().getSize() + 3));
                    if(txt->getGlobalBounds().left + txt->getGlobalBounds().width + 10 >= this->websiteP->getBounds().left + this->websiteP->getBounds().width)
                    {
                        str->replace(i,1, " ");
                        txt->setString(str->substr(0, txt->getString().getSize()));
                    }
                    else
                    {
                        i = -1;
                        break;
                    }

                }
            }
            /*
            if(str->substr(txt->getString().getSize()-10,1) == " ")
            {
                str->replace(txt->getString().getSize()-10,1, "\n");
                std::cout << "REPLACED" << std::endl;
            }
            else
            {
                std::cout << "CURRENT CHAR: \"" << str->substr(txt->getString().getSize(),1) << "\" ." << std::endl;
            }
            */
            //txt->setString(str->substr(0, txt->getString().getSize() + 1).insert(txt->getString().getSize(), "\n"));
        }
        else
                txt->setString(str->substr(0, txt->getString().getSize() + 3));
        //std::cout << std::string(txt->getString().substring(txt->getString().getSize() - 1, 1));
        //std::cout << "SIZE: " << txt->getString().getSize() << std::endl;
    }
    else
        this->currentParagraph++;

}

void Blogpost::update()
{

    if(!this->complete)
    {
        switch(this->currentParagraph)
        {
        case 1:
            this->typeText(&this->p1,&this->str_p1);
            break;
        case 2:
            this->typeText(&this->p2,&this->str_p2);
            break;
        case 3:
            this->typeText(&this->p3,&this->str_p3);
            break;
        case 4:
            std::cout << this->str_p1 << std::endl;
            this->complete = true;
            break;
        default:
            std::cout << "DEFAULT CASE IN BLOGPOST::UPDATE() " << std::endl;
            break;
        }
        this->p2.setPosition(this->p1.getGlobalBounds().left, this->p1.getGlobalBounds().top + this->p1.getGlobalBounds().height + 20);
        this->p3.setPosition(this->p2.getGlobalBounds().left, this->p2.getGlobalBounds().top + this->p2.getGlobalBounds().height + 20);
    }

    this->render();


}

