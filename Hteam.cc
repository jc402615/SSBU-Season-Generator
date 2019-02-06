#include "Hteam.h"
#include <iostream>

Hteam::Hteam(){
    teamName = "NO TEAM NAME";
    numberOfPlayers = 0;
    isMainTeam = false;
    wins = 0;
    losses = 0;
}

string Hteam::getTeamName(){
    return teamName;
}

int Hteam::getNumberOfPlayers(){
    return numberOfPlayers;
}

int Hteam::getWins(){
    return wins;
}

int Hteam::getLosses(){
    return losses;
}
Hplayer Hteam::getTeamMemberAtIndex(int index){
    return teamMembers[index];
}

bool Hteam::getIsMainTeam(){
    return isMainTeam;
}

void Hteam::setTeamName(string newTeamName){
    teamName = newTeamName;
}

void Hteam::setNumberOfPlayers(int newNumberOfPlayers){
    numberOfPlayers = newNumberOfPlayers;
}

void Hteam::setWins(int newWins){
    wins = newWins;
}

void Hteam::setLosses(int newLosses){
    losses = newLosses;
}

void Hteam::setIsMainTeam(bool newIsMainTeam){
    isMainTeam = newIsMainTeam;
}

void Hteam::increaseTeamMemberWinsAtIndex(int index){
    teamMembers[index].increaseWins();
}

void Hteam::increaseTeamMemberNumberOfMatchesPlayedAtIndex(int index){
    teamMembers[index].increaseNumberOfMatchesPlayed();
}

void Hteam::increaseTeamMemberKillsAtIndex(int index){
    teamMembers[index].increaseKills();
}

void Hteam::doubleIncreaseTeamMemberKillsAtIndex(int index){
    teamMembers[index].doubleIncreaseKills();
}

void Hteam::increaseTeamMemberDeathsAtIndex(int index){
    teamMembers[index].increaseDeaths();
}

void Hteam::increaseTeamMemberStageDataWinsAtIndices(int memberIndex, int stageIndex){
    teamMembers[memberIndex].increaseStageDataWins(stageIndex);
}

void Hteam::increaseTeamMemberStageDataNumberOfMatchesPlayed(int memberIndex, int stageIndex){
    teamMembers[memberIndex].increaseStageDataNumberOfMatchesPlayed(stageIndex);
}

bool Hteam::addTeamMember(Hplayer newTeamMember){
    if(!isAlreadyOnTeam(newTeamMember.getCharacter())){
        teamMembers.push_back(newTeamMember);
        return true;
    }
    else{
        cout << "Unable to add player: already on team." << endl;
        return false;
    }

}

int Hteam::getTotalMatchesPlayed(){
    return (wins + losses);
}

void Hteam::printRecord(){
    cout << wins << "-" << losses;
}

void Hteam::printTeamMembers(){
    if(numberOfPlayers == 0){

    }
    else if(numberOfPlayers == 1){
        cout << teamMembers[0].getCharacter();
    }
    else{
        int i = 0;
        for(; i < numberOfPlayers - 1; i++){
            cout << teamMembers[i].getCharacter() << " & ";
        }
        cout << teamMembers[i].getCharacter();
    }

}

void Hteam::increaseWins(){
    wins++;
}

void Hteam::increaseLosses(){
    losses++;
}

bool Hteam::isAlreadyOnTeam(string HplayerCharName){
    for(size_t i = 0; i < teamMembers.size(); i++){
        if(teamMembers[i].getCharacter() == HplayerCharName){
            return true;
        }
    }
    return false;
}

void Hteam::increaseNumberOfPlayers(){
    numberOfPlayers++;
}

void Hteam::removeAllTeamMembers(){
    teamMembers.clear();
}
