//*****************************************************************
//
//  Program:     Match header file
//
//  Author:      Joey Cunningham
//  Email:       jc402615@ohio.edu
//
//  Description: a Match represents a face off between 2 teams (human, cpu, or mixed)
//               and captures data from the match. If both teams are cpu, then a
//               calculation is done to determine the winner.
//
//  Date:        Jan.13.19
//
//*****************************************************************


#ifndef MATCH_H
#define MATCH_H

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "Hteam.h"
#include "Cteam.h"

using namespace std;

class Match{

public:
    void addHumanTeam(Hteam &humanTeam);
    void addCpuTeam(Cteam &cpuTeam);
    void clearBothTeams();

    bool isHumanMatch();
    bool isCpuMatch();
    bool isMixedMatch();

    void playStock(vector<Hteam> &userTeams, vector<Cteam> &computerTeams, int stockLives);
    //runs the match and collects data depending on what type of teams
    //are involved in the match
    void printWinner(ostream &outs);
    void printMatchup();
    void setStageName(string newStageName);
    string getStageName();
    void setHWinner(Hteam &humanTeam);
    void setCWinner(Cteam &cpuTeam);
    void randomlySetStage(vector<string> &stages);
    //uses the names within stages and randomly assigns one to stageName
    void writeTeamNames(ostream &outs);
    int writeTeamNameAndRecord();
    //returns the length that the string it writes takes up

    //simulation functions
    double getProbabilityOfWinFor(Cteam team);
    int getNumberOfKillsForLosingTeam(int maxKills, double probabilityOfWin);

private:
    vector<Hteam> humanTeams; //holds human team combatants
    vector<Cteam> cpuTeams;   //holds cpu team combatants

    Hteam Hwinner; //used to hold the winner if its a human team
    Cteam Cwinner; //used to hold the winner if its a computer team

    string stageName;

};

#endif
