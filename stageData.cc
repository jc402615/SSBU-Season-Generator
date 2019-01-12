#include "stageData.h"

stageData::stageData(){
    name = "NO NAME";
    hasStrictEdges = false;
    hasSevereHazards = false;
    hasScrolling = false;
    wins = 0;
    numberOfMatchesPlayed = 0;

}

stageData::stageData(string newName, bool newHasStrictEdges, bool newHasSevereHazards,
                     bool newHasScrolling, int newWins, int newNumberOfMatchesPlayed)
          {
              name = newName;
              hasStrictEdges = newHasStrictEdges;
              hasSevereHazards = newHasSevereHazards;
              hasScrolling = newHasScrolling;
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

bool stageData::getHasScrolling(){
    return hasScrolling;
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

void stageData::setHasScrolling(bool newHasScrolling){
    hasScrolling = newHasScrolling;
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
