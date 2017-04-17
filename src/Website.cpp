#include "Website.h"
#include "GameWindow.h"
#include "Button.h"
#include "App.h"
#include "App_WebBrowser.h"
#include "ComputerDesktop.h"
#include "enumController.h"

Website::Website()
{

}

void Website::setArticles()
{
    this->article1 = new Article(this->gameWindowP, this->desktopP, this->spr.getGlobalBounds().left + 92, this->spr.getGlobalBounds().top + 0,     this->gameWindowP->contMgr.getArtGroup().art1);
    this->article2 = new Article(this->gameWindowP, this->desktopP, this->spr.getGlobalBounds().left + 92, this->spr.getGlobalBounds().top + 150,   this->gameWindowP->contMgr.getArtGroup().art2);
    this->article3 = new Article(this->gameWindowP, this->desktopP, this->spr.getGlobalBounds().left + 92, this->spr.getGlobalBounds().top + 300,   this->gameWindowP->contMgr.getArtGroup().art3);


    this->buttonList.push_back(Button(this->gameWindowP,this->article1->getPosition().x-10, this->article1->getPosition().y-3,ButArticle, APPNone, WPNone, 1));
    this->buttonList.push_back(Button(this->gameWindowP,this->article2->getPosition().x-10, this->article2->getPosition().y-3,ButArticle, APPNone, WPNone, 2));
    this->buttonList.push_back(Button(this->gameWindowP,this->article3->getPosition().x-10, this->article3->getPosition().y-4,ButArticle, APPNone, WPNone, 3));


    std::cout << "SET ARTICLES" << std::endl;
}

Website::Website(GameWindow* gameWindowP, App_WebBrowser* parentApp, webPages type)
{
    this->gameWindowP = gameWindowP;
    this->textureP = &this->gameWindowP->TextureGroup;
    this->desktopP = &this->gameWindowP->Desktop;
    this->browserP = parentApp;
    this->pageType = type;

    this->spr.setPosition(this->browserP->getBounds().left + this->browserP->getWebPageOffset().x,
                          this->browserP->getBounds().top + this->browserP->getWebPageOffset().y);

    if(this->pageType != WPBlog)
        this->blogFlags = 0;

    switch(this->pageType)
    {
    case WPHome:
        {
            this->spr.setTexture(this->textureP->tex_web_Homepage);
            this->buttonList.push_back(Button(this->gameWindowP,int(this->spr.getPosition().x+30),int(this->spr.getPosition().y+23), ButHomeLink, APPNone,WPBNN));
            this->buttonList.push_back(Button(this->gameWindowP,int(this->spr.getPosition().x+271),int(this->spr.getPosition().y+23), ButHomeLink, APPNone,WPBlog));

        }
        break;
    case WPBNN:
        {
            this->spr.setTexture(this->textureP->tex_web_BNN);
            this->setArticles();
        }
        break;
    case WPBlog:
        {
            this->spr.setTexture(this->textureP->tex_web_Blog);
            this->buttonList.push_back(Button(gameWindowP, this->spr.getPosition().x+903, this->spr.getPosition().y+44,ButComments));
            this->commentList.push_back(CommentBox(this, this->gameWindowP));

            if(this->desktopP->articleChosen.size() != 0)
            {
                this->desktopP->spawnDialogueBox(d_CritSup,this);
            }

        }
        break;
    default:
        std::cout << "DEFAULT CASE IN WEBSITE.CPP" << std::endl;
        break;
    }

}

Website::~Website()
{
    this->buttonList.clear();
    delete this->article1;
    this->article1 = 0;
    delete this->article2;
    this->article2 = 0;
    delete this->article3;
    this->article3 = 0;

    this->gameWindowP = 0;
    this->browserP = 0;
    this->desktopP = 0;
    this->textureP = 0;
}

void Website::queSprites(sf::Sprite spr)
{
    globalWindowPtr->queSprites(spr);
}

void Website::render()
{
    this->queSprites(this->spr);
    for(unsigned i = 0; i < this->buttonList.size(); i++)
    {
        this->buttonList[i].render();
    }
    if(this->article1 != 0)
        this->article1->render();
    if(this->article2 != 0)
        this->article2->render();
    if(this->article3 != 0)
        this->article3->render();

    for(unsigned i = 0; i < this->commentList.size(); i ++)
    {
        this->commentList[i].render();
    }
}

void Website::update()
{

    for(unsigned i = 0; i < this->commentList.size(); i++)
    {
        this->commentList[i].update();
        if(this->commentList[i].deployed)
            this->commentList[i].xSpeed = 0;
        if(!this->commentList[i].buttonDown && this->commentList[i].deployed)
        {
            this->commentList[i].xSpeed = this->commentList[i].speed;
        }
    }
    for(unsigned i = 0; i < this->buttonList.size(); i++)
    {
        switch(this->pageType)
        {
        case WPBNN:
            {
                if(this->buttonList[i].getActive() && this->buttonList[i].articleAssigned != 0) //ARTICLE BUTTONS HAVE INTEGERS TO SYMBOLISE WHICH ARTICLE THEY REPRESENT
                {
                    this->desktopP->spawnDialogueBox(d_YesNo,this);

                    switch(this->buttonList[i].articleAssigned)
                    {
                    case 1:
                        this->browserP->currentArticleP = this->article1;
                        this->desktopP->articleChosen.clear();
                        this->desktopP->articleChosen.push_back(*this->article1);
                        break;
                    case 2:
                        this->browserP->currentArticleP = this->article2;
                        this->desktopP->articleChosen.clear();
                        this->desktopP->articleChosen.push_back(*this->article2);
                        break;
                    case 3:
                        this->browserP->currentArticleP = this->article3;
                        this->desktopP->articleChosen.clear();
                        this->desktopP->articleChosen.push_back(*this->article3);
                        break;
                    default:
                        break;
                    }
                    std::cout << "ARTICLE ASSIGNED: " << this->browserP->currentArticleP << std::endl;


                }
            }
            break;
        case WPBlog:
            {
                if(this->buttonList[i].getActive())
                {
                    switch(this->buttonList[i].getType())
                    {
                        case ButComments:
                        {

                            if(this->commentList.size() == 1)
                            {
                                this->commentList.back().xSpeed = -this->commentList.back().speed;
                                this->commentList.back().buttonDown = true;
                            }
                            else
                            {
                                std::cout << "ERROR: COMMENTLIST SIZE IS NOT 1." << std::endl;
                                std::cin.ignore();
                                this->gameWindowP->close();
                            }
                        }
                        break;
                        case ButBlogPost:
                            {
                                //POST THE BLOG POST.
                                this->gameWindowP->contMgr.Post(*this->browserP->postP);
                            }
                            break;
                    default:
                        break;
                    }
                }
                if(this->buttonList[i].getType() == ButComments && !this->buttonList[i].getActive() && this->commentList.size()> 0)
                    this->commentList.back().buttonDown = false;

                if(this->browserP->postP != 0)
                {
                    this->browserP->postP->update();
                    if(this->browserP->postP->complete && !(this->blogFlags & WFPostReady))
                    {
                        this->blogFlags |= WFPostReady;
                        this->buttonList.push_back(Button(this->gameWindowP,this->getBounds().left + 2,this->getBounds().top + 425,ButBlogPost,APPBrowser,WPBlog));
                    }
                    if(this->gameWindowP->Desktop.dailyPostDone)
                    {
                        for(unsigned i = 0; i < this->buttonList.size(); i++)
                        {
                            if(this->buttonList[i].getType() == ButBlogPost)
                            {
                                this->buttonList.erase(this->buttonList.begin() + i);
                                break;
                            }

                        }
                    }
                }

            }
            break;
        }
    }
    switch(this->pageType)
    {
    case WPBNN:
        {
            this->checkDialogueBoxes();
            if(this->setToDelete)
            {
                delete this;
                return;
            }
        }
        break;
        case WPBlog:
            {
            }
            break;
        case WPHome:
            {

            }
            break;
        default:
            std::cout << "DEFAULT CASE IN WEBSITE.CPP" << std::endl;
            break;
    }


    this->render();
}

webPages Website::getPageType()
{
    return this->pageType;
}

void Website::checkDialogueBoxes()
{
    std::vector<unsigned>indexToRemove;
    //startOverDialogueListLoop:
    for(unsigned i = 0; i < this->gameWindowP->Desktop.getDialogueListSize(); i++)
    {
        switch(this->gameWindowP->Desktop.dialogueList[i].getReturn())
        {
        case dr_No:
            {

                std::cout << "DIALOGUE BOX DELETED" << std::endl;
                //this->gameWindowP->Desktop.dialogueList.erase(this->gameWindowP->Desktop.dialogueList.begin() + i);
                this->gameWindowP->Desktop.dialogueList[i].setToDelete = true;
                for(unsigned a = 0; a < this->gameWindowP->Desktop.articleChosen.size(); a++)
                {
                    this->gameWindowP->Desktop.articleChosen.erase(this->gameWindowP->Desktop.articleChosen.begin() + a);
                }
            }
            break;
        case dr_Yes:
            {
                std::cout << "BNN WEBSITE: " << this << std::endl;
                //this->gameWindowP->Desktop.dialogueList.erase(this->gameWindowP->Desktop.dialogueList.begin() + i);
                this->gameWindowP->Desktop.dialogueList[i].setToDelete = true;
                this->browserP->changeWebsite(WPBlog);
                std::cout << "NEW WEBSITE: " << this << std::endl;
                return;
            }
            break;
        case dr_None:
            {

            }
            break;
        case dr_Criticize:
            {
                //this->gameWindowP->Desktop.dialogueList.erase(this->gameWindowP->Desktop.dialogueList.begin() + i);
                this->gameWindowP->Desktop.dialogueList[i].setToDelete = true;
                this->gameWindowP->Desktop.dialogueList.clear();
                this->blogFlags |= WFCriticize;
                this->desktopP->spawnDialogueBox(d_ThreeOpts, this);
                return;
            }
            break;
        case dr_Support:
            {
                //this->gameWindowP->Desktop.dialogueList.erase(this->gameWindowP->Desktop.dialogueList.begin() + i);
                this->gameWindowP->Desktop.dialogueList[i].setToDelete = true;
                //GENERATE SUPPORTIVE BLOGPOST
                this->blogFlags |= WFSupport;
                if(this->pageType == WPBlog)
                    this->generateBlogPost();

            }
            break;
        case dr_crit1:
            {
                this->gameWindowP->Desktop.dialogueList[i].setToDelete = true;
                //this->gameWindowP->Desktop.dialogueList.clear();
                this->blogFlags |= WFCrit1;
                if(this->pageType == WPBlog)
                    this->generateBlogPost();
            }
            break;
        case dr_crit2:
            {
                this->gameWindowP->Desktop.dialogueList[i].setToDelete = true;
                //this->gameWindowP->Desktop.dialogueList.clear();
                this->blogFlags |= WFCrit2;
                if(this->pageType == WPBlog)
                    this->generateBlogPost();
            }
            break;
        case dr_crit3:
            {
                this->gameWindowP->Desktop.dialogueList[i].setToDelete = true;
                //this->gameWindowP->Desktop.dialogueList.clear();
                this->blogFlags |= WFCrit3;
                if(this->pageType == WPBlog)
                    this->generateBlogPost();
            }
            break;
        }
    }
    if(this->gameWindowP->Desktop.dialogueList.size() > 0)
    {
        if( this->gameWindowP->Desktop.dialogueList.back().getReturn() == dr_Yes ||
            this->gameWindowP->Desktop.dialogueList.back().getReturn() == dr_No)
            this->gameWindowP->Desktop.dialogueList.clear();
    }
    for(unsigned i = 0; i < indexToRemove.size(); i++)
    {
        //this->gameWindowP->Desktop.dialogueList.erase(this->gameWindowP->Desktop.dialogueList.begin() + indexToRemove[i]);
        //i = 0;
    }
}

App_WebBrowser* Website::getBrowserP()
{
    return this->browserP;
}

sf::FloatRect Website::getBounds()
{
    return this->spr.getGlobalBounds();
}


void Website::generateComments()
{
//    this->commentList.push_back(CommentBox());

}

CommentBox::CommentBox(Website* websiteP, GameWindow* gamewindowP)
{
    this->websiteP = websiteP;
    this->gamewindowP = gamewindowP;
    this->textureP = &this->gamewindowP->TextureGroup;
    this->spr_commentBox.setTexture(this->textureP->tex_webItem_comments);
    this->spr_commentBox.setPosition(this->websiteP->getBounds().left + this->websiteP->getBounds().width, this->websiteP->getBounds().top + 76);

}

void CommentBox::update()
{
    if(abs(this->spr_commentBox.getGlobalBounds().left + this->spr_commentBox.getGlobalBounds().width - this->websiteP->getBounds().left + this->websiteP->getBounds().width) * 0.01 > 0.1)
    {
        this->speed = abs(this->spr_commentBox.getGlobalBounds().left + this->spr_commentBox.getGlobalBounds().width - this->websiteP->getBounds().left + this->websiteP->getBounds().width) * 0.01;
    }
    else
        this->speed = 0.01;

    if(this->xSpeed != 0)
        std::cout << "SPEED: " << this->xSpeed << std::endl;
    this->spr_commentBox.move(this->xSpeed,0);
    if(this->spr_commentBox.getGlobalBounds().left + this->spr_commentBox.getGlobalBounds().width <= this->websiteP->getBounds().left + this->websiteP->getBounds().width)
    {
        this->spr_commentBox.setPosition(this->websiteP->getBounds().left + this->websiteP->getBounds().width - this->spr_commentBox.getGlobalBounds().width, this->spr_commentBox.getPosition().y);
        this->deployed = true;
    }
    else if(this->spr_commentBox.getGlobalBounds().left >= this->websiteP->getBounds().left + this->websiteP->getBounds().width &&
            this->xSpeed > 0)
    {
            this->xSpeed = 0;
        this->deployed = false;
    }
    else
        this->deployed = false;
}

void CommentBox::render()
{
    this->gamewindowP->queSprites(this->spr_commentBox,2);
}


void Website::generateBlogPost()
{
    std::cout << "GENERATING BLOGPOST..." << std::endl;
    if(this->desktopP->articleChosen.size() > 0)
    {
        this->browserP->postP = new Blogpost(this->gameWindowP, this, this->desktopP, &this->desktopP->articleChosen.back());
    }
    else
        std::cout << "STD::VECTOR ARTICLECHOSEN SIZE IS 0" << std::endl;


}











