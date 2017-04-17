#include "InputHandler.h"
#include "GameWindow.h"

InputHandler::InputHandler()
{

}

InputHandler::InputHandler(GameWindow* windowPtr)
{
    this->setGameWindowPointer(windowPtr);
}

void InputHandler::tick()
{

}


void InputHandler::setGameWindowPointer(GameWindow* window)
{
    this->gameWindowP = window;
}
