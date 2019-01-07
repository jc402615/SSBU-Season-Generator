#include "Hplayer.h"

Hplayer::Hplayer(){
    user = "NO USER";
    fighter = "NO FIGHTER";
    character = "NO CHARACTER";
    wins = 0;
    numberOfMatchesPlayed = 0;
    //stage data will already be constructed through its own
}


string Hplayer::getUser(){
    return user;
}
string Hplayer::getFighter(){
    return fighter;
}
string Hplayer::getCharacter(){
    return character;
}
int Hplayer::getWins(){
    return wins;
}
int Hplayer::getNumberOfMatchesPlayed(){
    return numberOfMatchesPlayed;
}
stageData Hplayer::getStageDataAtIndex(int index){
    return stageStats[index];
}


void Hplayer::setUser(string newUser){
    user = newUser;
}
void Hplayer::setFighter(string newFighter){
    fighter = newFighter;
}
void Hplayer::setCharacter(string newCharacter){
    character = newCharacter;
}
void Hplayer::setWins(int newWins){
    wins = newWins;
}
void Hplayer::setNumberOfMatchesPlayed(int newNumberOfMatchesPlayed){
    numberOfMatchesPlayed = newNumberOfMatchesPlayed;
}

void Hplayer::setStageDataName(int index, string newName){
    stageStats[index].setName(newName);
}
void Hplayer::setStageDataHasStrictEdges(int index, bool newHasStrictEdges){
    stageStats[index].setHasStrictEdges(newHasStrictEdges);
}
void Hplayer::setStageDataHasSevereHazards(int index, bool newHasSevereHazards){
    stageStats[index].setHasSevereHazards(newHasSevereHazards);
}
void Hplayer::setStageDataWins(int index, int newWins){
    stageStats[index].setWins(newWins);
}
void Hplayer::setStageDataNumberOfMatchesPlayed(int index, int newNumberOfMatchesPlayed){
    stageStats[index].setNumberOfMatchesPlayed(newNumberOfMatchesPlayed);
}

void Hplayer::increaseWins(){
    wins++;
}
void Hplayer::increaseNumberOfMatchesPlayed(){
    numberOfMatchesPlayed++;
}
int Hplayer::getLosses(){
    return (numberOfMatchesPlayed - wins);
}

void Hplayer::increaseStageDataWins(int index){
    stageStats[index].increaseWins();
}
void Hplayer::increaseStageDataNumberOfMatchesPlayed(int index){
    stageStats[index].increaseNumberOfMatchesPlayed();
}
