//*****************************************************************
//
//  Program:     Hteam header file
//
//  Author:      Joey Cunningham
//  Email:       jc402615@ohio.edu
//
//  Description: team of human players, including the amount and statistics
//
//  Date:        Jan.06.19
//
//*****************************************************************

#ifndef HTEAM_H
#define HTEAM_H

#include "Hplayer.h"
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class Hteam{
public:
    //constructor
    Hteam();

    //getters
    string getTeamName();
    int getNumberOfPlayers();
    int getWins();
    int getLosses();
    Hplayer getTeamMemberAtIndex(int index);
    bool getIsMainTeam();
    int getTeamKills();
    int getTeamDeaths();
    int getWinStreak();
    int getRank();

    //setters
    void setTeamName(string newTeamName);
    void setNumberOfPlayers(int newNumberOfPlayers);
    void setWins(int newWins);
    void setLosses(int newLosses);
    bool addTeamMember(Hplayer newTeamMember); //returns true if added successfully
    //!!!! anytime a teamMember is added, need to increment the numberOfPlayers by one
    void setIsMainTeam(bool newIsMainTeam);
    void setTeamKills(int newTeamKills);
    void setTeamDeaths(int newTeamDeaths);
    void setWinStreak(int newWinStreak);
    void setRank(int newRank);

    //addtional helpers for Hplayer teamMembers stats
    void increaseTeamMemberWinsAtIndex(int index);
    void increaseTeamMemberNumberOfMatchesPlayedAtIndex(int index);
    void increaseTeamMemberKillsAtIndex(int index);
    void doubleIncreaseTeamMemberKillsAtIndex(int index);
    void increaseTeamMemberDeathsAtIndex(int index);
    void increaseTeamMemberStageDataWinsAtIndices(int memberIndex, int stageIndex);
    void increaseTeamMemberStageDataNumberOfMatchesPlayed(int memberIndex, int stageIndex);

    //helpers
    int getTotalMatchesPlayed();
    void printRecord();
    void printTeamMembers();
    void increaseWins();
    void increaseLosses();
    bool isAlreadyOnTeam(string HplayerCharName);
    void increaseNumberOfPlayers();
    void removeAllTeamMembers(); //useful for when loading data
    void increaseTeamKills();
    void increaseTeamDeaths();
    void increaseWinStreak();
    void decreaseWinStreak();
    int getKDDifferential();
    int getWinPercentage(); //return value between 1 and 1000
    void increaseRank();
    void writeStandingsData();

private:
    string teamName;
    int numberOfPlayers; //number of players that make up the team
    int wins;  //number of wins
    int losses;//numbers of losses
    vector<Hplayer> teamMembers; //holds the human players on the team
    bool isMainTeam; //whether or not the team has its own season
    int teamKills; //number of kills accumulated by the team in total
    int teamDeaths; //number of deaths accumulated by the team in total
    int winStreak; //the number of games won (if +) or lossed (if -) consecutively
    int rank;
};

#endif
