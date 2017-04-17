#ifndef ARTICLE_H
#define ARTICLE_H
#include <SFML/Graphics.hpp>
#include "enumController.h"

class GameWindow;
class ComputerDesktop;
class Textures;



class Article
{
    public:
        Article();
        Article(GameWindow* gameWindowP, ComputerDesktop* desktopP, int x, int y, articles type);
        void render();
        void update();
        void queText(sf::Text);

        articles getType();

        std::string bc_title="Critical Title";
        std::string bc_para1="Paragraph1";
        std::string bc_para2_1="Paragraph2 Opt1";
        std::string bc_para2_2="Paragraph2 Opt2";
        std::string bc_para2_3="Paragraph2 Opt3";
        std::string bc_para2_1_name="Opt1";
        std::string bc_para2_2_name="Opt2";
        std::string bc_para2_3_name="Opt3";
        std::string bc_para3="Pargraph3";

        std::string bs_title="Supporting Title";
        std::string bs_para1="Paragraph1";
        std::string bs_para2="Paragraph2";
        std::string bs_para3="Paragraph3";

        float       nOptionNotoriety[3]={0,0,0};
        float       nOptionPopularity[3]={0,0,0};

        float       nSupportNotoriety   = 0;
        float       nSupportPopularity  = 0;


        sf::Vector2f getPosition();

    private:
        GameWindow* gameWindowP = 0;
        ComputerDesktop* computerDesktopP = 0;
        Textures* TextureGroupP = 0;

        std::string title;
        std::string body;

        sf::Text titleTxt;
        sf::Text bodyTxt;



        articles type;


};

#endif // ARTICLE_H
