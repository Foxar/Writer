#ifndef TEXTURES_H
#define TEXTURES_H
#include <SFML/Graphics.hpp>

enum TexRects
{
    TRNone                      = 0,
    TRCount                     = 29,
    TRAppMenuInactive           = 1,
    TRAppMenuActive             = 2,
    TRSwitchOn                  = 3,
    TRSwitchOff                 = 4,
    TRAppWebBrowserInActive     = 5,
    TRAppWebBrowserActive       = 6,
    TRAppOptionsInactive        = 7,
    TRAppOptionsActive          = 8,
    TRHomeBNNInActive           = 9,
    TRHomeBNNActive             = 10,
    TRHomeBlogInActive          = 11,
    TRHomeBlogActive            = 12,
    TRDialogueYesInactive       = 13,
    TRDialogueYesActive         = 14,
    TRDialogueNoInactive        = 15,
    TRDialogueNoActive          = 16,
    TRBlogCommentButtonInActive = 17,
    TRBlogCommentButtonActive   = 18,
    TRAppEmailInActive          = 19,
    TRAppEmailActive            = 20,
    TRDialogueSupportInactive   = 21,
    TRDialogueSupportActive     = 22,
    TRDialogueCriticizeInactive = 23,
    TRDialogueCriticizeActive   = 24,
    TRBlogPostInactive          = 25,
    TRBlogPostActive            = 26,
    TRNextDayButtonInactive     = 27,
    TRNextDayButtonActive       = 28

};

class Textures
{
    public:
        Textures();
        void loadTextures();

        //SPLASH

        sf::Texture splash_Screen;

        //MAIN MENU

        sf::Texture menu_Play;
        sf::Texture menu_Resume;
        sf::Texture menu_Exit;
        sf::Texture menu_Settings;
        sf::Texture menu_Title;

        //DESKTOP

        sf::Texture computer_Desktop;
        sf::Texture app_Menu_Button;

        //APP MENU
        sf::Texture app_Menu;
        sf::Texture texIconWeb;
        sf::Texture texIconEmail;
        sf::Texture texIconOpt;

        //SETTINGS
        sf::Texture settings_switch;
        sf::Texture label_fullscreen;

        //APPS MAIN WINDOWS

        sf::Texture app_WebBrowser;
        sf::Texture app_Email;

        //MISC BUTTONS
        sf::Texture tex_butt_exit;
        sf::Texture tex_butt_nextDay;

        //DIALOGUE BOX
        sf::Texture tex_dialogueBoxArticleChoice;
        sf::Texture tex_dialogueBoxItemChoice;
        sf::Texture tex_dialogueBoxCritSup;

        //DIALOGUE BOX OPTIONS
        sf::Texture tex_yesNo;
        sf::Texture tex_critSup;

        //URLS
        sf::Texture tex_URL_BNN;
        sf::Texture tex_URL_blog;
        sf::Texture tex_URL_homePage;

        //HOMEPAGE BUTTONS
        sf::Texture tex_home_buttons;

        //WEBPAGE ITEMS
        sf::Texture tex_webItem_comments;

        //WEBPAGE BUTTONS
        sf::Texture tex_But_comments;
        sf::Texture tex_but_post;

        //WEBSITES

        sf::Texture tex_web_BNN;
        sf::Texture tex_web_Homepage;
        sf::Texture tex_web_Blog;
        sf::Texture tex_web_ViewBlog;

        //FONTS

        sf::Font articleFont;

        //TEXTURE RECTS
        std::vector<sf::IntRect>TextureRects;
};

#endif // TEXTURES_H
