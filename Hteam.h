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

    //setters
    void setTeamName(string newTeamName);
    void setNumberOfPlayers(int newNumberOfPlayers);
    void setWins(int newWins);
    void setLosses(int newLosses);
    bool addTeamMember(Hplayer newTeamMember); //returns true if added successfully
    //!!!! anytime a teamMember is added, need to increment the numberOfPlayers by one

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

private:
    string teamName;
    int numberOfPlayers; //number of players that make up the team
    int wins;  //number of wins
    int losses;//numbers of losses
    vector<Hplayer> teamMembers; //holds the human players on the team
};

#endif
