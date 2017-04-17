#ifndef APPMENU_H
#define APPMENU_H
#include <SFML/Graphics.hpp>
#include "Button.h"

class Button;
class App;
class GameWindow;
class Textures;
class MainMenu;
class ComputerDesktop;

class AppMenu
{
    public:
        AppMenu();
        AppMenu(GameWindow *win, ComputerDesktop *desk);
        void update();
        void render();
        bool getActive();
        void setActive(bool active);
        App *tempApp = 0;
    private:
        void queSprites(sf::Sprite spr);
        bool active;

        sf::Sprite spr;

        Button APPBrowserIcon;
        Button APPEmailIcon;
        Button APPOptionsIcon;

        GameWindow *gameWindowP = 0;
        Textures *TextureGroup = 0;
        ComputerDesktop *desktopP = 0;


};

#endif // APPMENU_H
