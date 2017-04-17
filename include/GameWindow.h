#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "enumController.h"
#include "SpriteContainer.h"
#include "SplashScreen.h"
#include "Button.h"
#include "MainMenu.h"
#include "InputHandler.h"
#include "Textures.h"
#include "ComputerLoading.h"
#include "ComputerDesktop.h"
#include "Settings.h"
#include "ContinuityManager.h"

#include <iostream>

enum Inputs
{
    InNone = 0x0,
    InMouseLeft = 0x01,
    InMouseRight = 0x02

};

class GameWindow
{
    public:
        GameWindow();
        void start();
        void queSprites(sf::Sprite, int layer = 1);
        void queShapes(sf::RectangleShape);
        void queText(sf::Text, int = 1);
        void changeState(gameStates, bool reinitialize = true);
        void setCursor(CursorTypes type);
        void close();

        //RENDER WINDOW METHODS
        void setCamera(sf::View cam);
        sf::RenderWindow *getPointer();
        bool pollEvent(sf::Event e);
        sf::IntRect getViewRect();
        sf::Vector2f getViewCenter();
        sf::Vector2f getMousePos();
        sf::Vector2u getWindowSize();
        sf::Vector2u getDefaultWindowSize();
        void setLetterBox(sf::View *camera);
        void switchFullscreen(bool fullscreen);

        void dayProgressionReset();


        sf::Texture spreadsheet;
        sf::View camera_MainMenu;
        sf::View camera_Desktop;


        ContinuityManager contMgr = ContinuityManager(this);


        unsigned char input = InNone;

        Textures TextureGroup;

        bool Fullscreen = false;
        bool InGame = false;
        ComputerDesktop Desktop;

    protected:
        void startWin();
        void tick();
        void render();
        void handleInput();
        void reinitialize();
        void run();

        void loadTextures();

    private:
        const int WIDTH = 960;
        const int HEIGHT = 540;
        const int MENU_SCALE = 4;
        const int TPS = 60;

        sf::RenderWindow win;
        sf::Clock renderClock;
        sf::Clock tickClock;
        sf::Clock splashClock;

        sf::Sprite cursor;
        sf::Texture tex_cursor;
        sf::Texture tex_curClick;

        gameStates State = mainMenu;
        SpriteContainer spriteContainer;


        SplashScreen Splash;
        MainMenu Menu;
        InputHandler Handler;
        ComputerLoading Loading;
        Settings SettingsMenu;


        sf::Event event;


};




#endif // GAMEWINDOW_H
