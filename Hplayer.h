//*****************************************************************
//
//  Program:     Hplayer header file
//
//  Author:      Joey Cunningham
//  Email:       jc402615@ohio.edu
//
//  Description: Hplayer is a human player and holds all necessary information
//               concerning the player's identity and statistics
//
//  Date:        Jan.06.19
//
//*****************************************************************

#ifndef HPLAYER_H
#define HPLAYER_H

#include <string>
#include "stageData.h"

using namespace std;

class Hplayer{
public:
    //constructors
    //default
    Hplayer();

    //getters
    string getUser();
    string getFighter();
    string getCharacter();
    int getWins();
    int getNumberOfMatchesPlayed();
    stageData getStageDataAtIndex(int index);

    //setters
    void setUser(string newUser);
    void setFighter(string newFighter);
    void setCharacter(string newCharacter);
    void setWins(int newWins);
    void setNumberOfMatchesPlayed(int newNumberOfMatchesPlayed);

    //helpers
    void increaseWins();
    void increaseNumberOfMatchesPlayed();
    int getLosses();
private:

    string user; // the actual human being who controls this character
    string fighter; //the playable character that the human being uses
    string character; //the fictional fighter, userName essentially.
                      //this is important for multiseason campaigns and
                      //tracking info for different characters that use
                      //the same fighter
    int wins; //quick access to the number of wins that a player has had
    int numberOfMatchesPlayed; //total number of matches that player has played
    // losses = numberOfMatchesPlayed - wins
    stageData stageStats[103]; //hold all data for stage statistics for Hplayer


};




#endif
