#include "ContinuityManager.h"
#include "GameWindow.h"

ContinuityManager::ContinuityManager()
{

}

ContinuityManager::ContinuityManager(GameWindow* winPointer)
{
    this->gameWindowP = winPointer;
    this->generateArticleGroup();
}
void ContinuityManager::Post(Blogpost& post)
{
    this->vBlogList.push_back(post);
    //GENERATE NOTORIETY BASED ON THE BLOGPOST BASE NOTORIETY AND THE BLOGS POPULARITY
    //BLOG OVERALL NOTORIETY += POST NOTORIETY * (NUMBER OF FOLLOWERS / 2)

    this->nNotoriety += this->vBlogList.back().nBlogPostNotoriety * (this->nFollowers/2);
    this->nFollowers += this->vBlogList.back().nBlogPostFollowers;

    this->gameWindowP->Desktop.dailyPostDone = true;
}

//ACCESORS
unsigned short int ContinuityManager::getNDay()
{
    return this->nDay;
}
unsigned ContinuityManager::getBlogListSize()
{
    return this->vBlogList.size();
}
Blogpost* ContinuityManager::getBlogPostP(int i)
{
    return &this->vBlogList[i];
}
DailyArticleGroup ContinuityManager::getArtGroup()
{
    return this->ArtGroup;
}
Date ContinuityManager::getDate()
{
    return this->Date;
}
unsigned int ContinuityManager::getFollowers()
{
    return this->nFollowers;
}
unsigned short int ContinuityManager::getNotoriety()
{
    return this->nNotoriety;
}

//MUTATORS
void ContinuityManager::changeNotoriety(unsigned short int a)
{
    this->nNotoriety+=a;
}
void ContinuityManager::changeFollowers(unsigned int a)
{
    this->nFollowers+=a;
}

//PRIVATE

void ContinuityManager::saveGameState()
{

}

bool ContinuityManager::checkNotoriety()
{
    /*  Generates emails and/or hate comments if corresponding notoriety thresholds have been
        reached and a game over if NOTORIETY_THRESHOLD_ARREST has been reached.                 */

            if(this->nNotoriety > NOTORIETY_THRESHOLD_HATE_LEVEL_1)
    {
        //GENERATE LEVEL 1 HATE COMMENT.

    }
    else    if(this->nNotoriety > NOTORIETY_THRESHOLD_HATE_LEVEL_2)
    {
        //GENERATE LEVEL 2 HATE COMMENT.

    }
    else    if(this->nNotoriety > NOTORIETY_THRESHOLD_POLICE_EMAIL_1)
    {
        //GENERATE FIRST POLICE WARNING EMAIL


    }
    else    if(this->nNotoriety > NOTORIETY_THRESHOLD_POLICE_EMAIL_2)
    {
        //GENERATE SECOND POLICE WARNING EMAIL

    }
    else    if(this->nNotoriety > NOTORIETY_THRESHOLD_ARREST)
    {
        std::cout << "GAME OVER" << std::endl;
        std::cin.ignore();
        this->gameWindowP->close();
        //GAME OVER
    }
    else
        return false;
}

void ContinuityManager::generateArticleGroup()
{
    switch(this->nDay)
    {
    case 1:
        {
            this->ArtGroup.art1 = a_facebookAvatar;
            this->ArtGroup.art2 = a_ukEmbargo;
            this->ArtGroup.art3 = a_norBorders;
        }
        break;
    case 2:
        {
            this->ArtGroup.art1 = a_prisonStrike;
            this->ArtGroup.art2 = a_usDemocrat;
            this->ArtGroup.art3 = a_ukraineWar;
        }
        break;
    default:
        std::cout << "CONTINUITYMANAGER::GENERATEARTICLEGROUP() DEFAULT CASE." << std::endl;
        std::cin.ignore();
        break;
    }

}


void ContinuityManager::ProgressToNextDay()
{
    /*  Progressing to next day should reset most values, generate articles appropriate to the day
        player is on, checking if he reached the notoriety edge and if so trigger the fail state.   */

    std::cout << "CONT MANAGER: PROGRESSING TO NEXT DAY" << std::endl;

    //PROGRESS DAY AND CHANGE THE DATE
    this->nDay++;
    this->Date.day++;
    if(this->Date.day > 30)
    {
        this->Date.month = static_cast<monthsEnum>(this->Date.month + 1);
        this->Date.day = 1;
    }

    //NOTORIETY COOLDOWN
    if(this->nNotoriety < 50)
        this->nNotoriety = 0;
    else
        this->nNotoriety-=50;

    this->gameWindowP->dayProgressionReset();

    if(this->checkNotoriety())
        return;

    this->saveGameState();          //IF GAME HAS NOT BEEN FAILED, SAVE THE GAME



    this->generateArticleGroup();   //GENERATE TODAY'S ARTICLES

    this->gameWindowP->changeState(nextDayScreen);   //START A "DAY #, DD.MM.YYYY" SCREEN

}
