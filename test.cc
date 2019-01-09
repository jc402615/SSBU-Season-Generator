#include "stageData.h"
#include "Hplayer.h"
#include "Cplayer.h"
#include "Hteam.h"
#include "Cteam.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    cout << "Welcome to testing area!!" << endl << endl;
    /*
    stageData temp;
    cout << temp.getName() << endl;
    cout << temp.getHasStrictEdges() << endl;
    cout << temp.getHasSevereHazards() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;

    cout << "now setting" << endl;
    temp.setName("ImaStage");
    temp.setHasStrictEdges(true);
    temp.setHasSevereHazards(true);
    temp.setWins(21);
    temp.setNumberOfMatchesPlayed(100);

    cout << "now the stage looks like this" << endl;
    cout << temp.getName() << endl;
    cout << temp.getHasStrictEdges() << endl;
    cout << temp.getHasSevereHazards() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;
    cout << "losses: " << temp.getLosses() << endl;
    */

    //Hplayer Htemp;
    /*cout << "here is the fighter currently" << endl;
    cout << Htemp.getUser() << endl;
    cout << Htemp.getFighter() << endl;
    cout << temp.getCharacter() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;
    cout << temp.getLosses() << endl;
    cout << temp.getStageDataAtIndex(0).getWins() << endl << endl;
    */
   /*
    cout << "setting player" << endl;
    Htemp.setUser("Joey");
    Htemp.setFighter("Kirby");
    Htemp.setCharacter("JJ");
    Htemp.setWins(20);
    Htemp.setNumberOfMatchesPlayed(30);
    Htemp.setStageDataWins(0, 100);
    Htemp.increaseStageDataWins(0);
    */
/*
    cout << "now the player is " << endl << endl;
    cout << temp.getUser() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getCharacter() << endl;
    cout << temp.getWins() << endl;
    cout << temp.getNumberOfMatchesPlayed() << endl;
    cout << temp.getLosses() << endl;
    cout << temp.getStageDataAtIndex(0).getWins() << endl << endl;
    */

    /*
    Cplayer temp;
    cout << "the cplayer starts as" << endl;
    cout << temp.getId() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getLevel() << endl;
    cout << temp.getKills() << endl;
    cout << temp.getDeaths() << endl;

    cout << "setting the cplayer" << endl;
    temp.setId("Foxy Slayer");
    temp.setFighter("Fox");
    temp.setLevel(8);
    temp.setKills(10);
    temp.setDeaths(2);

    Cteam cpuTeam;
    cout << cpuTeam.getTeamName() << endl;
    cout << cpuTeam.getWins() << endl;
    cout << cpuTeam.getLosses() << endl;
    cpuTeam.printTeamMembers();
    cout << endl << cpuTeam.getNumberOfPlayers() << endl;

    cpuTeam.addTeamMember(temp);
    cpuTeam.addTeamMember(temp);
    cpuTeam.setTeamName("Compute and Destroy");
    cpuTeam.setWins(12);
    cpuTeam.setLosses(1);

    cout << "\n\n\n\n\nNow the team is" << endl;
    cout << cpuTeam.getTeamName() << endl;
    cout << cpuTeam.getWins() << endl;
    cout << cpuTeam.getLosses() << endl;
    cpuTeam.printTeamMembers();
    cout << endl << cpuTeam.getNumberOfPlayers() << endl;
    cpuTeam.printRecord();
    cout << endl;

    cout << "\n\n\n\n\ninfo about team member 2: " << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getId() << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getKills() << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getDeaths() << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getFighter() << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getLevel() << endl;

    cout << "changing team member data\n\n\n\n\n\n\n" << endl;
    cpuTeam.doubleIncreaseTeamMemberKillsAtIndex(1);
    cpuTeam.decreaseTeamMemberLevelAtIndex(1);
    cpuTeam.increaseTeamMemberDeathsAtIndex(1);

    cout << cpuTeam.getTeamMemberAtIndex(1).getId() << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getKills() << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getDeaths() << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getFighter() << endl;
    cout << cpuTeam.getTeamMemberAtIndex(1).getLevel() << endl;

/*

    cout << "the cplayer is now" << endl;
    cout << temp.getId() << endl;
    cout << temp.getFighter() << endl;
    cout << temp.getLevel() << endl;
    cout << temp.getKills() << endl;
    cout << temp.getDeaths() << endl;
*/

/*
    Hteam humanTeam;
    cout << "Hteam now" << endl;
    cout << humanTeam.getTeamName() << endl;
    cout << humanTeam.getNumberOfPlayers() << endl;
    cout << humanTeam.getWins() << endl;
    cout << humanTeam.getLosses() << endl << endl;

    cout << "setting now" << endl;
    humanTeam.setTeamName("Slayer Nation");
    humanTeam.setWins(10);
    humanTeam.setLosses(2);
    humanTeam.increaseWins();
    humanTeam.increaseLosses();
    humanTeam.addTeamMember(Htemp);
    humanTeam.addTeamMember(Htemp);

    cout << "now Hteam is" << endl;
    cout << humanTeam.getTeamName() << endl;
    cout << humanTeam.getNumberOfPlayers() << endl;
    cout << humanTeam.getWins() << endl;
    cout << humanTeam.getLosses() << endl << endl;
    humanTeam.printTeamMembers();
    cout << endl << endl << endl << endl;
    cout << humanTeam.getTeamMemberAtIndex(0).getCharacter() << endl;
    cout << humanTeam.getTeamMemberAtIndex(0).getFighter() << endl;
    cout << humanTeam.getTeamMemberAtIndex(0).getWins() << endl;
    humanTeam.getTeamMemberAtIndex(0).Hplayer::setWins(80);
    Htemp.setWins(777);
    cout << humanTeam.getTeamMemberAtIndex(0).getWins() << endl;
    cout << Htemp.getWins() << endl << endl << endl << endl << endl << endl;
    humanTeam.increaseTeamMemberWinsAtIndex(0);
    cout << humanTeam.getTeamMemberAtIndex(0).getWins();
    Hplayer copy = humanTeam.getTeamMemberAtIndex(0);
    cout << copy.getWins() << endl;
    cout << humanTeam.getTeamMemberAtIndex(0).getStageDataAtIndex(0).getWins();
    humanTeam.increaseTeamMemberStageDataWinsAtIndices(0,0);
    cout << humanTeam.getTeamMemberAtIndex(0).getStageDataAtIndex(0).getWins();
    */
   /*
    ifstream ins;
    ins.open("test.txt");
    bool tempBool = false;
    cout << "bool is currently " << tempBool << endl;
    ins >> tempBool;
    cout << "now bool is " << tempBool << endl;
    */
   Hplayer temp;
   Hteam tempTeam;
   tempTeam.addTeamMember(temp);
   cout << tempTeam.getNumberOfPlayers();
   temp.setCharacter("hey");
   tempTeam.addTeamMember(temp);
   cout << tempTeam.getNumberOfPlayers();
   return 0;

}
