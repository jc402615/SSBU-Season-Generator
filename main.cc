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

void printIntroMenu(); //?????
//*****************************************************************
//  Function:   printIntroMenu
//  Purpose:    prints out the
//  Parameters: none
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************

void loadData(vector<string> &teamNames);
//*****************************************************************
//  Function:   loadData
//  Purpose:    loads previous data from stored files
//  Parameters: teamNames - the vector to store the names in
//  Pre Conditions: the data files have not yet been accessed
//  Post Conditions: does not return a value
//*****************************************************************

void loadTeamNames(vector<string> &teamNames);
//*****************************************************************
//  Function:   loadTeamNames
//  Purpose:    reads in team names from file to and stores them in vector
//  Parameters: teamNames - the vector to store the names in
//  Pre Conditions: none
//  Post Conditions: does not return a value
//*****************************************************************
int main (){
    vector<string> teamNames; //stores teamNames
    //functions to read in all data types from stored files
    loadData(teamNames);
    cout << "the first team: " << teamNames[0];
    cout << "the second team is " << teamNames[1];

    return 0;
    system("CLS"); //clears the screen -- << flush; to clear iostream
    printBasicMenu(); //intro

    string tempString; //used for data input
    int tempInt; //used for data input
    cin >> tempString;

    //need to see if team already exis



    return 0;
}

void printBasicMenu(){
    cout << "#################################################" << endl;
    cout << "#  Super Smash Bros. Ultimate Season Generator  #" << endl;
    cout << "#                                               #" << endl;
    cout << "#  By: OpenSkyze                                #" << endl;
    cout << "#################################################" << endl;
    cout << "#  Please enter your team name to continue:     #" << endl;
    cout << "#################################################" << endl << endl;
    cout << "Team Name: ";

}

void loadData(vector<string> &teamNames){
    loadTeamNames(teamNames);
}

void loadTeamNames(vector<string> &teamNames){
    ifstream inFile;
    inFile.open("teamNames.dat");
    if(inFile.fail()){
        cout << "unable to locate teamNames.dat" << endl;
    }
    else{
        string temp;
        getline(inFile, temp); //priming read
        while(!inFile.eof()){ //read in all teams and add them to list
            teamNames.push_back(temp);
            getline(inFile, temp);
        }
        //all teams are now stored in teamNames
    }
    inFile.close();
}
