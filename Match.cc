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

void Match::playStock(vector<Hteam> &userTeams, vector<Cteam> &computerTeams, int stockLives){
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
        cpuIt = computerTeams.begin();
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
        srand(time(0));
        //need to run a simulation of the match
        vector<Cteam>::iterator it1;
        vector<Cteam>::iterator it2;
        it1 = computerTeams.begin();
        it2 = computerTeams.begin();
        while(it1 -> getTeamName() != cpuTeams[0].getTeamName()){
            it1++;
        } //this will leave it1 pointing at the first cpu team
        while(it2 -> getTeamName() != cpuTeams[1].getTeamName()){
            it2++;
        } //this will leave it2 pointing at the second cpu team

        //step1 - determine which team won
        int maxKills = stockLives * cpuTeams[0].getNumberOfPlayers(); //used for kill distribution
        double probabilityOfWin = getProbabilityOfWinFor(cpuTeams[0]);
        int breakPoint = round(probabilityOfWin * 1000);
        int randomNum = (rand() % 1000) + 1;
        //debug
        cout << "begin showing random number within siumulation" << endl;
        cout << randomNum << endl;

        if(randomNum <= breakPoint){ //then cpuTeams[0] won
            Cwinner = cpuTeams[0];
            it1 -> increaseWins();
            it2 -> increaseLosses();

            //now need to distribute kills and deaths
            //kills
            int levelsOfTeam1 = 0;
            int levelsOfTeam2 = 0;
            for(int i = 0; i < cpuTeams[0].getNumberOfPlayers(); i++){
                levelsOfTeam1 += cpuTeams[0].getTeamMemberAtIndex(i).getLevel();
            }
            for(int i = 0; i < cpuTeams[1].getNumberOfPlayers(); i++){
                levelsOfTeam2 += cpuTeams[1].getTeamMemberAtIndex(i).getLevel();
            }

            //for winning team
            vector<int> breakPoints; //holds the values for each of the team members liklihood to get the kill
            breakPoints.push_back(cpuTeams[0].getTeamMemberAtIndex(0).getLevel());
            for(int i = 1; i < cpuTeams[0].getNumberOfPlayers(); i++){
                breakPoints.push_back(cpuTeams[0].getTeamMemberAtIndex(i).getLevel() + breakPoints[i - 1]);
            }

            int indexOfMember;
            for(int j = 0; j < maxKills; j++){ //need to distribute the max number of kills of the winning team
                indexOfMember = 0;
                randomNum = (rand() % levelsOfTeam1) + 1;
                //debug
                cout << randomNum << endl;
                while(randomNum > breakPoints[indexOfMember]){
                    indexOfMember++;
                }
                it1 -> increaseTeamMemberKillsAtIndex(indexOfMember);
            }

            //for losing team
            vector<int> breakPoints2;
            breakPoints2.push_back(cpuTeams[1].getTeamMemberAtIndex(0).getLevel());
            for(int i = 1; i < cpuTeams[1].getNumberOfPlayers(); i++){
                breakPoints2.push_back(cpuTeams[1].getTeamMemberAtIndex(i).getLevel() + breakPoints2[i - 1]);
            }

            int maxLosingKills = getNumberOfKillsForLosingTeam(maxKills, getProbabilityOfWinFor(cpuTeams[1]));
            for(int j = 0; j < maxLosingKills; j++){
                indexOfMember = 0;
                randomNum = (rand() % levelsOfTeam2) + 1;
                //debug
                cout << randomNum << endl;
                while(randomNum > breakPoints2[indexOfMember]){
                    indexOfMember++;
                }
                it2 -> increaseTeamMemberKillsAtIndex(indexOfMember);
            }
            //all kills have now been distributed

            //deaths
            //for losing team
            for(int i = 0; i < cpuTeams[1].getNumberOfPlayers(); i++){
                for(int j = 0; j < stockLives; j++){
                    it2 -> increaseTeamMemberDeathsAtIndex(i);
                }
            }

            //for winning team
            int maxLosingDeaths = maxLosingKills;
            vector<int> deathCounter;
            for(int i = 0; i < cpuTeams[0].getNumberOfPlayers(); i++){
                deathCounter.push_back(0);
            } //used to measure how many deaths each team member has been given so far

            vector<int> reverseBreakPoints;
            reverseBreakPoints.push_back(10 - cpuTeams[0].getTeamMemberAtIndex(0).getLevel());
            for(int i = 1; i < cpuTeams[0].getNumberOfPlayers(); i++){
                reverseBreakPoints.push_back(10 - cpuTeams[0].getTeamMemberAtIndex(i).getLevel() + reverseBreakPoints[i - 1]);
            } //reverseBreakPoints is now filled

            int totalOfReverseBreakPoints = 10 * cpuTeams[0].getNumberOfPlayers() - levelsOfTeam1;
            for(int i = 0; i < maxLosingDeaths; i++){
                bool retry = true;
                while(retry == true){
                    indexOfMember = 0;
                    randomNum = (rand() % totalOfReverseBreakPoints) + 1;
                    //debug
                    cout << randomNum << endl;
                    while(randomNum > reverseBreakPoints[indexOfMember]){
                        indexOfMember++;
                    }
                    if(deathCounter[indexOfMember] < stockLives){
                        it1 -> increaseTeamMemberDeathsAtIndex(indexOfMember);
                        deathCounter[indexOfMember]++;
                        retry = false;
                    }
                }

            } //all deaths and kills have been assigned appropriately

        }
        else{
            Cwinner = cpuTeams[1];
        }


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

double Match::getProbabilityOfWinFor(Cteam team){
    int levelsOfTeam1 = 0;
    int levelsOfTeam2 = 0;
    for(int i = 0; i < cpuTeams[0].getNumberOfPlayers(); i++){
        levelsOfTeam1 += cpuTeams[0].getTeamMemberAtIndex(i).getLevel();
    }
    for(int i = 0; i < cpuTeams[1].getNumberOfPlayers(); i++){
        levelsOfTeam2 += cpuTeams[1].getTeamMemberAtIndex(i).getLevel();
    }

    //need to know whether team is cpuTeams[0] or cpuTeams[1]
    if(team.getTeamName() == cpuTeams[0].getTeamName()){
        return ((pow(levelsOfTeam1,2))/((pow(levelsOfTeam1,2)) + pow(levelsOfTeam2,2)));
    }
    else if(team.getTeamName() == cpuTeams[1].getTeamName()){
        return ((pow(levelsOfTeam2,2))/((pow(levelsOfTeam1,2)) + pow(levelsOfTeam2,2)));
    }
    else{
        return -9999; //this should never happen
        cout << "error: invalid cpu teams in match" << endl;
    }
}

int Match::getNumberOfKillsForLosingTeam(int maxKills, double probabilityOfWin){
    int numberKills = round(((maxKills - 1) * 0.6) + (probabilityOfWin - 0.5));
    int randNum = (rand() % 6) + 1;
    //debug
    cout << "In get number of kills for losing team funciton" << endl;
    cout << randNum << endl;
    if(randNum == 1){
        numberKills--;
    }
    if(randNum == 6){
        numberKills++;
    }

    //check that numberKills is valid
    if(numberKills >= maxKills){
        numberKills = maxKills - 1;
    }
    if(numberKills < 0){
        numberKills = 0;
    }

    return numberKills;
}
