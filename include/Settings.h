#ifndef SETTINGS_H
#define SETTINGS_H
#include "Button.h"

class GameWindow;
class Textures;

class Settings
{
    public:
        Settings();
        Settings(GameWindow* GameWindow);
        void update();
    private:
        void render();
        void queSprites(sf::Sprite spr);
        void queShapes(sf::RectangleShape shape);
        void chooseSelectorPosition(sf::FloatRect target);

        Button fullscreenSwitchButton;

        sf::Sprite label_fullscreen;

        sf::Sprite ExitText;
        sf::RectangleShape Selector;

        GameWindow *gameWindowP = 0;
        Textures *TextureGroup = 0;


};

#endif // SETTINGS_H
