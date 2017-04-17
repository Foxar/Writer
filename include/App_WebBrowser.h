#ifndef APP_WEBBROWSER_H
#define APP_WEBBROWSER_H
#include "App.h"



class Website;
class Article;
class Blogpost;

class App_WebBrowser: public App
{
    public:
        App_WebBrowser(GameWindow *gameWindowP);
        ~App_WebBrowser();
        void render();
        void update();
        void changeWebsite(webPages websiteToChangeTo);
        sf::Vector2i getWebPageOffset();
        sf::Vector2i getURLOffset();
        Website* websiteP = 0;
        Article *currentArticleP = 0;
        Blogpost* postP = 0;
    private:
        //webPages openPage = WPHome;

        const webPages defaultWebsite = WPHome;

        Button exitButton;
        sf::Sprite urlSprite;
        sf::Vector2i webPageOffset = sf::Vector2i(0,48);
        sf::Vector2i URLOffset = sf::Vector2i(35,11);

        bool websiteChangeFlag = false;




        void checkURL();
};

#endif // APP_WEBBROWSER_H
