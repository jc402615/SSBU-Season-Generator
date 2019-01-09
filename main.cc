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
void printBasicMenu(vector<Hteam> &userTeams);
//*****************************************************************
//  Function:   printBasicMenu
//  Purpose:    prints out the header of the program
//  Parameters: none
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************


void loadData(vector<Hteam> &userTeams, vector<Cteam> &computerTeams);
//*****************************************************************
//  Function:   loadData
//  Purpose:    loads previous data from stored files
//  Parameters: teamNames - the vector to store the names in
//  Pre Conditions: the data files have not yet been accessed
//  Post Conditions: does not return a value
//*****************************************************************

void loadUserTeams(vector<Hteam> &userTeams);
//*****************************************************************
//  Function:   loadUserTeamNames
//  Purpose:    reads in user teams from file and stores them in vector
//  Parameters: userTeams - the vector to store the user teams in
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************

void loadComputerTeams(vector<Cteam> &computerTeams);
//*****************************************************************
//  Function:   loadComputerTeamNames
//  Purpose:    reads in computer teams from file and stores them in vector
//  Parameters: computerTeams - the vector to store the names in
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************

void saveUserTeams(vector<Hteam> &userTeams);
//*****************************************************************
//  Function:   saveUserTeams
//  Purpose:    writes all user based team data to disk
//  Parameters: userTeams - the vector that holds all of the user teams to save
//  Pre Conditions: userTeams contains the userTeams
//  Post Conditions: the data is saved to a file called userTeams.dat
//*****************************************************************

void saveComputerTeams(vector<Cteam> &computerTeams);
//*****************************************************************
//  Function:   saveComputerTeams
//  Purpose:    writes all computer based team data to disk
//  Parameters: computerTeams - the vector that holds all of the cpu teams to save
//  Pre Conditions: computerTeams contains all the cpu teams
//  Post Conditions: the data is saved to a file called computerTeams.dat
//*****************************************************************

int isAlreadyATeam(string teamName, vector<Hteam> &userTeams);
//*****************************************************************
//  Function:   isAlreadyATeam
//  Purpose:    determines whether teamName is already a Team
//  Parameters: teamName - the name to check for
//              userTeams - the vector of Hteams to check in
//  Pre Conditions: userTeams already contains all Hteams
//  Post Conditions: returns the index of the matching team, or -1 if not found
//*****************************************************************

void printAllUserTeams(vector<Hteam> &userTeams);
//*****************************************************************
//  Function:   printAllUserTeams
//  Purpose:    simply lists out all existing teams to aid in user selection
//  Parameters: userTeams - the vector containing all the team names to print
//  Pre Conditions: userTeams already holds the necessary teams
//  Post Conditions: does not return a value
//*****************************************************************

Hplayer createAHplayer();
//*****************************************************************
//  Function:   createAHplayer
//  Purpose:    gets input from user to create a new Hplayer
//  Parameters: none
//  Pre Conditions: none
//  Post Conditions: returns the Hplayer with stats given by user
//*****************************************************************

void printCreateAPlayerHelpMenu();
//*****************************************************************
//  Function:   printCreateAPlayerHelpMenu
//  Purpose:    displays what each attribute of a Hplayer's character respresents
//  Parameters: none
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

    bool returnToIntro = true;
    bool returnToCharacterName = true;

    string tempString; //used for data input
    int tempInt; //used for data input
    Hteam activeTeam; //the team that is currently in use
    Hplayer tempHplayer;

    while(returnToIntro){
        printBasicMenu(userTeams); //intro

        cin >> tempString;

        //need to see if team already exists
        tempInt = isAlreadyATeam(tempString, userTeams);
        if( tempInt == -1){
            cout << tempString << " does not appear to be a team yet." << endl;
            cout << "Would you like to start this team (y/n): ";
            cin >> tempString;

            if(tempString == "y" || tempString == "Y" || tempString == "yes" || tempString == "Yes"){
                returnToIntro = false;
                activeTeam.setTeamName(tempString);
                cout << "\nHow many players are on your team (including yourself): ";
                cin >> tempInt;
                //debug
                cout << activeTeam.getNumberOfPlayers();
                for(size_t i = 0; i < tempInt; i++){
                    //debug
                    cout << "i: " << i << endl;
                    bool b = (i < activeTeam.getNumberOfPlayers());
                    cout << "i < #Players: " << b << endl;
                    returnToCharacterName = true;
                    while(returnToCharacterName){
                        cout << "Please enter information for player " << i + 1 << " of your team." << endl;
                        if(activeTeam.addTeamMember(createAHplayer())){
                            returnToCharacterName = false;
                        }
                    }
                }
            }
            else{
                //they want to enter another team name, return them to main menu
            }
        }
        else{
            //continue using a current team
            activeTeam = userTeams[tempInt];
        }
    } //end of intro sequence, active Team should now be set and ready to move on




    return 0;
}

void printBasicMenu(vector<Hteam> &userTeams){
    cout << "######################################################" << endl;
    cout << "#  Super Smash Bros. Ultimate Season Generator       #" << endl;
    cout << "#                                                    #" << endl;
    cout << "#  By: OpenSkyze                                     #" << endl;
    cout << "######################################################" << endl;
    printAllUserTeams(userTeams);
    cout << "######################################################" << endl;
    cout << "#  Please enter your team name to begin:             #" << endl;
    cout << "######################################################" << endl << endl;
    cout << "Team Name: ";

}

void loadData(vector<Hteam> &userTeams, vector<Cteam> &computerTeams){
    loadUserTeams(userTeams);
    loadComputerTeams(computerTeams);
}

void loadUserTeams(vector<Hteam> &userTeams){
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

void loadComputerTeams(vector<Cteam> &computerTeams){
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

void saveUserTeams(vector<Hteam> &userTeams){
    ofstream outFile;
    outFile.open("userTeams.dat");
    for(size_t i = 0; i < userTeams.size(); i++){
        outFile << userTeams[i].getTeamName() << endl;
        outFile << userTeams[i].getNumberOfPlayers() << endl;
        outFile << userTeams[i].getWins() << endl;
        outFile << userTeams[i].getLosses() << endl;
        for(int j = 0; j < userTeams[i].getNumberOfPlayers(); j++){
            outFile << userTeams[i].getTeamMemberAtIndex(j).getUser() << endl;
            outFile << userTeams[i].getTeamMemberAtIndex(j).getFighter() << endl;
            outFile << userTeams[i].getTeamMemberAtIndex(j).getCharacter() << endl;
            outFile << userTeams[i].getTeamMemberAtIndex(j).getWins() << endl;
            outFile << userTeams[i].getTeamMemberAtIndex(j).getNumberOfMatchesPlayed() << endl;
            outFile << userTeams[i].getTeamMemberAtIndex(j).getKills() << endl;
            outFile << userTeams[i].getTeamMemberAtIndex(j).getDeaths() << endl;
            for(int k = 0; k < 103; k++){
                outFile << userTeams[i].getTeamMemberAtIndex(j).getStageDataAtIndex(k).getWins() << endl;
                outFile << userTeams[i].getTeamMemberAtIndex(j).getStageDataAtIndex(k).getNumberOfMatchesPlayed() << endl;
            }
        }
    }

    outFile.close();
}

void saveComputerTeams(vector<Cteam> &computerTeams){
    ofstream outFile;
    outFile.open("computerTeams.dat");
    for(size_t i = 0; i < computerTeams.size(); i++){
        outFile << computerTeams[i].getTeamName() << endl;
        outFile << computerTeams[i].getNumberOfPlayers() << endl;
        outFile << computerTeams[i].getWins() << endl;
        outFile << computerTeams[i].getLosses() << endl;
        for(int j = 0; j < computerTeams[i].getNumberOfPlayers(); j++){
            outFile << computerTeams[i].getTeamMemberAtIndex(j).getId() << endl;
            outFile << computerTeams[i].getTeamMemberAtIndex(j).getFighter() << endl;
            outFile << computerTeams[i].getTeamMemberAtIndex(j).getLevel() << endl;
            outFile << computerTeams[i].getTeamMemberAtIndex(j).getKills() << endl;
            outFile << computerTeams[i].getTeamMemberAtIndex(j).getDeaths() << endl;
        }
    }
}

int isAlreadyATeam(string teamName, vector<Hteam> &userTeams){
    for(size_t i = 0; i < userTeams.size(); i++){
        if(userTeams[i].getTeamName() == teamName){
            return i;
        }
    }
    return -1;
}

void printAllUserTeams(vector<Hteam> &userTeams){
    for(size_t i = 0; i < userTeams.size(); i++){
        cout << "# • " << userTeams[i].getTeamName();
        size_t spaces = 50 - userTeams[i].getTeamName().length();
        for(size_t j = 0; j < spaces; j++){
            cout << " ";
        }
        cout << "#" << endl;
    }
}

Hplayer createAHplayer(){
    printCreateAPlayerHelpMenu();
    Hplayer newPlayer;
    string s;

    cout << "\nUser: ";
    cin >> s;
    newPlayer.setUser(s);
    cout << "\nFighter: ";
    cin >> s;
    newPlayer.setFighter(s);
    cout << "\nCharacter: ";
    cin >> s;
    newPlayer.setCharacter(s);

    return newPlayer;

}

void printCreateAPlayerHelpMenu(){
    cout << "######################################################" << endl;
    cout << "#           Create A Player - Help Menu              #" << endl;
    cout << "######################################################" << endl;
    cout << "# User:      Human player's name                     #" << endl;
    cout << "# Fighter:   Which playable fighter will you use?    #" << endl;
    cout << "# Character: (UserName/Profile) of your character    #" << endl;
    cout << "######################################################" << endl;
}
