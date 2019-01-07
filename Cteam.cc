#include "Cteam.h"
#include <iostream>

Cteam::Cteam(){
    teamName = "NO TEAM NAME";
    numberOfPlayers = 0;
    wins = 0;
    losses = 0;
}

string Cteam::getTeamName(){
    return teamName;
}

int Cteam::getNumberOfPlayers(){
    return numberOfPlayers;
}

int Cteam::getWins(){
    return wins;
}

int Cteam::getLosses(){
    return losses;
}

Cplayer Cteam::getTeamMemberAtIndex(int index){
    return teamMembers[index];
}

void Cteam::setTeamName(string newTeamName){
    teamName = newTeamName;
}

void Cteam::setNumberOfPlayers(int newNumberOfPlayers){
    numberOfPlayers = newNumberOfPlayers;
}

void Cteam::setWins(int newWins){
    wins = newWins;
}

void Cteam::setLosses(int newLosses){
    losses = newLosses;
}

void Cteam::addTeamMember(Cplayer &newTeamMember){
    teamMembers.push_back(newTeamMember);
    numberOfPlayers++;
}

int Cteam::getTotalMatchesPlayed(){
    return (wins + losses);
}

void Cteam::printRecord(){
    cout << wins << "-" << losses;
}

void Cteam::printTeamMembers(){
    if(numberOfPlayers == 0){

    }
    else if(numberOfPlayers == 1){
        cout << teamMembers[0].getId();
    }
    else{
        int i = 0;
        for(; i < numberOfPlayers - 1; i++){
            cout << teamMembers[i].getId() << " & ";
        }
        cout << teamMembers[i].getId();
    }

}

void Cteam::increaseWins(){
    wins++;
}

void Cteam::increaseLosses(){
    losses++;
}

void Cteam::increaseTeamMemberKillsAtIndex(int index){
    teamMembers[index].increaseKills();
}

void Cteam::doubleIncreaseTeamMemberKillsAtIndex(int index){
    teamMembers[index].doubleIncreaseKills();
}

void Cteam::increaseTeamMemberDeathsAtIndex(int index){
    teamMembers[index].increaseDeaths();
}

void Cteam::increaseTeamMemberLevelAtIndex(int index){
    teamMembers[index].increaseLevel();
}

void Cteam::decreaseTeamMemberLevelAtIndex(int index){
    teamMembers[index].decreaseLevel();
}
