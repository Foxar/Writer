#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "enumController.h"

class Textures;
class GameWindow;
class App_WebBrowser;

const int BUTTON_COOLDOWN_MS = 100;



class Button
{
    public:
        Button(GameWindow *gameWindowP, int x, int y, ButtonType type, AppType appType=APPNone, webPages webPage=WPNone, int articlePicked = 0);
        //Button(GameWindow *gameWindowP, int x, int y, ButtonType type);
        Button();
        void Click();
        void update(App_WebBrowser* parentBrowser = 0);
        void render(int layer = 1);
        bool getActive();
        bool getPressed();
        ButtonType getType();
        void setActive(bool active);
        sf::FloatRect getBounds();
        int articleAssigned = 0; //FOR USE WITH BUTARTICLE BUTTONS ONLY
        void setColor(sf::Color color);
        webPages getWebType();
    private:
        sf::Sprite spr;
        AppType appType = APPNone;
        webPages webType = WPNone;
        bool active = false;
        bool pressed = false;
        bool highLighted = false;



        void queSprites(sf::Sprite spr);

        GameWindow *gameWindowP = 0;
        Textures *TextureGroup = 0;

        sf::Clock Cooldown;

        ButtonType type = BUTNone;
};

#endif // BUTTON_H
