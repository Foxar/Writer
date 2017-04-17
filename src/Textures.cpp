#include "Textures.h"

Textures::Textures()
{
    this->loadTextures();
}


void Textures::loadTextures()
{
    for(unsigned i = 0; i < TRCount; i++)
    {
        this->TextureRects.push_back(sf::IntRect(0,0,0,0));
    }
    this->menu_Play.loadFromFile("res//menu//play.png");
    this->menu_Exit.loadFromFile("res//menu//exit.png");
    this->menu_Settings.loadFromFile("res//menu//settings.png");
    this->menu_Title.loadFromFile("res//menu//title.png");

    this->splash_Screen.loadFromFile("res//largeSize//splash.png");

    this->computer_Desktop.loadFromFile("res//largeSize//desktop.png");

    this->app_Menu_Button.loadFromFile("res//buttons//applicationMenuButton.png");

    this->settings_switch.loadFromFile("res//buttons//settingsMenuOnOffButton.png");

    this->menu_Resume.loadFromFile("res//menu//resume.png");

    this->label_fullscreen.loadFromFile("res//menu//fullscreen.png");

    this->app_Menu.loadFromFile("res//largeSize//applicationMenu.png");

    this->texIconWeb.loadFromFile("res//buttons/webBrowserMenu.png");

    this->texIconOpt.loadFromFile("res//buttons//optionsMenu.png");

    this->app_WebBrowser.loadFromFile("res//largeSize//browser.png");

    this->tex_butt_exit.loadFromFile("res//buttons//webBrowserExit.png");

    this->tex_web_Homepage.loadFromFile("res//largeSize//homepage.png");

    this->tex_web_BNN.loadFromFile("res//largeSize//BNN.png");

    this->tex_URL_BNN.loadFromFile("res//smallSize//url//url_BNN.png");

    this->tex_URL_blog.loadFromFile("res//smallSize//url//url_blog.png");

    this->tex_URL_homePage.loadFromFile("res//smallSize//url//url_homepage.png");

    this->tex_home_buttons.loadFromFile("res//buttons//homeButtons.png");

    this->tex_web_Blog.loadFromFile("res//largeSize//blogPage.png");

    this->tex_dialogueBoxArticleChoice.loadFromFile("res//smallSize//dialogueBox//articleChoice.png");

    this->tex_yesNo.loadFromFile("res//buttons//yesNo.png");

    this->tex_webItem_comments.loadFromFile("res//smallSize//commentBox//commentBox.png");

    this->tex_But_comments.loadFromFile("res//buttons/commentsShow.png");

    this->texIconEmail.loadFromFile("res//buttons//emailMenu.png");

    this->tex_dialogueBoxItemChoice.loadFromFile("res//smallSize//dialogueBox//itemChoice.png");

    this->tex_dialogueBoxCritSup.loadFromFile("res//smallSize//dialogueBox//criticiseSupport.png");

    this->tex_critSup.loadFromFile("res//buttons//critsup.png");

    this->tex_but_post.loadFromFile("res//buttons//postButton.png");

    this->tex_web_ViewBlog.loadFromFile("res//largeSize//blogViewPage.png");

    this->tex_butt_nextDay.loadFromFile("res//buttons/nextDayButton.png");

    this->tex_dialogueBoxArticleChoice.setSmooth(false);



    this->articleFont.loadFromFile("res//fonts//visitor1.ttf");



    this->TextureRects[TRAppMenuInactive] = sf::IntRect(57,0,57,38);
    this->TextureRects[TRAppMenuActive] = sf::IntRect(0,0,57,38);

    this->TextureRects[TRSwitchOff] = sf::IntRect(0,0,29,22);
    this->TextureRects[TRSwitchOn] = sf::IntRect(29,0,29,22);

    this->TextureRects[TRAppWebBrowserInActive] = sf::IntRect(250,0,250,61);
    this->TextureRects[TRAppWebBrowserActive] = sf::IntRect(0,0,250,61);

    this->TextureRects[TRAppEmailInActive] = sf::IntRect(250,0,250,61);
    this->TextureRects[TRAppEmailActive] = sf::IntRect(0,0,250,61);

    this->TextureRects[TRAppOptionsInactive] = sf::IntRect(250,0,250,61);
    this->TextureRects[TRAppOptionsActive] = sf::IntRect(0,0,250,61);

    this->TextureRects[TRHomeBNNInActive] = sf::IntRect(0,0,182,182);
    this->TextureRects[TRHomeBNNActive] = sf::IntRect(182,0,182,182);

    this->TextureRects[TRHomeBlogInActive] = sf::IntRect(0,182,182,182);
    this->TextureRects[TRHomeBlogActive] = sf::IntRect(182,0,182,182);

    this->TextureRects[TRDialogueYesInactive] = sf::IntRect(0,0,50,24);
    this->TextureRects[TRDialogueYesActive] = sf::IntRect(0,24,50,24);


    this->TextureRects[TRDialogueNoInactive] = sf::IntRect(50,0,50,24);
    this->TextureRects[TRDialogueNoActive] = sf::IntRect(50,24,50,24);

    this->TextureRects[TRBlogCommentButtonInActive] = sf::IntRect(0,0,55,30);
    this->TextureRects[TRBlogCommentButtonActive] = sf::IntRect(55,0,55,30);

    this->TextureRects[TRDialogueCriticizeInactive] = sf::IntRect(0,0,90,24);
    this->TextureRects[TRDialogueCriticizeActive] = sf::IntRect(0,24,90,24);

    this->TextureRects[TRDialogueSupportInactive] = sf::IntRect(90,0,90,24);
    this->TextureRects[TRDialogueSupportActive] = sf::IntRect(90,24,90,24);

    this->TextureRects[TRBlogPostInactive] = sf::IntRect(0,0,67,24);
    this->TextureRects[TRBlogPostActive] = sf::IntRect(67,0,67,24);

    this->TextureRects[TRNextDayButtonInactive] = sf::IntRect(0,0,67,24);
    this->TextureRects[TRNextDayButtonActive] = sf::IntRect(67,0,67,24);

}
