#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <SFML/Graphics.hpp>

class GameWindow;

class SplashScreen
{
    public:
        SplashScreen();
        SplashScreen(GameWindow* windowPtr);
        void update();
        void setGameWindowPointer(GameWindow* window);
    private:
        sf::Sprite spr;

        bool opening;
        GameWindow *gameWindowP = 0;

};

#endif // SPLASHSCREEN_H
