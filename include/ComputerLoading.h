#ifndef COMPUTERLOADING_H
#define COMPUTERLOADING_H

class GameWindow;

class ComputerLoading
{
    public:
        ComputerLoading();
        ComputerLoading(GameWindow *gameWindowP);
        void update();

    private:
        GameWindow *gameWindowP = 0;
};

#endif // COMPUTERLOADING_H
