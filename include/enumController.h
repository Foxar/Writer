#ifndef ENUMCONTROLLER_H_INCLUDED
#define ENUMCONTROLLER_H_INCLUDED

class GameWindow;
extern GameWindow* globalWindowPtr;

enum monthsEnum
{
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVERMBER = 11,
    DECEMBER = 12
};

enum webPages
{
    WPNone = 0,
    WPHome = 1,
    WPBNN = 2,
    WPBlog = 3,
    WPBlogView = 4
};
enum ButtonType
{
    BUTNone             = 0,
    BUTAppMenu          = 1,
    BUTSwitch           = 2,
    BUTAppIcon          = 3,
    BUTAppOptions       = 4,
    ButAppUtilClose     = 5,
    ButHomeLink         = 6,
    ButArticle          = 7,
    ButDialogueYes      = 8,
    ButDialogueNo       = 9,
    ButComments         = 10,
    ButDialogueChoice   = 11,
    ButDialogueSupport  = 12,
    ButDialogueCriticize= 13,
    ButBlogPost         = 14,
    ButNextDay          = 15
};

enum AppType
{
    APPCount = 3,
    APPNone = 0,
    APPBrowser = 1,
    APPEmail = 2
};

enum gameStates{
splash = 0,
mainMenu = 1,
settings = 2,
computerLoading = 3,
pauseMenu = 4,
desktop = 5,
webBrowser = 6,
nextDayScreen = 7
};

enum CursorTypes{
CURNormal = 0,
CURClick = 1
};

enum MainMenuOption
{
    MMONone = 0,
    MMOPlay = 1,
    MMOSettings = 2,
    MMOExit = 3
};

enum webSites{
homePage = 0,
news = 1,
blog = 2};

enum buttonSoundEffects
{
sfx_browserClick = 0,
sfx_count = 1
};

enum articles
{
    a_articleZero       = 0,
    a_ukEmbargo         = 1,
    a_norBorders        = 2,
    a_facebookAvatar    = 3,
    a_prisonStrike      = 4,
    a_usDemocrat        = 5,
    a_ukraineWar        = 6
};

enum dialogueBoxType
{
    d_None = 0,
    d_YesNo = 1,
    d_ThreeOpts = 2,
    d_CritSup = 3
};

enum dialogueBoxReturns
{
    dr_None = 0,
    dr_No = 1,
    dr_Yes = 2,
    dr_Criticize= 3,
    dr_Support = 4,
    dr_crit1 = 5,
    dr_crit2 = 6,
    dr_crit3 = 7
};

#endif // ENUMCONTROLLER_H_INCLUDED
