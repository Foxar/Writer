#include "Button.h"
#include "Textures.h"
#include "GameWindow.h"
#include "App_WebBrowser.h"

Button::Button()
{

}

void Button::setActive(bool active)
{
    this->active = active;
    if(active == true && this->type == BUTAppMenu)
        std::cout << "FUUCK " << std::endl;
}

Button::Button(GameWindow *gameWindowP, int x, int y, ButtonType type, AppType appType, webPages webType, int articlePicked)
{
    if(articlePicked != 0)
    {
        this->articleAssigned = articlePicked;
    }
    this->gameWindowP = gameWindowP;
    this->appType = appType;
    this->TextureGroup = &this->gameWindowP->TextureGroup;
    this->webType = webType;
    this->type = type;

    switch(this->type)
    {
    case ButBlogPost:
        {
            this->spr.setTexture(this->TextureGroup->tex_but_post);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRBlogPostInactive]);
        }
        break;
    case BUTAppMenu:
        {
            this->spr.setTexture(this->TextureGroup->app_Menu_Button);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRAppMenuInactive]);
        }
        break;
    case BUTSwitch:
        {
            this->spr.setTexture(this->TextureGroup->settings_switch);
            if(this->gameWindowP->Fullscreen)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRSwitchOn]);
            }
            else
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRSwitchOff]);
            }
        }
        break;
    case BUTAppIcon:
        {
            switch(this->appType)
            {
            case APPNone:
                std::cout << "APPNONE HANDED AS ARGUMENT FOR BUTTON CONSTRUCTOR." << std::endl;
                this->gameWindowP->close();
                break;
            case APPBrowser:
                this->spr.setTexture(this->TextureGroup->texIconWeb);
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRAppWebBrowserInActive]);
                break;
            case APPEmail:
                this->spr.setTexture(this->TextureGroup->texIconEmail);
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRAppEmailInActive]);
                break;
            default:
                std::cout << "ERROR BUTTON CONSTRUCTOR" << std::endl;
                break;
            }
        }
        break;
    case BUTAppOptions:
        {
            this->spr.setTexture(this->TextureGroup->texIconOpt);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRAppOptionsInactive]);
        }
        break;
    case ButAppUtilClose:
        {
            this->spr.setTexture(this->TextureGroup->tex_butt_exit);
        }
        break;
    case ButHomeLink:
        {
            this->spr.setTexture(this->TextureGroup->tex_home_buttons);
            switch(this->webType)
            {
            case WPBNN:
                {
                    this->spr.setTextureRect(this->TextureGroup->TextureRects[TRHomeBNNInActive]);
                }
                break;
            case WPBlog:
                {
                    this->spr.setTextureRect(this->TextureGroup->TextureRects[TRHomeBlogInActive]);
                }
                break;
            default:
                std::cout << "DEFAULT CASE IN BUTTON.CPP HOMELINK 2" << std::endl;
                break;
            }
        }
        break;
    case ButArticle:
        {
            this->spr.setTexture(this->TextureGroup->tex_web_BNN);
            this->spr.setTextureRect(sf::IntRect(0,0,740,148));
            this->spr.setColor(sf::Color(0,0,0,0));
        }
        break;
    case ButDialogueNo:
        {
            this->spr.setTexture(this->TextureGroup->tex_yesNo);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueNoInactive]);
        }
        break;
    case ButDialogueYes:
        {
            this->spr.setTexture(this->TextureGroup->tex_yesNo);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueYesInactive]);
        }
        break;
    case ButComments:
        {
            this->spr.setTexture(this->TextureGroup->tex_But_comments);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRBlogCommentButtonInActive]);
        }
        break;
    case ButDialogueChoice:
        {
            this->spr.setTexture(this->TextureGroup->tex_web_BNN);
            this->spr.setTextureRect(sf::IntRect(0,0,291,31));
            this->spr.setColor(sf::Color(0,0,0,255));

        }
        break;
    case ButDialogueCriticize:
        {
            this->spr.setTexture(this->TextureGroup->tex_critSup);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueCriticizeInactive]);
        }
        break;
    case ButDialogueSupport:
        {
            this->spr.setTexture(this->TextureGroup->tex_critSup);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueSupportInactive]);
        }
        break;
    case ButNextDay:
        {
            this->spr.setTexture(this->TextureGroup->tex_butt_nextDay);
            this->spr.setTextureRect(this->TextureGroup->TextureRects[TRNextDayButtonInactive]);
        }
        break;
    default:
        std::cout << "DEFAULT CASE IN BUTTON.CPP" << std::endl;
        std::cin.ignore();
        this->gameWindowP->close();
        break;

    }

    this->spr.setPosition(x,y);
}

void Button::Click()
{
    this->pressed = true;
    this->Cooldown.restart();
}

void Button::update(App_WebBrowser* parentBrowser)
{
//    std::cout << "BUTTON: " << this << std::endl;
//    std::cout << "RANDOM: " << this->active << std::endl;
//    std::cout << "GAMEWINDOW2: " << this->gameWindowP << std::endl;
    if(this->spr.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
    {
        this->gameWindowP->setCursor(CURClick);
        if(this->gameWindowP->input == InMouseLeft)
        {
            this->Click();
        }
    }
    switch(this->type)
    {
    case BUTAppMenu:
        {
            if(!this->highLighted && this->pressed)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRAppMenuActive]);
            }
            else if(this->highLighted && this->Cooldown.getElapsedTime().asMilliseconds() > BUTTON_COOLDOWN_MS)
            {
                this->Cooldown.restart();
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRAppMenuInactive]);
                this->highLighted = false;
            }

            if(this->pressed)
            {
                if(!this->highLighted)
                    this->highLighted =  true;
                this->active = !this->active;
                this->pressed = false;
            }


        }
        break;
    case BUTSwitch:
        {
            if(this->pressed && this->Cooldown.getElapsedTime().asMilliseconds() > BUTTON_COOLDOWN_MS)
            {
                this->active = !this->active;
                this->pressed = false;
            }

            if(this->active)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRSwitchOn]);
            }
            else
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRSwitchOff]);
            }

        }
        break;
    case BUTAppIcon:
        {
            TexRects Active;
            TexRects InActive;

            switch(this->appType)
            {
            case APPBrowser:
                Active = TRAppWebBrowserActive;
                InActive = TRAppWebBrowserInActive;
                break;
            default:
                break;

            }
            if(!this->highLighted && this->pressed)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[Active]);
                this->Cooldown.restart();
                this->highLighted = true;
            }
            else if(this->highLighted && this->Cooldown.getElapsedTime().asMilliseconds() > BUTTON_COOLDOWN_MS)
            {
                this->Cooldown.restart();
                this->spr.setTextureRect(this->TextureGroup->TextureRects[InActive]);
                this->highLighted = false;
            }

            if(this->pressed && !this->highLighted)
            {
                if(!this->highLighted)
                    this->highLighted =  true;
                this->active = !this->active;
                this->pressed = false;
                this->gameWindowP->Desktop.appMenu.setActive(false);

                this->gameWindowP->Desktop.appMenu.setActive(false);
                this->gameWindowP->Desktop.appMenuButton.setActive(false);
                this->gameWindowP->Desktop.appMenu.tempApp = new App_WebBrowser(this->gameWindowP);
            }


        }
        break;
    case BUTAppOptions:
        {
            if(!this->highLighted && this->pressed)
            {
                this->highLighted = true;
                this->pressed = false;
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRAppOptionsActive]);
                this->Cooldown.restart();
            }
            else if(this->highLighted && this->Cooldown.getElapsedTime().asMilliseconds() > BUTTON_COOLDOWN_MS)
            {
                this->active = !this->active;
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRAppOptionsInactive]);
                this->highLighted = false;
            }


        }
        break;
    case ButAppUtilClose:
        {
            if(this->pressed)
            {
                this->active = true;
                this->pressed = false;
            }
        }
        break;
    case ButHomeLink:
        {

            if(this->active)
                this->active = false;
            if(this->pressed)
            {
                if(this->type != ButHomeLink)
                    std::cout << " OH SHIT WATHC OUT " << std::endl;
                std::cout << "BUTTON OF " << this->type << " PRESSED" << std::endl;
                this->pressed = false;
                this->active = true;
                switch(this->webType)
                {
                case WPBNN:
                    this->spr.setTextureRect(this->TextureGroup->TextureRects[TRHomeBNNActive]);
                    break;
                case WPBlog:
                    this->spr.setTextureRect(this->TextureGroup->TextureRects[TRHomeBlogActive]);
                    break;
                default:
                    //std::cout << "DEFAULT CASE IN BUTTON.CPP BUTHOMELINK, WEBTYPE: " << this->webType << std::endl;
                    break;
                }
            }
        }
        break;
    default:
        std::cout << "DEFAULT CASE IN BUTTON.CPP, TYPE: " << this->type << std::endl;
        break;
    case ButArticle:
        {
            if(this->active)
            {
                this->active = false;
                this->pressed = false;
                this->highLighted = false;
                this->spr.setColor(sf::Color(sf::Color(0,0,0,255)));
            }
            if(this->spr.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
            {
                this->highLighted = true;
                //this->spr.setColor(sf::Color(sf::Color(0,0,0,100)));
            }
            else
            {
                this->highLighted = false;
                this->spr.setColor(sf::Color(sf::Color(0,0,0,0)));
            }


            if(this->pressed)
            {
                this->pressed = false;
                this->active = true;
            }
        }
        break;
    case ButDialogueNo:
        {
            if(this->active)
            {
                this->pressed = false;
                this->active = false;
                this->highLighted = false;
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueNoInactive]);
            }
            if(this->highLighted)
            {
                this->active = true;
            }
            if(this->pressed)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueNoActive]);
                this->highLighted = true;
                this->pressed = false;
            }
        }
        break;
    case ButDialogueYes:
        {
            if(this->active)
            {
                this->pressed = false;
                this->active = false;
                this->highLighted = false;
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueYesInactive]);
            }
            if(this->highLighted)
            {
                this->active = true;
            }
            if(this->pressed)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueYesActive]);
                this->highLighted = true;
                this->pressed = false;
            }
        }
        break;
    case ButComments:
        {
            if(this->pressed)
            {
                this->active = !this->active;
                this->pressed = false;
                if(this->active)
                    this->spr.setTextureRect(this->TextureGroup->TextureRects[TRBlogCommentButtonActive]);
                else
                    this->spr.setTextureRect(this->TextureGroup->TextureRects[TRBlogCommentButtonInActive]);
            }
        }
        break;
    case ButDialogueChoice:
        {
            if(this->active)
            {
                this->active = false;
                this->pressed = false;
                this->highLighted = false;
                this->spr.setColor(sf::Color(sf::Color(0,0,0,255)));
            }
            if(this->spr.getGlobalBounds().contains(this->gameWindowP->getMousePos()))
            {
                this->highLighted = true;
                //this->spr.setColor(sf::Color(sf::Color(0,0,0,100)));
            }
            else
            {
                this->highLighted = false;
                this->spr.setColor(sf::Color(sf::Color(0,0,0,0)));
            }


            if(this->pressed)
            {
                this->pressed = false;
                this->active = true;
            }
        }
        break;
    case ButDialogueCriticize:
        {
            if(this->active)
            {
                this->pressed = false;
                this->active = false;
                this->highLighted = false;
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueCriticizeInactive]);
            }
            if(this->highLighted)
            {
                this->active = true;
            }
            if(this->pressed)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueCriticizeActive]);
                this->highLighted = true;
                this->pressed = false;
            }
        }
        break;
    case ButDialogueSupport:
        {
            if(this->active)
            {
                this->pressed = false;
                this->active = false;
                this->highLighted = false;
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueSupportInactive]);
            }
            if(this->highLighted)
            {
                this->active = true;
            }
            if(this->pressed)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRDialogueSupportActive]);
                this->highLighted = true;
                this->pressed = false;
            }
        }
        break;
    case ButBlogPost:
        {
            if(this->active)
            {
                this->pressed = false;
                this->active = false;
                this->highLighted = false;
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRBlogPostInactive]);
            }
            if(this->highLighted)
            {
                this->active = true;
            }
            if(this->pressed)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRBlogPostActive]);
                this->highLighted = true;
                this->pressed = false;
            }
        }
        break;
    case ButNextDay:
        {
            this->spr.setPosition(this->gameWindowP->getMousePos());
            if(this->active)
            {
                this->pressed = false;
                this->active = false;
                this->highLighted = false;
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRNextDayButtonInactive]);
            }
            if(this->highLighted)
            {
                this->active = true;
            }
            if(this->pressed)
            {
                this->spr.setTextureRect(this->TextureGroup->TextureRects[TRNextDayButtonActive]);
                this->highLighted = true;
                this->pressed = false;
            }
        }

    }

}

void Button::queSprites(sf::Sprite spr)
{
    this->gameWindowP->queSprites(spr);
}

void Button::render(int layer)
{
    this->gameWindowP->queSprites(spr,layer);
}

sf::FloatRect Button::getBounds()
{
    return this->spr.getGlobalBounds();
}

bool Button::getActive()
{
    return this->active;
}

bool Button::getPressed()
{
    return this->pressed;
}

void Button::setColor(sf::Color color)
{
    this->spr.setColor(color);
}

ButtonType Button::getType()
{
    return this->type;
}

webPages Button::getWebType()
{
    return this->webType;
}
