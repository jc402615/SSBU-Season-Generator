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

    //setters
    void setTeamName(string newTeamName);
    void setNumberOfPlayers(int newNumberOfPlayers);
    void setWins(int newWins);
    void setLosses(int newLosses);
    void addTeamMember(Cplayer &newTeamMember);

    //helpers
    int getTotalMatchesPlayed();
    void printRecord();
    void printTeamMembers();
    void increaseWins();
    void increaseLosses();

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


};


#endif
