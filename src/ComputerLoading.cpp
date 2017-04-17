#include "ComputerLoading.h"
#include "GameWindow.h"
#include "Button.h"

ComputerLoading::ComputerLoading()
{

}

ComputerLoading::ComputerLoading(GameWindow *gameWindowP)
{
    this->gameWindowP = gameWindowP;
}

void ComputerLoading::update()
{
    this->gameWindowP->changeState(desktop);
}
