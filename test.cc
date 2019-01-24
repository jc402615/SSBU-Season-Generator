#include "stageData.h"
#include "Hplayer.h"
#include "Cplayer.h"
#include "Hteam.h"
#include "Cteam.h"
#include "Match.h"
#include "Season.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

void printOdds();

void printKills();

int main(){
    cout << "Welcome to testing area!!" << endl << endl;
    srand(time(0));

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
   /*
   Hplayer temp;
   Hteam tempTeam;
   tempTeam.addTeamMember(temp);
   cout << tempTeam.getNumberOfPlayers();
   temp.setCharacter("hey");
   tempTeam.addTeamMember(temp);
   cout << tempTeam.getNumberOfPlayers();
   */

   // this is for match testing
   vector<Hteam> userTeams;
   vector<Cteam> computerTeams;
   Hteam tempTeam;
   Hteam tempTeam2;
   Cteam CtempTeam;
   Cteam CtempTeam2;
   Cplayer tempCPlayer;
   Hplayer tempHPlayer;
   Match match;

/*
   tempHPlayer.setUser("Joey");
   tempHPlayer.setFighter("Kirby");
   tempHPlayer.setCharacter("JJ");
   tempTeam.addTeamMember(tempHPlayer);
   tempHPlayer.setUser("Jenna");
   tempHPlayer.setFighter("Zelda");
   tempHPlayer.setCharacter("Quackers");
   tempTeam.addTeamMember(tempHPlayer);
   tempTeam.setNumberOfPlayers(2);
   tempTeam.setTeamName("Killers");

   tempHPlayer.setUser("JOE");
   tempHPlayer.setFighter("Yoshi");
   tempHPlayer.setCharacter("RE4");
   tempTeam2.addTeamMember(tempHPlayer);
   tempHPlayer.setUser("Jonny");
   tempHPlayer.setFighter("Fox");
   tempHPlayer.setCharacter("JOnBoy");
   tempTeam2.addTeamMember(tempHPlayer);
   tempTeam2.setNumberOfPlayers(2);
   tempTeam2.setTeamName("Other Guys");
*/

   tempCPlayer.setId("Foxy Fighter");
   tempCPlayer.setLevel(7);
   tempCPlayer.setFighter("Fox");

   CtempTeam.setNumberOfPlayers(2);
   CtempTeam.addTeamMember(tempCPlayer);
   CtempTeam.addTeamMember(tempCPlayer);
   CtempTeam.setTeamName("Silver Foxes");

   tempCPlayer.setId("Flying Bird");
   tempCPlayer.setLevel(5);
   tempCPlayer.setFighter("Falco");

   CtempTeam2.setNumberOfPlayers(2);
   CtempTeam2.addTeamMember(tempCPlayer);
   CtempTeam2.addTeamMember(tempCPlayer);
   CtempTeam2.setTeamName("Flying Birds");

  // match.addHumanTeam(tempTeam);
   //match.addHumanTeam(tempTeam2);
   match.addCpuTeam(CtempTeam);
   match.addCpuTeam(CtempTeam2);
   match.setStageName("Battlefield");

   cout << "is this match human: " << match.isHumanMatch() << endl;
   cout << "is cpu match only: " << match.isCpuMatch() << endl;
   cout << "is mixed match: " << match.isMixedMatch() << endl;


   //userTeams.push_back(tempTeam);
   //userTeams.push_back(tempTeam2);
   computerTeams.push_back(CtempTeam);
   computerTeams.push_back(CtempTeam2);
   match.playStock(userTeams, computerTeams,6);

   cout << "\n\n\n\n\n\nThese are the teams in the array now: " << endl;
/*
   cout << "human team 1: " << endl;
   cout << userTeams[0].getWins() << endl;
   cout << userTeams[0].getLosses() << endl;
   cout << "for player1: " << endl;
   cout << userTeams[0].getTeamMemberAtIndex(0).getWins() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(0).getNumberOfMatchesPlayed() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(0).getKills() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(0).getDeaths() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(0).getStageDataAtIndex(0).getName() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(0).getStageDataAtIndex(0).getWins() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(0).getStageDataAtIndex(0).getNumberOfMatchesPlayed() << endl;
   cout << "for player2: " << endl;
   cout << userTeams[0].getTeamMemberAtIndex(1).getWins() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(1).getNumberOfMatchesPlayed() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(1).getKills() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(1).getDeaths() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(1).getStageDataAtIndex(0).getName() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(1).getStageDataAtIndex(0).getWins() << endl;
   cout << userTeams[0].getTeamMemberAtIndex(1).getStageDataAtIndex(0).getNumberOfMatchesPlayed() << endl;


   cout << "human team 2: " << endl;
   cout << userTeams[1].getWins() << endl;
   cout << userTeams[1].getLosses() << endl;
   cout << "for player1: " << endl;
   cout << userTeams[1].getTeamMemberAtIndex(0).getWins() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(0).getNumberOfMatchesPlayed() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(0).getKills() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(0).getDeaths() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(0).getStageDataAtIndex(0).getName() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(0).getStageDataAtIndex(0).getWins() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(0).getStageDataAtIndex(0).getNumberOfMatchesPlayed() << endl;
   cout << "for player2: " << endl;
   cout << userTeams[1].getTeamMemberAtIndex(1).getWins() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(1).getNumberOfMatchesPlayed() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(1).getKills() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(1).getDeaths() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(1).getStageDataAtIndex(0).getName() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(1).getStageDataAtIndex(0).getWins() << endl;
   cout << userTeams[1].getTeamMemberAtIndex(1).getStageDataAtIndex(0).getNumberOfMatchesPlayed() << endl;
   */

   cout << "\n\n\n\nhere is the cpu team: " << endl;
   cout << computerTeams[0].getWins() << endl;
   cout << computerTeams[0].getLosses() << endl;
   cout << computerTeams[0].getTeamMemberAtIndex(0).getKills() << endl;
   cout << computerTeams[0].getTeamMemberAtIndex(0).getDeaths() << endl;
   cout << computerTeams[0].getTeamMemberAtIndex(1).getKills() << endl;
   cout << computerTeams[0].getTeamMemberAtIndex(1).getDeaths() << endl;

   cout << "\n\n\n\nhere is the second cpu team: " << endl;
   cout << computerTeams[1].getWins() << endl;
   cout << computerTeams[1].getLosses() << endl;
   cout << computerTeams[1].getTeamMemberAtIndex(0).getKills() << endl;
   cout << computerTeams[1].getTeamMemberAtIndex(0).getDeaths() << endl;
   cout << computerTeams[1].getTeamMemberAtIndex(1).getKills() << endl;
   cout << computerTeams[1].getTeamMemberAtIndex(1).getDeaths() << endl;

   match.printWinner();

   cout << "testing round robin generation" << endl;
   Season season;
   season.setTotalNumberOfTeams(10);
   vector<string> tester = season.generateSchedule();
   for(int i  = 0; i < tester.size(); i++){
       cout << "here is string " << i << endl;
       cout << tester[i] << endl;
   }

/*
   cout << "\n\n\n\n\n\n\n Stringstream testing" << endl;
   int output;
   stringstream strStream;

   for(int i = 0; i < tester.size(); i++){
       strStream << tester[i];
       for(int j = 0; j < 10; j++){
           strStream >> output;
           cout << output << " ";
       }
       cout << endl;
   }
*/
   return 0;

}

void printOdds(){
    cout << "     1     2     3     4     5     6     7     8     9" << endl;
    for(double i = 1; i < 10; i++){
        cout << i << "   ";
        for(double j = 1; j < 10; j++){
            cout << setw(4) << setprecision(3) << (((i*i)/(i*i + j*j))*100) << "%   ";
        }
        cout << endl;
    }
}

void printKills(){
    cout << "      1      2      3      4      5      6      7      8      9" << endl;
    for(double i = 1; i < 10; i++){
        cout << i << "   ";
        for(double j = 1; j < 10; j++){
            cout << setw(4) << setprecision(3) <<  round(5 * (0.1 + (((i*i)/(i*i + j*j))))) << "   ";
        }
        cout << endl;
    }
}
