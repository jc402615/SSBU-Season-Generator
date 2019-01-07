//*****************************************************************
//
//  Program:     Cplayer header file
//
//  Author:      Joey Cunningham
//  Email:       jc402615@ohio.edu
//
//  Description: Cplayer is a computer player and holds all needed data to
//               set up the opponent character for a match
//
//  Date:        Jan.06.19
//
//*****************************************************************

#ifndef CPLAYER_H
#define CPLAYER_H

#include <string>

using namespace std;

class Cplayer{
public:
    //constructors
    //default
    Cplayer();
    Cplayer(string newId, string newFighter, int newLevel, int newKills,
            int newDeaths);

    //getters
    string getId();
    string getFighter();
    int getLevel();
    int getKills();
    int getDeaths();

    //setters
    void setId(string newId);
    void setFighter(string newFighter);
    void setLevel(int newLevel);
    void setKills(int newKills);
    void setDeaths(int newDeaths);

    //helpers
    void increaseLevel();
    void decreaseLevel();
    void increaseKills();
    void doubleIncreaseKills();
    void increaseDeaths();
private:
    string id; //this is to identify each CPU as seperate if desired
    string fighter; //the playable character
    int level; //level 1 to 9 of the character
    int kills; //kills by computer player
    int deaths; //deaths by computer player
};





#endif
