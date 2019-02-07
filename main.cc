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
#include <windows.h>     //used for creation of folders
#include <ctime> //used for seeding rand
#include <cmath> //used for exponent calculations
#include "stageData.h"
#include "Hplayer.h"
#include "Cplayer.h"
#include "Hteam.h"
#include "Cteam.h"
#include "Match.h"
#include "Season.h"


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
//  Parameters: userTeams - the vector to store Human Teams in
//              computerTeams - the vector to store cpu teams in
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

int isAlreadyAMainTeam(string teamName, vector<Hteam> &userTeams);
//*****************************************************************
//  Function:   isAlreadyAMainTeam
//  Purpose:    determines whether teamName is already a team with its own season
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

void printAllMainUserTeams(vector<Hteam> &userTeams);
//*****************************************************************
//  Function:   printAllMainUserTeams
//  Purpose:    simply lists out all existing teams that are the headers
//              of their own season
//  Parameters: userTeams - the vector containing all the team names to print
//  Pre Conditions: userTeams already holds the necessary teams
//  Post Conditions: does not return a value
//*****************************************************************

void saveData(vector<Hteam> &userTeams, vector<Cteam> &computerTeams);
//*****************************************************************
//  Function:   saveData
//  Purpose:    saves active data into stored files
//  Parameters: userTeams - the vector that holds all userTeams
//              computerTeams - the vector that holds all computerTeams
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************

void loadGenerationData(vector<string> &fighters, vector<string> &idNames,
                        vector<string> &adjectives, vector<string> &nouns,
                        vector<string> &stages);
//*****************************************************************
//  Function:   loadGenerationData
//  Purpose:    loads strings from files into the appropriate array
//  Parameters: fighters - holds the names of playable characters
//              idNames - holds the names of ids for cpu players
//              adjectives - for team name generation
//              nouns - for team name generation
//  Pre Conditions: files should be stored in the similarly named files .dat
//  Post Conditions: the vectors will be filled with all the data from the files
//*****************************************************************



int main (){
    srand(time(0)); //seeds random number generator
    //read in previous data from disk
    vector<Hteam> userTeams;
    vector<string> fighters;   //used for random team generation
    vector<string> idNames;    //used for random team generation
    vector<string> adjectives; //used for random team generation
    vector<string> nouns;      //used for random team generation
    vector<string> stages;     //used for random stageGeneration

    //functions to read in all data types from stored files
    loadUserTeams(userTeams);
    loadGenerationData(fighters, idNames, adjectives, nouns, stages);
    //end reading of data

    system("CLS"); //clears the screen -- << flush; to clear iostream

    bool returnToIntro = true;
    bool returnToCharacterName = true;

    string tempString; //used for data input
    string tempString2; //used for additional data input
    int tempInt; //used for data input
    Hteam activeTeam; //the team that is currently in use
    Hplayer tempHplayer;

    printBasicMenu(userTeams);
/*
    while(returnToIntro){
        printBasicMenu(userTeams); //intro

        cin >> tempString;


        //need to see if team already exists
        tempInt = isAlreadyATeam(tempString, userTeams);
        if( tempInt == -1){
            cout << tempString << " does not appear to be a team yet." << endl;
            cout << "Would you like to start this team (y/n): ";
            cin >> tempString2;

            if(tempString2 == "y" || tempString2 == "Y" || tempString2 == "yes" || tempString2 == "Yes"){
                returnToIntro = false;
                activeTeam.setTeamName(tempString);
                cout << "\nHow many players are on your team (including yourself): ";
                cin >> tempInt;
                for(size_t i = 0; i < tempInt; i++){
                    returnToCharacterName = true;
                    while(returnToCharacterName){
                        cout << "Please enter information for player " << i + 1 << " of your team." << endl;
                        if(activeTeam.addTeamMember(createAHplayer())){
                            activeTeam.increaseNumberOfPlayers();
                            returnToCharacterName = false;
                        }
                    }
                } //the team has been completed
                userTeams.push_back(activeTeam);
            }
            else{
                //they want to enter another team name, return them to main menu
            }
        }
        else{
            //continue using a current team
            returnToIntro = false;
            activeTeam = userTeams[tempInt];
        }
    } //end of intro sequence, active Team should now be set and ready to move on

*/
    //need season / matches
    //option to view stats / next match or all previous matches of the season
    //option to quit

    //print season menu
    // bunch of stars showing week of season and next match/stage/opponent including record
    //1. play match
    //2. view season standing/ stat page
    //3. view all time stats -> records page


    Season season;
    season.setTotalNumberOfTeams(30);
    season.setNumberOfHumanTeams(2);
    season.setNumberOfPlayersPerTeam(1);
    season.setBattleAmount(3);

    
    //season.createAHTeam("Slayers", userTeams, 1, true);

    season.addHumanTeamByNameFrom("Beetles", userTeams);
    season.addHumanTeamByNameFrom("1ers", userTeams);



    season.generateRestOfCpuTeams(fighters, idNames, adjectives, nouns);
    season.generateSchedule(stages);
    season.printOutAllMatchups();
    season.printOutAllMatchupsForWeek(3);

    cout << "\n\n\n\n\n\n";
    /*
    season.createAHTeam("Murder", userTeams);
    season.createAHTeam("Murder2", userTeams, 1, false);

    cout << userTeams[userTeams.size() - 1].getTeamName() << endl;
    cout << userTeams[userTeams.size() - 1].getNumberOfPlayers() << endl;
    cout << userTeams[userTeams.size() - 1].getIsMainTeam() << endl;
*/
    /*
    cin >> tempInt;
    cout << userTeams[userTeams.size() - 1].getTeamName() << endl;
    cout << userTeams[userTeams.size() - 1].getTeamMemberAtIndex(0).getUser() << endl;
    cout << userTeams[userTeams.size() - 1].getTeamMemberAtIndex(0).getFighter() << endl;
    cout << userTeams[userTeams.size() - 1].getTeamMemberAtIndex(0).getCharacter() << endl;
    cout << userTeams[userTeams.size() - 1].getTeamMemberAtIndex(1).getUser() << endl;
    cout << userTeams[userTeams.size() - 1].getTeamMemberAtIndex(1).getFighter() << endl;
    cout << userTeams[userTeams.size() - 1].getTeamMemberAtIndex(1).getCharacter() << endl;
    */
    saveUserTeams(userTeams);

    return 0;
} // end of main function

void printBasicMenu(vector<Hteam> &userTeams){
    cout << "######################################################" << endl;
    cout << "#  Super Smash Bros. Ultimate Season Generator       #" << endl;
    cout << "#                                                    #" << endl;
    cout << "#  By: OpenSkyze                                     #" << endl;
    cout << "######################################################" << endl;
    cout << "#                 Existing Teams                     #" << endl;
    cout << "######################################################" << endl;
    printAllMainUserTeams(userTeams);
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
        string tempString3;
        int tempInt;
        bool tempBool;
        Hplayer tempPlayer;
        Hteam tempTeam;

        getline(inFile, tempString); //priming read
        while(!inFile.eof()){ //read in all teams and add them to list
            //need to make sure the tempTeam teamMembers has been reset since
            //every other member variable will be overridden
            tempTeam.removeAllTeamMembers();
            tempTeam.setTeamName(tempString);
            inFile >> tempInt;
            tempTeam.setNumberOfPlayers(tempInt);
            inFile.ignore(); //ignore \n character
            inFile >> tempBool;
            tempTeam.setIsMainTeam(tempBool);
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
            //need to empty previous teamMembers
            tempTeam.removeAllTeamMembers();
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
        outFile << userTeams[i].getIsMainTeam() << endl;
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
    outFile.close();
}

int isAlreadyATeam(string teamName, vector<Hteam> &userTeams){
    for(size_t i = 0; i < userTeams.size(); i++){
        if(userTeams[i].getTeamName() == teamName){
            return i;
        }
    }
    return -1;
}

int isAlreadyAMainTeam(string teamName, vector<Hteam> &userTeams){
    for(size_t i = 0; i < userTeams.size(); i++){
        if(userTeams[i].getTeamName() == teamName && userTeams[i].getIsMainTeam() == true){
            return i;
        }
    }
    return -1;
}

void printAllUserTeams(vector<Hteam> &userTeams){
    for(size_t i = 0; i < userTeams.size(); i++){
        cout << "# - " << userTeams[i].getTeamName();
        size_t spaces = 49 - userTeams[i].getTeamName().length();
        for(size_t j = 0; j < spaces; j++){
            cout << " ";
        }
        cout << "#" << endl;
    }
}

void printAllMainUserTeams(vector<Hteam> &userTeams){
    for(size_t i = 0; i < userTeams.size(); i++){
        if(userTeams[i].getIsMainTeam()){
            cout << "# - " << userTeams[i].getTeamName();
            size_t spaces = 49 - userTeams[i].getTeamName().length();
            for(size_t j = 0; j < spaces; j++){
                cout << " ";
            }
            cout << "#" << endl;
        }
    }
}

void saveData(vector<Hteam> &userTeams, vector<Cteam> &computerTeams){
    saveUserTeams(userTeams);
    saveComputerTeams(computerTeams);
}

void loadGenerationData(vector<string> &fighters, vector<string> &idNames,
                        vector<string> &adjectives, vector<string> &nouns,
                        vector<string> &stages)
{
    ifstream inFile;
    string readingString;
    int ignoreNum;

    inFile.open("fighters.dat");
    if(inFile.fail()){
        cout << "Error, unable to locate \"fighters.dat\"" << endl;
    }
    getline(inFile, readingString);
    while(!inFile.eof()){
        fighters.push_back(readingString);
        getline(inFile, readingString);
    }
    inFile.close();

    inFile.open("idNames.dat");
    if(inFile.fail()){
        cout << "Error, unable to locate \"idNames.dat\"" << endl;
    }
    getline(inFile, readingString);
    while(!inFile.eof()){
        idNames.push_back(readingString);
        getline(inFile, readingString);
    }
    inFile.close();

    inFile.open("adjectives.dat");
    if(inFile.fail()){
        cout << "Error, unable to locate \"adjectives.dat\"" << endl;
    }
    getline(inFile, readingString);
    while(!inFile.eof()){
        adjectives.push_back(readingString);
        getline(inFile, readingString);
    }
    inFile.close();

    inFile.open("nouns.dat");
    if(inFile.fail()){
        cout << "Error, unable to locate \"nouns.dat\"" << endl;
    }
    getline(inFile, readingString);
    while(!inFile.eof()){
        nouns.push_back(readingString);
        getline(inFile, readingString);
    }
    inFile.close();

    inFile.open("stages.dat");
    if(inFile.fail()){
        cout << "Error, unable to locate \"stages.dat\"" << endl;
    }
    getline(inFile, readingString);
    while(!inFile.eof()){
        stages.push_back(readingString);
        inFile >> ignoreNum;
        inFile >> ignoreNum;    //ignore the three flags for stageData use
        inFile >> ignoreNum;
        inFile.ignore();        //ignore the extra newline character
        getline(inFile,readingString);
    }
    //each of the reference arrays should now be filled
}
