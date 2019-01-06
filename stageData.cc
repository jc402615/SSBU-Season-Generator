#include "stageData.h"

stageData::stageData(){
    name = "NO NAME";
    hasStrictEdges = false;
    hasSevereHazards = false;
    wins = 0;
    numberOfMatchesPlayed = 0;

}

stageData::stageData(string newName, bool newHasStrictEdges, bool newHasSevereHazards,
          int newWins, int newNumberOfMatchesPlayed)
          {
              name = newName;
              hasStrictEdges = newHasStrictEdges;
              hasSevereHazards = newHasSevereHazards;
              wins = newWins;
              numberOfMatchesPlayed = newNumberOfMatchesPlayed;
          }

string stageData::getName(){
    return name;
}
bool stageData::getHasStrictEdges(){
    return hasStrictEdges;
}
bool stageData::getHasSevereHazards(){
    return hasSevereHazards;
}
int stageData::getWins(){
    return wins;
}
int stageData::getNumberOfMatchesPlayed(){
    return numberOfMatchesPlayed;
}
void stageData::setName(string newName){
    name = newName;
}
void stageData::setHasStrictEdges(bool newHasStrictEdges){
    hasStrictEdges = newHasStrictEdges;
}
void stageData::setHasSevereHazards(bool newHasSevereHazards){
    hasSevereHazards = newHasSevereHazards;
}
void stageData::setWins(int newWins){
    wins = newWins;
}
void stageData::setNumberOfMatchesPlayed(int newNumberOfMatchesPlayed){
    numberOfMatchesPlayed = newNumberOfMatchesPlayed;
}

void stageData::increaseWins(){
    wins++;
}

void stageData::increaseNumberOfMatchesPlayed(){
    numberOfMatchesPlayed++;
}

int stageData::getLosses(){
    return (numberOfMatchesPlayed - wins);
}
