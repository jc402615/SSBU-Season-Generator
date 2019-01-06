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

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Hplayer{
public:

private:

    string user; // the actual human being who controls this character
    string fighter; //the playable character that the human being uses
    int wins; //quick access to the number of wins that a player has had
    int numberOfMatchesPlayed; //total number of matches that player has played
    // losses = numberOfMatchesPlayed - wins


};




#endif
