#include "Cteam.h"
#include <iostream>

Cteam::Cteam(){
    teamName = "NO TEAM NAME";
    numberOfPlayers = 0;
    wins = 0;
    losses = 0;
    teamKills = 0;
    teamDeaths = 0;
    winStreak = 0;
    rank = 1;
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

int Cteam::getTeamKills(){
    return teamKills;
}

int Cteam::getTeamDeaths(){
    return teamDeaths;
}

int Cteam::getWinStreak(){
    return winStreak;
}

int Cteam::getRank(){
    return rank;
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
}

void Cteam::setTeamKills(int newTeamKills){
    teamKills = newTeamKills;
}

void Cteam::setTeamDeaths(int newTeamDeaths){
    teamDeaths = newTeamDeaths;
}

void Cteam::setWinStreak(int newWinStreak){
    winStreak = newWinStreak;
}

void Cteam::setRank(int newRank){
    rank = newRank;
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

void Cteam::increaseTeamKills(){
    teamKills++;
}

void Cteam::increaseTeamDeaths(){
    teamDeaths++;
}

void Cteam::increaseWinStreak(){
    if(winStreak >= 0){//positive
        winStreak++;
    }
    else{//negative
        winStreak = 1;
    }
}

void Cteam::decreaseWinStreak(){
    if(winStreak <= 0){//negative
        winStreak--;
    }
    else{//positive
        winStreak = -1;
    }
}

int Cteam::getKDDifferential(){
    return (teamKills - teamDeaths);
}

int Cteam::getWinPercentage(){
    double totalMatchesPlayed = wins + losses;
    double percentage = (wins/totalMatchesPlayed);
    int modifiedAnswer = round(1000 * percentage);
    return modifiedAnswer;
}

void Cteam::increaseRank(){
    rank++;
}

void Cteam::writeStandingsData(){
    cout << left << setw(27) << getTeamName();
    cout << right << setw(5) << getWins();
    cout << right << setw(10) << getLosses();
    cout << right << setw(10) << getTeamKills();
    cout << right << setw(9) << getTeamDeaths();
    cout << right << setw(11) << getKDDifferential();
    cout << endl;
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

void Cteam::removeAllTeamMembers(){
    teamMembers.clear();
}
