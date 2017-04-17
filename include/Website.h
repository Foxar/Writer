#ifndef WEBSITE_H
#define WEBSITE_H
#include "App_WebBrowser.h"
#include "Button.h"
#include "Article.h"
#include "Blogpost.h"
#include "ContinuityManager.h"

enum WebsiteFlags
{
    WFNone = 0x0,
    WFCriticize = 0x1,
    WFSupport = 0x2,
    WFCrit1 = 0x4,
    WFCrit2 = 0x8,
    WFCrit3 = 0x10,
    WFPostReady = 0x20
};


class GameWindow;
class App_WebBrowser;
class ComputerDesktop;
class Textures;
class Website;
class Article;

class CommentBox
{
    public:
        void update();
        void render();


        CommentBox(Website* websiteP, GameWindow* gamewindowP);


        sf::Text comment1;
        sf::Text comment2;
        sf::Text comment3;

        Website* websiteP = 0;
        Textures* textureP = 0;
        GameWindow* gamewindowP = 0;

        float xSpeed = 0;
        float speed = 0;
        bool deployed = false;
        bool buttonDown = false;


    private:
        sf::Sprite spr_commentBox;
};

class Website
{
    public:
        Website();
        Website(GameWindow* gameWindowP, App_WebBrowser* parentApp, webPages type);
        ~Website();
        void render();
        void update();
        webPages getPageType();
        std::vector<Button>buttonList;
        void checkDialogueBoxes();
        App_WebBrowser* getBrowserP();

        sf::FloatRect getBounds();

        unsigned char blogFlags = WFNone;

        Article* currentArticle = 0;

        void generateBlogPost();

        bool setToDelete = false;

    protected:

    private:
    void setArticles();
    void queSprites(sf::Sprite spr);

    void generateComments();

    webPages pageType = WPHome;
    sf::Sprite spr;

    std::vector<CommentBox>commentList; //THERE SHOULDNT BE MORE THAN ONE COMMENTBOXES. A VECTOR IS USED FOR THE EVENTUALITY A WEBSITE DOES NOT HAVE ANY COMMENT BOXES

    //PARENT POINTERS
    GameWindow* gameWindowP = 0;
    App_WebBrowser* browserP = 0;
    ComputerDesktop* desktopP = 0;
    Textures *textureP = 0;

    //MEMBER POINTERS
    Article* article1 = 0;
    Article* article2 = 0;
    Article* article3 = 0;
};

#endif // WEBSITE_H
