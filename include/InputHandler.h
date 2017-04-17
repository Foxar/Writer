#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SFML/Graphics.hpp>
class GameWindow;



class InputHandler
{
    public:
        InputHandler();
        InputHandler(GameWindow* windowPtr);
        void tick();

        sf::Vector2i mousePos;

    protected:

    private:
        void setGameWindowPointer(GameWindow* win);


        GameWindow *gameWindowP = 0;
};

#endif // INPUTHANDLER_H
