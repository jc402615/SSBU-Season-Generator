//*****************************************************************
//
//  Program:     Season header file
//
//  Author:      Joey Cunningham
//  Email:       jc402615@ohio.edu
//
//  Description: a season simuates an entity made up of a number of different
//               teams who fight against each other in order to be number 1 at
//               end of the season.
//
//  Date:        Jan.13.19
//
//*****************************************************************

#ifndef SEASON_H
#define SEASON_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "CTeam.h"
#include "Hteam.h"
#include "Match.h"

using namespace std;

class Season{
public:
    Season();

    void setTotalNumberOfTeams(int newTotalNumberOfTeams);
    void setNumberOfHumanTeams(int newNumberOfHumanTeams);

    int getTotalNumberOfTeams();
    int getNumberOfHumanTeams();

    //helpers
    int getNumberOfComputerTeams();
    void addHumanTeamByNameFrom(string teamName, vector<Hteam> &userTeams);
    //places an iterator pointing to the team with teamName located in userTeams into activeHumanTeams
    void setComputerTeams(vector<Cteam> &newComputerTeams);
    //sets computerTeams to be the same as the argument newComputerTeams
    void generateMatchups(string &encodedOutput);
    //generates all of the matchups for the season
vector<string> generateSchedule();
private:

    //uses a basic number format to fill the initial table used to make the round robin matchups
    void fillCodedOutputWith(vector<string> &encodedOutput, vector<int> &topRow, vector<int> &bottomRow);
    //places the matchups into the encodedOutput vector, where each string contains the matchups for the week
    void rotateRoundRobinTeams(vector<int> &topRow, vector<int> &bottomRow);
    int totalNumberOfTeams;
    int numberOfHumanTeams;

    vector<vector<Hteam>::iterator> activeHumanTeams;  //holds pointers to all the human teams in the season, located in the global vector
    vector<Cteam> computerTeams;      //holds all the computer teams in the season
    vector<vector<Match>> matchups;   //holds all the matches for a season in a 2D vector
};





#endif
