#include "DialogueBox.h"
#include "Textures.h"
#include "GameWindow.h"
#include "App_WebBrowser.h"
#include "Website.h"

DialogueBox::DialogueBox()
{


}

DialogueBox::DialogueBox(GameWindow* gamewindowP, Textures* texturesP, Website* websiteP, int x, int y, dialogueBoxType type)
{
    this->gameWindowP = gamewindowP;
    this->TextureGroup = texturesP;
    this->websiteP = websiteP;
    this->browserP = this->websiteP->getBrowserP();

    this->type = type;

    this->spr.setTexture(this->TextureGroup->tex_dialogueBoxArticleChoice);
    this->spr.setOrigin(this->spr.getGlobalBounds().width/2, this->spr.getGlobalBounds().height/2);
    this->spr.setPosition(this->gameWindowP->getViewCenter());
    if(this->gameWindowP->Desktop.getDialogueListSize() > 0)
    {
        this->spr.setPosition( this->gameWindowP->Desktop.dialogueList.back().getBounds().left + 10 ,
                                this->gameWindowP->Desktop.dialogueList.back().getBounds().top + 10);
    }

    switch(this->type)
    {
    case d_YesNo:
        {
            sf::Vector2i yesPos = sf::Vector2i(this->spr.getGlobalBounds().left + (this->spr.getGlobalBounds().width/4) - (this->TextureGroup->TextureRects[TRDialogueYesInactive].width/2),
                                        this->spr.getGlobalBounds().top + (this->spr.getGlobalBounds().height*0.75) - (this->TextureGroup->TextureRects[TRDialogueYesInactive].height/2));

            sf::Vector2i noPos = sf::Vector2i(this->spr.getGlobalBounds().left + (this->spr.getGlobalBounds().width*0.75) - (this->TextureGroup->TextureRects[TRDialogueNoInactive].width/2),
                                               this->spr.getGlobalBounds().top + (this->spr.getGlobalBounds().height*0.75) - (this->TextureGroup->TextureRects[TRDialogueNoInactive].height/2));

            std::cout << "YESPOS: " << yesPos.x << ", " << yesPos.y << std::endl;
            std::cout << "NOPOS: " << noPos.y << ", " << noPos.y << std::endl;

            this->opt1 = Button(this->gameWindowP, yesPos.x, yesPos.y, ButDialogueYes, APPNone, WPNone, 0);
            this->opt2 = Button(this->gameWindowP, noPos.x, noPos.y, ButDialogueNo, APPNone, WPNone, 0);
        }
        break;
    case d_CritSup:
        {
            std::cout << "CRITSUP CONSTRUCTOR CALLED " << std::endl;



            this->spr.setTexture(this->TextureGroup->tex_dialogueBoxCritSup, true);
            sf::Vector2i yesPos = sf::Vector2i(this->spr.getGlobalBounds().left + (this->spr.getGlobalBounds().width/4) - (this->TextureGroup->TextureRects[TRDialogueYesInactive].width/2),
                                        this->spr.getGlobalBounds().top + (this->spr.getGlobalBounds().height*0.75) - (this->TextureGroup->TextureRects[TRDialogueYesInactive].height/2));

            sf::Vector2i noPos = sf::Vector2i(this->spr.getGlobalBounds().left + (this->spr.getGlobalBounds().width*0.75) - (this->TextureGroup->TextureRects[TRDialogueNoInactive].width/2),
                                               this->spr.getGlobalBounds().top + (this->spr.getGlobalBounds().height*0.75) - (this->TextureGroup->TextureRects[TRDialogueNoInactive].height/2));

            std::cout << "YESPOS: " << yesPos.x << ", " << yesPos.y << std::endl;
            std::cout << "NOPOS: " << noPos.y << ", " << noPos.y << std::endl;

            this->opt1 = Button(this->gameWindowP, yesPos.x, yesPos.y, ButDialogueCriticize, APPNone, WPNone, 0);
            this->opt2 = Button(this->gameWindowP, noPos.x, noPos.y, ButDialogueSupport, APPNone, WPNone, 0);
        }
        break;
    case d_ThreeOpts:
        {
            this->opt1Name = this->gameWindowP->Desktop.articleChosen.back().bc_para2_1_name;
            this->opt2Name = this->gameWindowP->Desktop.articleChosen.back().bc_para2_2_name;
            this->opt3Name = this->gameWindowP->Desktop.articleChosen.back().bc_para2_3_name;


            this->spr.setTexture(this->TextureGroup->tex_dialogueBoxItemChoice, true);

            this->opt1 = Button(this->gameWindowP, this->spr.getGlobalBounds().left + 2, this->spr.getGlobalBounds().top + 56, ButDialogueChoice, APPNone, WPNone, 0);
            this->opt2 = Button(this->gameWindowP, this->spr.getGlobalBounds().left + 2, this->spr.getGlobalBounds().top + 87, ButDialogueChoice, APPNone, WPNone, 0);
            this->opt3 = Button(this->gameWindowP, this->spr.getGlobalBounds().left + 2, this->spr.getGlobalBounds().top + 118, ButDialogueChoice, APPNone, WPNone, 0);

            this->labels.push_back(sf::Text(this->opt1Name, this->TextureGroup->articleFont, 15));
            this->labels.back().setOrigin(floor(this->labels.back().getGlobalBounds().width/2), floor(this->labels.back().getGlobalBounds().height/2));
            this->labels.back().setPosition(floor(this->opt1.getBounds().left + (this->opt1.getBounds().width/2)), floor(this->opt1.getBounds().top + (this->opt1.getBounds().height/2)));
            this->labels.back().setColor(sf::Color::Black);

            this->labels.push_back(sf::Text(this->opt2Name, this->TextureGroup->articleFont, 15));
            this->labels.back().setOrigin(floor(this->labels.back().getGlobalBounds().width/2), floor(this->labels.back().getGlobalBounds().height/2));
            this->labels.back().setPosition(floor(this->opt2.getBounds().left + (this->opt2.getBounds().width/2)), floor(this->opt2.getBounds().top  + (this->opt2.getBounds().height/2)));
            this->labels.back().setColor(sf::Color::Black);

            this->labels.push_back(sf::Text(this->opt3Name, this->TextureGroup->articleFont, 15));
            this->labels.back().setOrigin(floor(this->labels.back().getGlobalBounds().width/2), floor(this->labels.back().getGlobalBounds().height/2));
            this->labels.back().setPosition(floor(this->opt3.getBounds().left + (this->opt3.getBounds().width/2)), floor(this->opt3.getBounds().top + (this->opt3.getBounds().height/2)));
            this->labels.back().setColor(sf::Color::Black);


        }
        break;
    }
}

sf::FloatRect DialogueBox::getBounds()
{
    return this->spr.getGlobalBounds();
}

void DialogueBox::update()
{
    this->browserP->websiteP->checkDialogueBoxes();

    this->opt1.update();
    this->opt2.update();

    switch(this->type)
    {
    case d_YesNo:
        {
            if(this->opt1.getActive())
            {
                this->Return = dr_Yes;
            }
            else if(this->opt2.getActive())
            {
                this->Return = dr_No;
                std::cout << "OPT2 ACTIVE" << std::endl;
            }

        }
        break;
    case d_CritSup:
        {
            if(this->opt1.getActive())
            {
                this->Return = dr_Criticize;
            }
            else if(this->opt2.getActive())
            {
                this->Return = dr_Support;
            }
        }
        break;
    case d_ThreeOpts:
        {
            this->opt3.update();
            if(this->opt1.getActive())
            {
                this->Return = dr_crit1;
            }
            else if(this->opt2.getActive())
            {
                this->Return = dr_crit2;
            }
            else if(this->opt3.getActive())
            {
                this->Return = dr_crit3;
            }
        }
        break;
    default:
        std::cout << "UNKNOWN DIALOGUEBOX TYPE IN DIALOGUEBOX.CPP" << std::endl;
        break;
    }
}

dialogueBoxReturns DialogueBox::getReturn()
{
    return this->Return;
}

void DialogueBox::render()
{
    this->gameWindowP->queSprites(this->spr,2);
    this->opt1.render(2);
    this->opt2.render(2);
    if(this->type == d_ThreeOpts)
    {
        this->opt3.render(2);
        for(unsigned i = 0; i < this->labels.size(); i++)
        {
            this->gameWindowP->queText(this->labels[i],2);
        }
    }
}

DialogueBox::~DialogueBox()
{
    this->labels.clear();
}
