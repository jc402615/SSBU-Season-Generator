#include "Match.h"
#include "iostream"

void Match::addHumanTeam(Hteam &humanTeam){
    humanTeams.push_back(humanTeam);
}

void Match::addCpuTeam(Cteam &cpuTeam){
    cpuTeams.push_back(cpuTeam);
}

void Match::clearBothTeams(){
    humanTeams.clear();
    cpuTeams.clear();
}

bool Match::isHumanMatch(){
    return (humanTeams.size() == 2);
}

bool Match::isCpuMatch(){
    return (cpuTeams.size() == 2);
}

bool Match::isMixedMatch(){
    return (humanTeams.size() == 1 && cpuTeams.size() == 1);
}

void Match::play(vector<Hteam> &userTeams, vector<Cteam> &cpuTeams){
    if(isHumanMatch()){
        //just need to collect data for both teams
        //update data & stage data for both teams
        //THIS PART OF THE FUNCTION WILL BE USED FOR MULTITEAM SEASONS IN THE FUTURE
    }
    else if(isMixedMatch()){
        vector<Hteam>::iterator humanIt; //used to walk through user team vector
        vector<Cteam>::iterator cpuIt;  //used to walk through cpu team vector
        int stageIndex; //need to know the index of the stage for setting human stage stats

        humanIt = userTeams.begin();
        cpuIt = cpuTeams.begin();
        while(humanIt -> getTeamName() != humanTeams[0].getTeamName()){
            humanIt++;
        } //this will leave humanIt pointing at the human team
        while(cpuIt -> getTeamName() != cpuTeams[0].getTeamName()){
            cpuIt++;
        } //this will leave cpuIt pointing at the cpu team
        stageIndex = 0;
        while(humanTeams[0].getTeamMemberAtIndex(0).getStageDataAtIndex(stageIndex).getName() != stageName){
            stageIndex++;
        } //stageIndex now matches the stage


        //get winner
        string userInput;
        int userInputInt;
        cout << "Were the " << humanTeams[0].getTeamName() << " successful? (y/n): ";
        cin >> userInput;

        if(userInput == "y" || userInput == "Y" || userInput == "yes" || userInput == "Yes"){
            //the human team won
            Hwinner = humanTeams[0];

            humanIt -> increaseWins();
            cpuIt -> increaseLosses();

            for(int a = 0; a < humanIt -> getNumberOfPlayers(); a++){
                humanIt -> increaseTeamMemberWinsAtIndex(a);
                humanIt -> increaseTeamMemberStageDataWinsAtIndices(a, stageIndex);
            }

        }
        else{ //may want to loop until user explicity enters y or n
            //the cpu team won
            Cwinner = cpuTeams[0];

            cpuIt -> increaseWins();
            humanIt -> increaseLosses();

        }

        //things to increase regardless of who wins

        //user team members
        for(int a = 0; a < humanIt -> getNumberOfPlayers(); a++){
            humanIt -> increaseTeamMemberNumberOfMatchesPlayedAtIndex(a);
            humanIt -> increaseTeamMemberStageDataNumberOfMatchesPlayed(a, stageIndex);
        }

        //now get kills and deaths
        cout << "\nPlease enter data from the match for each player: " << endl;
        for (int a = 0; a < humanIt -> getNumberOfPlayers(); a++){
            cout << "For " << humanIt -> getTeamMemberAtIndex(a).getCharacter() << " :" << endl;
            cout << "KO's: ";
            cin >> userInputInt;
            for(int b = 0; b < userInputInt; b++){
                humanIt -> increaseTeamMemberKillsAtIndex(0);
            }
            cout << "\nFalls: ";
            cin >> userInputInt;
            for(int b = 0; b < userInputInt; b++){
                humanIt -> increaseTeamMemberDeathsAtIndex(a);
            }
            cout << endl;
        }

        for (int a = 0; a < cpuIt -> getNumberOfPlayers(); a++){
            cout << "For " << cpuIt -> getTeamMemberAtIndex(a).getId() << " :" << endl;
            cout << "KO's: ";
            cin >> userInputInt;
            for(int b = 0; b < userInputInt; b++){
                cpuIt -> increaseTeamMemberKillsAtIndex(0);
            }
            cout << "\nFalls: ";
            cin >> userInputInt;
            for(int b = 0; b < userInputInt; b++){
                cpuIt -> increaseTeamMemberDeathsAtIndex(a);
            }
            cout << endl;
        }


    }
    else if(isCpuMatch()){
        //need to run a simulation of the match
    }
}

void Match::printWinner(){
    if(Hwinner.getTeamName() == "NO TEAM NAME"){
        //then a human team did not win
        cout << Cwinner.getTeamName();
    }
    else{
        //a human team must have won
        cout << Hwinner.getTeamName();
    }
}

void Match::setStageName(string newStageName){
    stageName = newStageName;
}
string Match::getStageName(){
    return stageName;
}
