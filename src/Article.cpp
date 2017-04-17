#include "Article.h"
#include "GameWindow.h"
#include "ComputerDesktop.h"
#include "Textures.h"

Article::Article()
{

}

Article::Article(GameWindow* gameWindowP, ComputerDesktop* desktopP, int x, int y, articles type)
{
    this->type = type;
    this->gameWindowP = gameWindowP;
    this->computerDesktopP = desktopP;
    this->TextureGroupP = &this->gameWindowP->TextureGroup;

    switch(this->type)
    {
        //TEMPLATE:
        //
        //this->title = "";
        //this->body = "";
        //
        //this->bc_title = "";
        //this->bc_para1 = "";
        //this->bc_para2_1 = "";
        //this->bc_para2_2 = "";
        //this->bc_para2_3 = "";
        //this->bc_para3 = "";
        //
        //this->bc_para2_1_name = "";
        //this->bc_para2_2_name = "";
        //this->bc_para2_3_name = "";
        //
        //
        //
        //this->bs_title = "";
        //this->bs_para1 = "";
        //this->bs_para2 = "";
        //this->bs_para3 = "";
        case a_ukEmbargo:
            {
                this->title = "Embargo lifted?";
                this->body = "Talks have been held between UK and EU officials with\nthe long-term goal of ending the mutual embargo\nput in place in 2017 when the UK seceded from the Union.\nExpectations are that the Netherlands might\nalso join the talks.";

                this->bc_title = "Title";
                this->bc_para1 = "I think there is more to this story then the media is letting on. Ever since the secession relations with the UK has been chilly and it was worsened further after the intervention in the eastern states a few years ago.";
                this->bc_para2_1 = "I am speculating that this has something to do with the United States election due later this year. Britain always cared more about their overseas allies then their European ones and with most of the commonwealth nations aligning themselves more towards Europe and Democrat candidate Kenneth Miller almost guaranteed to win presidency it's not hard to see where the pressure is coming from.";
                this->bc_para2_2 = "It may sound harsh but I seriously hope that negotiations break down on this. Britain aligning itself towards Europe again would be a terrible disaster for France, being the only country actively keeping Europe at bay. Britain is needed on their side of the sea, not reintegrated into the Union.";
                this->bc_para2_3 = "I am guessing we will see the political climate heat up in the following days as France gets involved in trying to keep the brits on their side. Trade relations with Britain could lead to a massive economic boost in Europe, something France rightly fear. If things turn really sour, we could see intervention in the near future.";
                this->bc_para3 = "In the end there is not much I can do from my little blog, but I have to say that for the stability of the continent this must not pass.";

                this->bc_para2_1_name = "Speculation";
                this->bc_para2_2_name = "Don't lift embargo";
                this->bc_para2_3_name = "There will be consequences";

                this->nOptionNotoriety[0]   =   -2;
                this->nOptionNotoriety[1]   =   -4;
                this->nOptionNotoriety[2]   =   -3;

                this->nOptionPopularity[0]  =   -4;
                this->nOptionPopularity[1]  =   -4;
                this->nOptionPopularity[2]  =   -3;



                this->bs_title = "Title support";
                this->bs_para1 = "I think this is a great move by the british leaders to once again encourage trust and cooperation across Europe, something that has been lacking severely the last couple of years.";
                this->bs_para2 = "It is unlikely that France will like this move but I fully support it. Tensions in Europe have been high ever since the intervention in the eastern states and France's secession, so things may calm down a bit now if not in France, then at least in Britain.";
                this->bs_para3 = "Negotiations are not over yet, but I hope that together with the Netherlands and our allies abroad this might turn out very well for all parties involved.";

                this->nSupportNotoriety     = 2;
                this->nSupportPopularity    = 2;

            }
            break;
        case a_norBorders:
            {
                this->title = "Norway opens its borders!";
                this->body = "Earlier this morning Norway passed an amendment to their\nimmigration law allowing for more leniency toward\nEuropean nationals. Norway has continues to be a\npopular refuge for right wing extremist groups.";

                this->bc_title = "Norwegian haven.";
                this->bc_para1 = "I don't think anyone is fooled by Norway's act. It is clear that they are once again opening their borders to the Scandinavian far-right movements.";
                this->bc_para2_1 = "It is quite clear what Norway is doing with this move. Ever since the negotiations for extradition of several criminals belonging to extremist groups failed Norway has tried to build closer relationships to France and Britain who have made it a point to act concerned over these groups.";
                this->bc_para2_2 = "Norway is obviously trying to create a safe haven for the right wing extremist groups that has plagued our country in recent years. Police have been hard at work cracking down on white supremacy and fascist groups but I'd wager that moves like these will result in them flaring up again.";
                this->bc_para2_3 = "I say we should look to increase our border security and deny these people any platform to spread their hate, either domestic or abroad. I believe that the Swedish and Finnish police forces should be more then enough to accomplish this.";
                this->bc_para3 = "That would summarise my thoughts on the matter. I really think the parliament should deal harsher with these issues going forward.";

                this->bc_para2_1_name = "Criticise norway.";
                this->bc_para2_2_name = "Criticise emigrants.";
                this->bc_para2_3_name = "Criticise borders";

                this->nOptionNotoriety[0]   =   -1;
                this->nOptionNotoriety[1]   =   -2;
                this->nOptionNotoriety[2]   =   -2;

                this->nOptionPopularity[0]  =   -2;
                this->nOptionPopularity[1]  =   -3;
                this->nOptionPopularity[2]  =   -2;


                this->bs_title = "Norwegian heaven.";
                this->bs_para1 = "I think that it's great to see Norway being so open-minded. Who can forget that last time this happened they were flooded by political refugees and were so overwhelmed that they had to close the border.";
                this->bs_para2 = "Norway has always been a popular refuge for the Nordic free thinkers since, unlike our Union, Norway never passed laws that practically bans political subjects to be openly discussed. Furthermore\nthis seems to be aligning Norway more towards Britain and France.";
                this->bs_para3 = "I seriously hope that this will result in more people crossing the border, proving to our leaders that their opressive policies are unfeasible!";

                this->nSupportNotoriety     = 3;
                this->nSupportPopularity    = 4;
            }
        break;
        case a_facebookAvatar:
            {
                this->title = "Show solidarity with share.me!";
                this->body = "Social media site Share.me introduced a feature where users\ncould add an Italian flag over their avatar as a gesture of\nsolidarity over the terror attack in Rome last week\nthat claimed 10 lives.";

                this->bc_title = "No, a flag overlay won't stop terrorism.";
                this->bc_para1 = "This is a perfect example of slacktivism. You've got a multi-million dollar company acting all concerned to win internet cookie-points. This is nothing but a token effort.";
                this->bc_para2_1 = "Let's be real here, what does changing a social media avatar really do? Nothing! It will not bring the victims back to life, it will not console the families of the victims and it will not prevent new attacks to happen in the future. It is, frankly, disgusting to see people inflating their ego and pretending to occupy a moral high ground because they switched their Share avatar.";
                this->bc_para2_2 = "And why would BNN ever write an article about this? People died in this incident and it's frankly insulting to the victims and their families to turn this tragedy into publicity for a social media platform? Please BNN, for the future, write substance over quantity.";
                this->bc_para2_3 = "It's absolutely terrifying to see this social media platform turning this tragedy into publicity. I'd suggest to Share that they stop with the pretense and actually do something of value. How about you stop with the censorship on your platform and actually start allowing discussions on this subject again.";
                this->bc_para3 = "All in all, those are my concerns with this move by Share.me. I know this is quite a minor thing to rant about but I really can't stand this kind hypocrisy.";

                this->bc_para2_1_name = "It's pointless.";
                this->bc_para2_2_name = "It's not newsworthy.";
                this->bc_para2_3_name = "Criticize social media.";

                this->nOptionNotoriety[0]   =   1;
                this->nOptionNotoriety[1]   =   1;
                this->nOptionNotoriety[2]   =   1;

                this->nOptionPopularity[0]  =   2;
                this->nOptionPopularity[1]  =   3;
                this->nOptionPopularity[2]  =   2;

                this->bs_title = "This is great!";
                this->bs_para1 = "I'd say this is a wonderful move by Share.me to bring attention to this terrifying tragedy. It really reminds us that we are all vulnerable to this kind of terror but that we still have each other behind us. Truly a strong message for solidarity.";
                this->bs_para2 = "I'm mostly blogging about this to get the word out to all of my followers with Share-accounts. No matter if you lean to the left or right this event was horrifying and we should show our support to the victims and their families, but for most of us it's is difficult so hopefully this small token of support will count for at least something.";
                this->bs_para3 = "Now, let's do our best to avoid the same tragedy in the future.";

                this->nSupportNotoriety     =   -1;
                this->nSupportPopularity    =   -2;
            }
        break;
        case a_prisonStrike:
            {
                this->title = "Prisoners on a hunger strike.";
                this->body = "Right wing extremists held in German prisons today\ndecided to go on a hunger strike, citing \"inhumane\"\nconditions.";

                this->bc_title = "Criticise title";
                this->bc_para1 = "I support the hunger strikers in their resolve. The German prisons are a human rights disaster.";
                this->bc_para2_1 = "Most of the prisons these people are contained in were hastily built a few years ago in response to the European Freedom of Expression Directive of 2018 and the massive crackdown on percieved hate speech following it. Since then the prisons have been undermanned and underfunded, all in all in terrible condition, and human rights organisations won't bat an eye.";
                this->bc_para2_2 = "And face it, these people don't even belong in jail. Most of them are just like us, ordinary people, and I'd wager the vast majority of them aren't even holding radical beliefs at all. The Freedom of Expression Directive of 2018 expanded the scope of \"hate speech\" to such an extent that even ordinary people with only slightly unorthodox opinions were put under arrest.";
                this->bc_para2_3 = "I'd say that most of the prisoners demands are perfectly reasonable. Just something like regular meals daily and not being harassed by the guards daily are fair complaints to have. This entire project has been a disaster and the German government and, by extention, the European government would be fools to not at least negotiate with thw prisoners.";
                this->bc_para3 = "I do realise that by airing these opinions I am running the risk of too ending up in these jails, but such is the risk of keeping the public informed about what is really going on.";

                this->bc_para2_1_name = "Criticise jail conditions";
                this->bc_para2_2_name = "They are innocent.";
                this->bc_para2_3_name = "Their demands are reasonable.";



                this->bs_title = "Support title";
                this->bs_para1 = "I think the prisoners might have forgotten what kind of institution they are being handled by. It's a prison complex, not a daycare.";
                this->bs_para2 = "The people protesting about this are the right wing extremists that were arrested for spreading hate speech in public. Society shouldn't tolerate that kind of behaviour and that is exactly why they are in jail. They will being educated in proper public conduct and eventually be reintroduced into society, so nobody should care about their comfort for the duration of their stay.";
                this->bs_para3 = "In the end there is no doubt that the hunger strike will end unsuccessfully. It has been tried before in other prisons and it has ultimately ended in failure.";

                this->nOptionNotoriety[0] = 2;
                this->nOptionPopularity[0] = 2;

                this->nOptionNotoriety[1] = 4;
                this->nOptionPopularity[1] = 4;

                this->nOptionNotoriety[2] = 2;
                this->nOptionPopularity[2] = 3;

                this->nSupportNotoriety = -1;
                this->nSupportPopularity = -1;

            }
            break;
        case a_usDemocrat:
            {
                this->title = "Kenneth Miller to win primaries.";
                this->body = "Democratic candidate Kenneth Miller endures massive support\nfor the Democatic primaries occuring in the US later this year.";


                this->bc_para1 = "Kenneth Miller is a crook. He has made no secret of his ties to the corporate establishment that has controlled the Democratic party the last couple of decades.";
                this->bc_para2_1 = "Like the previous elections in recent memory the Democrats have put forward an establishment candidate supporting corporate interests on the expense of public interest. The difference now is that Miller is putting himself out there as a populist, something that won the Republicans the presidency for the past two terms.";
                this->bc_para2_2 = "American politics in are in general too influential on the world. I know there is no easy way around it, but why should the entire planet be worried about an election they have no influence in. If Miller wins this election the issue will become even worse as he has publicly supported foreign intervention and threatened war with Russia, in addition to reconciliation with Europe.";
                this->bc_para2_3 = "The American establishment has a strong hold over the media, just like in a -certain- other western country, and has for two decades now manipulated polls in order to support their favorite candidate. Miller just so happens to support reconciliation with Europe and American integration, two talking points the globalist establishment are very interested in.";
                this->bc_para3 = "I can't say I like the idea of a Miller presidency, but the election is still many months off and the unexpected has happened a lot in recent history.";

                this->bc_para2_1_name = "Criticize Miller";
                this->bc_para2_2_name = "American politics are too influencial.";
                this->bc_para2_3_name = "Polls are untrustworthy.";

                this->bs_para1 = "While Miller isn't the Democratic candidate yet, I can't overstate my support of the guy.";
                this->bs_para2 = "Miller has long been clear of his support for reconciliation with Europe and of Russian containment. In an increasingly hostile world I think that a Miller presidency could be an invaluable ally. In addition he has adopted many of the Republican populist talking points and has promoted several ideas on how to enlargen the social safety net and improve the standard of living for Americans.";
                this->bs_para3 = "The US has been stuck with republican presidents for far too long and has suffered greatly from their isolationist and nationalistic policies. I ask of you American readers to support him, for the betterment of the world.";

                this->nOptionNotoriety[0] = 2;
                this->nOptionPopularity[0] = 3;

                this->nOptionNotoriety[1] = 1;
                this->nOptionPopularity[1] = 2;

                this->nOptionNotoriety[2] = 3;
                this->nOptionPopularity[2] = 4;

                this->nSupportNotoriety = -1;
                this->nSupportPopularity = -2;



            }
            break;
        case a_ukraineWar:
            {
                this->title = "Russia intervenes in Ukraine.";
                this->body = "Russia announces material and limited military aid for the rebels fighting in Ukraine.";

                this->bc_para1 = "This is just wrong. Ukraine's civil war has been fought constantly for now over 5 years and is finally nearing a conclusion.";
                this->bc_para2_1 = "This act will do nothing but prolong the civil war and cause the deaths of even more people. Eastern Ukraine has already been reduced to rubble but Russia seems to want to extend this to the rest of the country. This has just shown that Russia has plans for this \"New Russia\" they are creating from the ruins of Ukraine.";
                this->bc_para2_2 = "If Russia believes that the rest of the world will just sit by and do nothing while Russian soldiers march up to Kiev they are incredibly naive. Not only will this present a massive security risk to Europe, especially the Baltic states, but will be seen as an act of agression by the entire western world who I guarantee will take action.";
                this->bc_para2_3 = "I guess this is Russia just showing their true nature as they have essentially brought back imperialism as governing ethic. The question is though, where will it end? It is doubtful that Ukraine will be the last victim of Russian agression so previous Soviet states could be threatened, or they could even attempt an attack on Europe itself.";
                this->bc_para3 = "No matter how this evolves I can imagine the balance of power and the peace we have built over the years will unravel at an extraordinary pace in the near future.";

                this->bc_para2_1_name = "Don't prolong the war";
                this->bc_para2_2_name = "International consequences";
                this->bc_para2_3_name = "What will happen next?";

                this->bs_para1 = "This is a necessary move by Russia. The rebels of eastern Ukraine are doing nothing more then expressing their right to self-determination which has been denied them for many years.";
                this->bs_para2 = "Ukraine has for long tried to align itself towards Europe, which is fine, but many minorites of the country, most notably Russians, do not agree with this direction and would rather align with Russia. So, while a civil war might have been a bit too much, the Russian part of Ukraine should be allowed to separate and pursue its own ambitions and goals.";
                this->bs_para3 = "Russia moving troops in might be the decisive factor in ending the civil war in as bloodless a way as possible. Arguing for another position is just promoting a neverending bloodbath.";

                this->nOptionNotoriety[0] = 1;
                this->nOptionPopularity[0] = 2;

                this->nOptionNotoriety[1] = 1;
                this->nOptionPopularity[1] = 3;

                this->nOptionNotoriety[2] = 1;
                this->nOptionPopularity[2] = 3;

                this->nSupportNotoriety = 3;
                this->nSupportPopularity = 2;


            }
            break;
        default:
            std::cout << "DEFAULT CASE IN ARTICLE.CPP CONSTRUCTOR, ARTICLE TYPE: " << this->type << std::endl;
            break;
    }


    this->titleTxt.setCharacterSize(40);
    this->titleTxt.setFillColor(sf::Color::White);
    this->titleTxt.setFont(this->TextureGroupP->articleFont);
    this->titleTxt.setOutlineThickness(2);
    this->titleTxt.setOutlineColor(sf::Color::Black);
    this->titleTxt.setPosition(x + 10, y + 5);
    this->titleTxt.setString(this->title);

    this->bodyTxt.setCharacterSize(20);
    this->bodyTxt.setFillColor(sf::Color::Black);
    this->bodyTxt.setFont(this->TextureGroupP->articleFont);
    this->bodyTxt.setPosition(this->titleTxt.getGlobalBounds().left, this->titleTxt.getGlobalBounds().top + this->titleTxt.getGlobalBounds().height + 5);
    this->bodyTxt.setString(this->body);

    this->bodyTxt.setOutlineThickness(1);
    this->bodyTxt.setOutlineColor(sf::Color::White);

}

void Article::update()
{

}

void Article::queText(sf::Text tex)
{
    this->gameWindowP->queText(tex);
}

void Article::render()
{
    this->queText(this->titleTxt);
    this->queText(this->bodyTxt);
}

sf::Vector2f Article::getPosition()
{
    return this->titleTxt.getPosition();
}

articles Article::getType()
{
    return this->type;
}
