#include "stageData.h"
#include "Hplayer.h"
#include "Cplayer.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Welcome to testing area!!" << endl << endl;
    /*
    stageData temp;
    cout << temp.getName() << endl;
    cout << temp.getHasStrictEdges() << endl;
    cout << temp.getHasSevereHazards() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;

    cout << "now setting" << endl;
    temp.setName("ImaStage");
    temp.setHasStrictEdges(true);
    temp.setHasSevereHazards(true);
    temp.setWins(21);
    temp.setNumberOfMatchesPlayed(100);

    cout << "now the stage looks like this" << endl;
    cout << temp.getName() << endl;
    cout << temp.getHasStrictEdges() << endl;
    cout << temp.getHasSevereHazards() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;
    cout << "losses: " << temp.getLosses() << endl;
    */
/*
    Hplayer temp;
    cout << "here is the fighter currently" << endl;
    cout << temp.getUser() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getCharacter() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;
    cout << temp.getLosses() << endl;
    cout << temp.getStageDataAtIndex(0).getWins() << endl << endl;

    cout << "setting player" << endl;
    temp.setUser("Joey");
    temp.setFighter("Kirby");
    temp.setCharacter("JJ");
    temp.setWins(20);
    temp.increaseWins();
    temp.setNumberOfMatchesPlayed(30);
    temp.setStageDataWins(0, 100);
    temp.increaseStageDataWins(0);

    cout << "now the player is " << endl << endl;
    cout << temp.getUser() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getCharacter() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;
    cout << temp.getLosses() << endl;
    cout << temp.getStageDataAtIndex(0).getWins() << endl << endl;
*/
    Cplayer temp;
    cout << "the cplayer starts as" << endl;
    cout << temp.getId() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getLevel() << endl;
    cout << temp.getKills() << endl;
    cout << temp.getDeaths() << endl;

    cout << "setting the cplayer" << endl;
    temp.setId("Foxy Slayer");
    temp.setFighter("Fox");
    temp.setLevel(9);
    temp.setKills(10);
    temp.setDeaths(2);

    temp.increaseLevel();



    cout << "the cplayer is now" << endl;
    cout << temp.getId() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getLevel() << endl;
    cout << temp.getKills() << endl;
    cout << temp.getDeaths() << endl;

    return 0;
}
