#ifndef CONTINUITYMANAGER_H
#define CONTINUITYMANAGER_H
#include "enumController.h"
#include "Blogpost.h"

struct Date{unsigned short int  day;
            monthsEnum          month;
            unsigned short int  year;};

struct DailyArticleGroup{articles   art1;
                         articles   art2;
                         articles   art3;};

/*At least try to keep this one in a consistent coding style, yeah? */

class ContinuityManager
{
        public:
        ContinuityManager();
        ContinuityManager(GameWindow* winPointer);
        void                    Update();
        void                    Post(Blogpost& post);
        void                    ProgressToNextDay();

        //ACCESORS
        unsigned short int      getNotoriety();
        unsigned short int      getNDay();
        unsigned int            getFollowers();
        unsigned int            getViews();
        unsigned                getBlogListSize();
        Date                    getDate();
        Blogpost*               getBlogPostP(int i = 0);
        DailyArticleGroup       getArtGroup();



        //MUTATORS
        void                    changeNotoriety(unsigned short int  a = 0);
        void                    changeFollowers(unsigned int        a = 0);



        private:
        //GAME WINDOW POINTER
        GameWindow*             gameWindowP =   0;

        void                    render();
        void                    addViews();
        void                    generateArticles();
        void                    saveGameState();
        void                    generateArticleGroup();

        bool                    checkNotoriety();


        std::vector<Blogpost>   vBlogList;

        Date                    Date=       {14,MAY,2024};                                  //DEFAULT VALUES ARE FOR DAY 1
        DailyArticleGroup       ArtGroup=   {a_facebookAvatar,a_norBorders,a_ukEmbargo};    //DEFAULT VALUES ARE FOR DAY 1

        unsigned int            nFollowers          =   1000;
        unsigned short int      nNotoriety          =   0;
        unsigned short int      nDay                =   1;
        unsigned short int      nThresholdsReached  =   0;

        const unsigned          NOTORIETY_THRESHOLD_HATE_LEVEL_1    =   100;
        const unsigned          NOTORIETY_THRESHOLD_HATE_LEVEL_2    =   200;
        const unsigned          NOTORIETY_THRESHOLD_POLICE_EMAIL_1  =   500;
        const unsigned          NOTORIETY_THRESHOLD_POLICE_EMAIL_2  =   1000;               //FINAL WARNING BEFORE BEING ARRESTED
        const unsigned          NOTORIETY_THRESHOLD_ARREST          =   2000;
        const unsigned          NOTORIETY_THRESHOLD_DAY_X           =   1500;


};

#endif // CONTINUITYMANAGER_H
