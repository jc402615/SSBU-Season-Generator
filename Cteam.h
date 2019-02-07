//*****************************************************************
//
//  Program:     Cteam header file
//
//  Author:      Joey Cunningham
//  Email:       jc402615@ohio.edu
//
//  Description: team of computer players, including the amount and statistics
//
//  Date:        Jan.07.19
//
//*****************************************************************

#ifndef CTEAM_H
#define CTEAM_H

#include "Cplayer.h"
#include <string>
#include <vector>

using namespace std;

class Cteam{
public:
    //constructor
    Cteam();

    //getters
    string getTeamName();
    int getNumberOfPlayers();
    int getWins();
    int getLosses();
    Cplayer getTeamMemberAtIndex(int index);
    int getTeamKills();
    int getTeamDeaths();
    int getWinStreak();
    int getRank();

    //setters
    void setTeamName(string newTeamName);
    void setNumberOfPlayers(int newNumberOfPlayers);
    void setWins(int newWins);
    void setLosses(int newLosses);
    void addTeamMember(Cplayer &newTeamMember);
    //must increment the numberOfPlayers by 1
    void setTeamKills(int newTeamKills);
    void setTeamDeaths(int newTeamDeaths);
    void setWinStreak(int newWinStreak);
    void setRank(int newRank);

    //helpers
    int getTotalMatchesPlayed();
    void printRecord();
    void printTeamMembers();
    void increaseWins();
    void increaseLosses();
    void removeAllTeamMembers();
    void increaseTeamKills();
    void increaseTeamDeaths();
    void increaseWinStreak();
    void decreaseWinStreak();
    int getKDDifferential();

    //additional helpers
    void increaseTeamMemberKillsAtIndex(int index);
    void doubleIncreaseTeamMemberKillsAtIndex(int index);
    void increaseTeamMemberDeathsAtIndex(int index);
    void increaseTeamMemberLevelAtIndex(int index);
    void decreaseTeamMemberLevelAtIndex(int index);
private:
    string teamName;
    int numberOfPlayers; //players that make up the team
    int wins; //number of wins
    int losses; //number of losses
    vector<Cplayer> teamMembers; //holds the cpu player on the team
    int teamKills;
    int teamDeaths;
    int winStreak;
    int rank;


};


#endif
