#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>
#include "enumController.h"

class GameWindow;


class MainMenu
{
    public:
        MainMenu();
        MainMenu(GameWindow* windowPtr);
        void update();

        sf::Sprite PlayText;
        sf::Sprite SettingsText;
        sf::Sprite ExitText;
        sf::Sprite TitleSpr;

    protected:
    private:
        void queSprites(sf::Sprite);
        void render();
        void chooseSelectorPosition(sf::FloatRect target);

        sf::RectangleShape Selector;
        GameWindow *gameWindowP = 0;

        MainMenuOption Selected = MMONone;
};

#endif // MAINMENU_H
