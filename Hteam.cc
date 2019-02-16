#include "Hteam.h"
#include <iostream>

Hteam::Hteam(){
    teamName = "NO TEAM NAME";
    numberOfPlayers = 0;
    isMainTeam = false;
    wins = 0;
    losses = 0;
    teamKills = 0;
    teamDeaths = 0;
    winStreak = 0;
    rank = 1; //everybody is completely tied at the beginning of the season
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

int Hteam::getTeamKills(){
    return teamKills;
}

int Hteam::getTeamDeaths(){
    return teamDeaths;
}

int Hteam::getWinStreak(){
    return winStreak;
}

int Hteam::getRank(){
    return rank;
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

void Hteam::setTeamKills(int newTeamKills){
    teamKills = newTeamKills;
}

void Hteam::setTeamDeaths(int newTeamDeaths){
    teamDeaths = newTeamDeaths;
}

void Hteam::setWinStreak(int newWinStreak){
    winStreak = newWinStreak;
}

void Hteam::setRank(int newRank){
    rank = newRank;
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

void Hteam::increaseTeamKills(){
    teamKills++;
}

void Hteam::increaseTeamDeaths(){
    teamDeaths++;
}

void Hteam::increaseWinStreak(){
    if(winStreak >= 0){//positive
        winStreak++;
    }
    else{//negative
        winStreak = 1;
    }
}

void Hteam::decreaseWinStreak(){
    if(winStreak <= 0){//negative
        winStreak--;
    }
    else{//positive
        winStreak = -1;
    }
}
int Hteam::getKDDifferential(){
    return (teamKills - teamDeaths);
}

int Hteam::getWinPercentage(){
    double totalMatchesPlayed = wins + losses;
    double percentage = (wins/totalMatchesPlayed);
    int modifiedAnswer = round(1000 * percentage);

    return modifiedAnswer;
}

void Hteam::increaseRank(){
    rank++;
}

void Hteam::writeStandingsData(){
    cout << left << setw(27) << getTeamName();
    cout << right << setw(5) << getWins();
    cout << right << setw(10) << getLosses();
    cout << right << setw(10) << getTeamKills();
    cout << right << setw(9) << getTeamDeaths();
    cout << right << setw(11) << getKDDifferential();
    cout << endl;
}
