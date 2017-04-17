#ifndef DIALOGUEBOX_H
#define DIALOGUEBOX_H

#include "Button.h"

class GameWindow;
class Textures;
class Website;


class DialogueBox
{
    public:
        DialogueBox();
        DialogueBox(GameWindow* gamewindowP, Textures* texturesP, Website* websiteP, int x, int y, dialogueBoxType type);
        virtual ~DialogueBox();

        void update();
        void render();
        sf::FloatRect getBounds();

        dialogueBoxReturns getReturn();

        bool setToDelete = false;
    private:
        sf::Sprite spr;

        std::vector<sf::Text>labels;

        Button opt1;
        Button opt2;
        Button opt3;

        std::string opt1Name;
        std::string opt2Name;
        std::string opt3Name;


        Textures* TextureGroup = 0;
        GameWindow* gameWindowP = 0;
        App_WebBrowser* browserP = 0;
        Website* websiteP = 0;

        dialogueBoxType type = d_None;
        dialogueBoxReturns Return = dr_None;

};

#endif // DIALOGUEBOX_H
