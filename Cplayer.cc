#include "Cplayer.h"

Cplayer::Cplayer(){
    id = "CPU";
    fighter = "NO FIGHTER";
    level = 1;
    kills = 0;
    deaths = 0;
}

Cplayer::Cplayer(string newId, string newFighter, int newLevel, int newKills,
        int newDeaths)
        {
            id = newId;
            fighter = newFighter;
            level = newLevel;
            kills = newKills;
            deaths = newDeaths;
        }

string Cplayer::getId(){
    return id;
}

string Cplayer::getFighter(){
    return fighter;
}

int Cplayer::getLevel(){
    return level;
}

int Cplayer::getKills(){
    return kills;
}

int Cplayer::getDeaths(){
    return deaths;
}

void Cplayer::setId(string newId){
    id = newId;
}

void Cplayer::setFighter(string newFighter){
    fighter = newFighter;
}

void Cplayer::setLevel(int newLevel){
    level = newLevel;
}

void Cplayer::setKills(int newKills){
    kills = newKills;
}

void Cplayer::setDeaths(int newDeaths){
    deaths = newDeaths;
}

void Cplayer::increaseLevel(){
    if(level != 9){
        level++;
    }

}

void Cplayer::decreaseLevel(){
    if(level != 1){
        level--;
    }

}

void Cplayer::increaseKills(){
    kills++;
}

void Cplayer::doubleIncreaseKills(){
    kills += 2;
}

void Cplayer::increaseDeaths(){
    deaths++;
}
