#include "Hplayer.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

Hplayer::Hplayer(){
    user = "NO USER";
    fighter = "NO FIGHTER";
    character = "NO CHARACTER";
    wins = 0;
    numberOfMatchesPlayed = 0;
    kills = 0;
    deaths = 0;

    //now need to read in set elements about stages
    string tempString;
    bool tempBool;

    ifstream inFile;
    inFile.open("stages.dat");
    if(inFile.fail()){
        cout << "Error: \"stages.dat\" not found. closing program" << endl;
        exit(1);
    }
    for(int i = 0; i < 103; i++){
        getline(inFile, tempString);
        setStageDataName(i, tempString);
        inFile >> tempBool;
        inFile.ignore();
        setStageDataHasStrictEdges(i, tempBool);
        inFile >> tempBool;
        inFile.ignore();
        setStageDataHasSevereHazards(i, tempBool);
    }
    inFile.close();
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

int Hplayer::getKills(){
    return kills;
}
int Hplayer::getDeaths(){
    return deaths;
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

void Hplayer::setKills(int newKills){
    kills = newKills;
}
void Hplayer::setDeaths(int newDeaths){
    deaths = newDeaths;
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

void Hplayer::increaseKills(){
    kills++;
}
void Hplayer::doubleIncreaseKills(){
    kills += 2;
}
void Hplayer::increaseDeaths(){
    deaths++;
}
