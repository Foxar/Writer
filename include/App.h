#ifndef APP_H
#define APP_H
#include <SFML/Graphics.hpp>
#include "Button.h"

class GameWindow;
class Textures;

class App
{
    public:
        App(GameWindow *gameWindowP);
        virtual ~App();
        virtual void update();
        virtual void render();
        virtual sf::FloatRect getBounds();
        bool isSetToClose();
        AppType getType();

        //DERIVATIVE FUNCTIONS' VIRTUAL DECLARATIONS
        virtual sf::Vector2i getWebPageOffset()=0;

    protected:
        sf::Sprite windowSpr;
        void queSprites(sf::Sprite spr);
        GameWindow *gameWindowP = 0;
        Textures *TextureGroup = 0;
        AppType type;
        bool toClose = false;

    private:


};

#endif // APP_H
