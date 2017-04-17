#ifndef BLOGPOST_H
#define BLOGPOST_H
#include "App_WebBrowser.h"
#include "Button.h"
#include "Article.h"

class GameWindow;
class App_WebBrowser;
class ComputerDesktop;
class Textures;
class Website;
class Article;

class Blogpost
{
    public:
        Blogpost(GameWindow* gameWindowP, Website* websiteP, ComputerDesktop* desktopP, Article* articleP);


        Website* websiteP = 0;
        GameWindow* gameWindowP = 0;
        ComputerDesktop* desktopP = 0;
        Article* articleP = 0;

        int currentParagraph = 1;
        bool complete = false;

        float nBlogPostNotoriety = 0;
        float nBlogPostFollowers = 0;

        void update();
        void render();


    private:

        void typeText(sf::Text* txt, std::string* str);

        std::string str_title;
        std::string str_p1;
        std::string str_p2;
        std::string str_p3;

        sf::Text Title;
        sf::Text p1;
        sf::Text p2;
        sf::Text p3;
};

#endif // BLOGPOST_H
