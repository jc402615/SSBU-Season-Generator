#include "stageData.h"
#include "Hplayer.h"
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
    Hplayer temp;
    cout << "here is the fighter currently" << endl;
    cout << temp.getUser() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getCharacter() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;
    cout << temp.getLosses() << endl;
    cout << temp.getStageDataAtIndex(0).getName() << endl << endl;

    cout << "setting player" << endl;
    temp.setUser("Joey");
    temp.setFighter("Kirby");
    temp.setCharacter("JJ");
    temp.setWins(20);
    temp.setNumberOfMatchesPlayed(30);
    temp.getStageDataAtIndex(0).setName("Stage 0"); //doesn't update stages

    cout << "now the player is " << endl << endl;
    cout << temp.getUser() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getCharacter() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;
    cout << temp.getLosses() << endl;
    cout << temp.getStageDataAtIndex(0).getName() << endl << endl;
    return 0;
}
