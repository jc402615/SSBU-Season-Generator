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
#include <sstream>
#include <windows.h>
#include <fstream>
#include "Cplayer.h"
#include "Hplayer.h"
#include "CTeam.h"
#include "Hteam.h"
#include "Match.h"

using namespace std;

class Season{
public:
    Season();

    //!!!!!!!!!!!!!!!!!!!!!
    void makeNew(string activeTeamName, vector<Hteam> &userTeams,
                 vector<string> &fighters, vector<string> &idNames,
                 vector<string> &adjectives, vector<string> &nouns,
                 vector<string> &stages);
                 /////contains all the questions and details when starting a brand new season from scratch for new Teams
                 //the rest of the vectors are used for cpuTeam generation

    void setTotalNumberOfTeams(int newTotalNumberOfTeams);
    void setNumberOfHumanTeams(int newNumberOfHumanTeams);
    void setNumberOfPlayersPerTeam(int newNumberOfPlayersPerTeam);
    void setBattleAmount(int newBattleAmount);

    int getTotalNumberOfTeams();
    int getNumberOfHumanTeams();
    int getNumberOfPlayersPerTeam();
    int getBattleAmount();

    //helpers
    int getNumberOfComputerTeams();
    void addHumanTeamByNameFrom(string teamName, vector<Hteam> &userTeams);
    //places an iterator pointing to the team with teamName located in userTeams into activeHumanTeams
    void setComputerTeams(vector<Cteam> &newComputerTeams);
    //sets computerTeams to be the same as the argument newComputerTeams
    void generateSchedule(vector<string> &stages);
    //uses a basic number format to fill the initial table used to make the round robin matchups
    //this is the function to use to generate all season matchups
    void generateRestOfCpuTeams(vector<string> &fighters, vector<string> &idNames,
                                vector<string> &adjectives, vector<string> &nouns);
    //requires rand to be seeded, all the vectors to be filled, totalNumberOfTeams and numberOfHumanTeams
    //already set, ...?
    void printOutAllMatchups();
    void printOutAllMatchupsForWeek(int weekNum);
    void createAHTeam(string newTeamName, vector<Hteam> &userTeams, int numPlayers = 0, bool newIsMainTeam = true);
    //the team will placed into userTeams after it has been created
    void waitForEnterPress();
    bool isWorseThan(Hteam &thisTeam, Hteam &otherTeam);
    bool isWorseThan(Hteam &thisTeam, Cteam &otherTeam);
    bool isWorseThan(Cteam &thisTeam, Hteam &otherTeam);
    bool isWorseThan(Cteam &thisTeam, Cteam &otherTeam);
    void saveComputerTeams();
    void loadComputerTeams(string activeTeam);
    void saveHumanTeamNames();
    void loadActiveHumanTeams(string activeTeam, vector<Hteam> &userTeams);
    void saveImperitiveSeasonData();
    void loadImperitiveSeasonData(string activeTeam);
    void saveMatchups();
    void loadMatchups(string activeTeam);
    void loadCombinedData(string activeTeam, vector<Hteam> &userTeams);
    void saveCombinedData();
    void updateRanks();
    void printTeamStandingsTable();
    void printScheduledMatches(vector<Hteam> &userTeams, vector<Cteam> &computerTeams);
    int printSeasonStatusMenu(vector<Hteam> &userTeams);
    void seasonHandler(vector<Hteam> &userTeams);
    void playWeeklyMatchups(vector<Hteam> &userTeams);
private:

    void fillCodedOutputWith(vector<string> &encodedOutput, vector<int> &topRow, vector<int> &bottomRow);
    //places the matchups into the encodedOutput vector, where each string contains the matchups for the week
    void rotateRoundRobinTeams(vector<int> &topRow, vector<int> &bottomRow);
    void randomizeWeeklySchedule(vector<string> &encodedOutput);
    //switches around the indices of the vector, while keeping the data intact
    void generateMatchups(vector<string> &encodedOutput, vector<string> &stages);
    //generates all of the matchups for the season

    Cplayer generateRandomComputerPlayer(vector<string> &fighters, vector<string> &idNames);
    Cteam generateRandomComputerTeam(int numberOfPlayers, vector<string> &fighters,
                                     vector<string> &idNames, vector<string> &adjectives,
                                     vector<string> &nouns);
    Hplayer createAHplayer();
    void printCreateAPlayerHelpMenu();
    int isAlreadyATeam(string teamName, vector<Hteam> &userTeams);

    //member variables
    int totalNumberOfTeams;
    int numberOfHumanTeams;
    int numberOfPlayersPerTeam;
    int battleAmount; //the number of lives or minutes in a battle

    vector<vector<Hteam>::iterator> activeHumanTeams;  //holds pointers to all the human teams in the season, located in the global vector
    vector<Cteam> computerTeams;      //holds all the computer teams in the season
    vector<vector<Match>> matchups;   //holds all the matches for a season in a 2D vector
};





#endif
