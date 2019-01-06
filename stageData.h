//*****************************************************************
//
//  Program:     stageData header file
//
//  Author:      Joey Cunningham
//  Email:       jc402615@ohio.edu
//
//  Description: stageData holds the information about stages for advanced
//               data tracking
//
//  Date:        Jan.06.19
//
//*****************************************************************

#ifndef STAGEDATA_H
#define STAGEDATA_H

#include <string>

using namespace std;

class stageData{
public:
    //constructors
    //default
    stageData(); //sets all values to empty, 0, or false as necessary
    stageData(string newName, bool newHasStrictEdges, bool newHasSevereHazards,
              int newWins, int newNumberOfMatchesPlayed);
    //getters
    string getName();
    bool getHasStrictEdges();
    bool getHasSevereHazards();
    int getWins();
    int getNumberOfMatchesPlayed();

    //setters;
    void setName(string newName);
    void setHasStrictEdges(bool newHasStrictEdges);
    void setHasSevereHazards(bool newHasSevereHazards);
    void setWins(int newWins);
    void setNumberOfMatchesPlayed(int newNumberOfMatchesPlayed);

    //helper functions
    void increaseWins(); //increments wins by one
    void increaseNumberOfMatchesPlayed(); //increments numberOfMatchesPlayed by one
    int getLosses();
private:

    string name; //name of the stage
    bool hasStrictEdges; //whether or not a stage has an edge that can be used for
                         //instant KOs without complete lauches
    bool hasSevereHazards; //whether or not the stage has hazards that can play
                           //a major outcome on the match
    int wins; //total wins that a player has had on a given stage
    int numberOfMatchesPlayed; //total matches that a player has played on a stage
    //losses = numberOfMatchesPlayed - wins


};



#endif
