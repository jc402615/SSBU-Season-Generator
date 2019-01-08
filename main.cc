//*****************************************************************
//
//  Program:     SSBU Season Generator Main Function
//
//  Author:      Joey Cunningham - "OpenSkyze"
//  Email:       jc402615@ohio.edu
//
//  Description: Please view README.txt for info
//
//  Date:        Jan.04.2019
//
//*****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "stageData.h"
#include "Hplayer.h"
#include "Cplayer.h"
#include "Hteam.h"
#include "Cteam.h"


using namespace std;

//function prototypes
void printBasicMenu();
//*****************************************************************
//  Function:   printBasicMenu
//  Purpose:    prints out the header of the program
//  Parameters: none
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************


void loadData(vector<Hteam> userTeams, vector<Cteam> computerTeams);
//*****************************************************************
//  Function:   loadData
//  Purpose:    loads previous data from stored files
//  Parameters: teamNames - the vector to store the names in
//  Pre Conditions: the data files have not yet been accessed
//  Post Conditions: does not return a value
//*****************************************************************

void loadUserTeamNames(vector<Hteam> &userTeams);
//*****************************************************************
//  Function:   loadUserTeamNames
//  Purpose:    reads in user teams from file and stores them in vector
//  Parameters: userTeams - the vector to store the user teams in
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************

void loadComputerTeamNames(vector<Cteam> &computerTeams);
//*****************************************************************
//  Function:   loadComputerTeamNames
//  Purpose:    reads in computer teams from file and stores them in vector
//  Parameters: computerTeams - the vector to store the names in
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************


int main (){
    //read in previous data from disk
    vector<Hteam> userTeams;
    vector<Cteam> computerTeams;

    //functions to read in all data types from stored files
    loadData(userTeams, computerTeams);

    //end reading of data
    system("CLS"); //clears the screen -- << flush; to clear iostream
    printBasicMenu(); //intro

    string tempString; //used for data input
    int tempInt; //used for data input
    cin >> tempString;

    //need to see if team already exists



    return 0;
}

void printBasicMenu(){
    cout << "#################################################" << endl;
    cout << "#  Super Smash Bros. Ultimate Season Generator  #" << endl;
    cout << "#                                               #" << endl;
    cout << "#  By: OpenSkyze                                #" << endl;
    cout << "#################################################" << endl;
    cout << "#  Please enter your team name to begin:     #" << endl;
    cout << "#################################################" << endl << endl;
    cout << "Team Name: ";

}

void loadData(vector<Hteam> &userTeams, vector<Cteam> &computerTeams){
    loadUserTeamNames(userTeams);
    loadComputerTeamNames(computerTeams);
}

void loadUserTeamNames(vector<Hteam> &userTeams){
    ifstream inFile;
    inFile.open("userTeams.dat");
    if(inFile.fail()){
        cout << "unable to locate userTeams.dat" << endl;
    }
    else{
        string tempString;
        int tempInt;
        Hplayer tempPlayer;
        Hteam tempTeam;
        bool tempBool;

        getline(inFile, tempString); //priming read
        while(!inFile.eof()){ //read in all teams and add them to list
            tempTeam.setTeamName(tempString);
            inFile >> tempInt;
            tempTeam.setNumberOfPlayers(tempInt);
            inFile.ignore(); //ignore \n character
            inFile >> tempInt;
            tempTeam.setWins(tempInt);
            inFile.ignore();
            inFile >> tempInt;
            tempTeam.setLosses(tempInt);
            inFile.ignore();
            //now each team member's data needs to be read into temp player, then added to the team
            for(int i = 0; i < tempTeam.getNumberOfPlayers(); i++){
                getline(inFile, tempString);
                tempPlayer.setUser(tempString);
                getline(inFile, tempString);
                tempPlayer.setFighter(tempString);
                getline(inFile, tempString);
                tempPlayer.setCharacter(tempString);
                inFile >> tempInt;
                inFile.ignore();
                tempPlayer.setWins(tempInt);
                inFile >> tempInt;
                inFile.ignore();
                tempPlayer.setNumberOfMatchesPlayed(tempInt);
                inFile >> tempInt;
                inFile.ignore();
                tempPlayer.setKills(tempInt);
                inFile >> tempInt;
                inFile.ignore();
                tempPlayer.setDeaths(tempInt);
                //read in stage Data
                for(int j = 0; j < 103; j++){
                    getline(inFile, tempString);
                    tempPlayer.setStageDataName(j, tempString);
                    inFile >> tempBool;
                    inFile.ignore();
                    tempPlayer.setStageDataHasStrictEdges(j, tempBool);
                    inFile >> tempBool;
                    inFile.ignore();
                    tempPlayer.setStageDataHasSevereHazards(j, tempBool);
                    inFile >> tempInt;
                    inFile.ignore();
                    tempPlayer.setStageDataWins(j, tempInt);
                    inFile >> tempInt;
                    inFile.ignore();
                    tempPlayer.setStageDataNumberOfMatchesPlayed(j, tempInt);
                } //finished reading stage data for player
                tempTeam.addTeamMember(tempPlayer);
            } //finished reading all players
            userTeams.push_back(tempTeam);
            getline(inFile, tempString);
        } //end of while to read in a team
    }
    inFile.close();
}

void loadComputerTeamNames(vector<Cteam> &computerTeams){
    ifstream inFile;
    inFile.open("computerTeams.dat");
    if(inFile.fail()){
        cout << "could not find \'computerTeams.dat\'" << endl;
    }
    else{
        string tempString;
        int tempInt;
        Cplayer tempPlayer;
        Cteam tempTeam;

        getline(inFile, tempString);
        while(!inFile.eof()){
            tempTeam.setTeamName(tempString);
            inFile >> tempInt;
            inFile.ignore();
            tempTeam.setNumberOfPlayers(tempInt);
            inFile >> tempInt;
            inFile.ignore();
            tempTeam.setWins(tempInt);
            inFile >> tempInt;
            inFile.ignore();
            tempTeam.setLosses(tempInt);

            //now need to read in team member data
            for(int i = 0; i < tempTeam.getNumberOfPlayers(); i++){
                    getline(inFile, tempString);
                    tempPlayer.setId(tempString);
                    getline(inFile, tempString);
                    tempPlayer.setFighter(tempString);
                    inFile >> tempInt;
                    inFile.ignore();
                    tempPlayer.setLevel(tempInt);
                    inFile >> tempInt;
                    inFile.ignore();
                    tempPlayer.setKills(tempInt);
                    inFile >> tempInt;
                    inFile.ignore();
                    tempPlayer.setDeaths(tempInt);
                    //now can add the completed Cplayer to the team
                    tempTeam.addTeamMember(tempPlayer);
            }
            //now all team member and stats have been added, so add to collection
            computerTeams.push_back(tempTeam);
            getline(inFile, tempString);
        }
    }
    inFile.close();
}
