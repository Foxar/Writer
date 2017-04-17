#ifndef COMPUTERDESKTOP_H
#define COMPUTERDESKTOP_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "App.h"
#include "AppMenu.h"
#include "DialogueBox.h"
#include "Article.h"

class GameWindow;
class Textures;
class Article;

//class Button;
//class App;

class ComputerDesktop
{
    public:
        ComputerDesktop();
        ComputerDesktop(GameWindow *gameWindowP);
        void update();
        sf::FloatRect getAppButtonBounds();
        App *activeApp = 0;
        Button appMenuButton;
        Button nextDayButton;

        bool dailyPostDone = false;

        unsigned getDialogueListSize();

        std::vector<Article>articleChosen; //ONLY SIZE IS SUPPSOED TO BE ONE.
        std::vector<unsigned>criticalPointsChosen;

        AppMenu appMenu;

        void spawnDialogueBox(dialogueBoxType type, Website* websiteP);

        std::vector<DialogueBox>dialogueList;
    private:
        void render();
        void queSprites(sf::Sprite spr);
        void checkDesktopButtonPressed();

        sf::Sprite desktop;

        GameWindow *gameWindowP = 0;
        Textures *TextureGroup = 0;

};

#endif // COMPUTERDESKTOP_H
