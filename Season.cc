#include "Season.h"

Season::Season(){
    totalNumberOfTeams = 0;
    numberOfHumanTeams = 0;
}

void Season::makeNew(string activeTeamName){
    string s = activeTeamName + " Season";
    LPCSTR folderName = s.c_str();
    CreateDirectory(folderName, NULL); //this folder will hold the season data corresponding to the main team
                                       //including the computerTeams info


}

void Season::setTotalNumberOfTeams(int newTotalNumberOfTeams){
    totalNumberOfTeams = newTotalNumberOfTeams;
}

void Season::setNumberOfHumanTeams(int newNumberOfHumanTeams){
    numberOfHumanTeams = newNumberOfHumanTeams;
}

void Season::setNumberOfPlayersPerTeam(int newNumberOfPlayersPerTeam){
    numberOfPlayersPerTeam = newNumberOfPlayersPerTeam;
}

void Season::setBattleAmount(int newBattleAmount){
    battleAmount = newBattleAmount;
}

int Season::getTotalNumberOfTeams(){
    return totalNumberOfTeams;
}

int Season::getNumberOfHumanTeams(){
    return numberOfHumanTeams;
}

int Season::getNumberOfPlayersPerTeam(){
    return numberOfPlayersPerTeam;
}

int Season::getBattleAmount(){
    return battleAmount;
}

//helpers
int Season::getNumberOfComputerTeams(){
    return (totalNumberOfTeams - numberOfHumanTeams);
}

void Season::addHumanTeamByNameFrom(string teamName, vector<Hteam> &userTeams){
    vector<Hteam>::iterator it = userTeams.begin();
    while(it -> getTeamName() != teamName){
        cout << userTeams.size() << endl;
        cout << it -> getTeamName() << endl;
        it++;
        cout << it -> getTeamName() << endl;
    } //leaves iterator pointing at the correct team within userTeams
    activeHumanTeams.push_back(it);
}

void Season::setComputerTeams(vector<Cteam> &newComputerTeams){
    computerTeams = newComputerTeams;
}

void Season::generateMatchups(vector<string> &encodedOutput, vector<string> &stages){
    Match tempMatch;
    vector<Match> weeklyMatchups;
    stringstream sso;
    int tempInt1;
    int tempInt2;

    for(int i = 0; i < encodedOutput.size(); i++){//for each week
        weeklyMatchups.clear();
        sso.str("");            //start from scratch each iteration

        //store first line of match ups in stringstream
        sso << encodedOutput[i];
        for(int j = 0; j < encodedOutput.size()/2 + 1; j++){
            tempMatch.clearBothTeams(); //clear the teams from the match
            sso >> tempInt1;
            sso >> tempInt2;

            if(tempInt1 != 0 && tempInt2 != 0){//then its not a bye, place teams in match
                if(tempInt1 <= numberOfHumanTeams){
                    tempMatch.addHumanTeam(*activeHumanTeams[tempInt1 - 1]);
                }
                else{
                    tempMatch.addCpuTeam(computerTeams[tempInt1 - numberOfHumanTeams - 1]);
                }

                if(tempInt2 <= numberOfHumanTeams){
                    tempMatch.addHumanTeam(*activeHumanTeams[tempInt2 - 1]);
                }
                else{
                    tempMatch.addCpuTeam(computerTeams[tempInt2 - numberOfHumanTeams - 1]);
                }


                //now just need to set a stage for the match
                tempMatch.randomlySetStage(stages);

                //the match has been completed
                weeklyMatchups.push_back(tempMatch);
            }

        }

        //now the matches for the week are stored in weeklyMatchups
        matchups.push_back(weeklyMatchups);
    }
}

void Season::generateRestOfCpuTeams(vector<string> &fighters, vector<string> &idNames,
                                    vector<string> &adjectives, vector<string> &nouns)
{
    vector<Cteam> newComputerTeams;
    Cteam tempTeam;

    for(int i = 0; i < totalNumberOfTeams - numberOfHumanTeams; i++){
        tempTeam = generateRandomComputerTeam(numberOfPlayersPerTeam, fighters, idNames,adjectives, nouns);
        newComputerTeams.push_back(tempTeam);
    } //now newComputerTeams holds all the needed cpuTeams

    computerTeams = newComputerTeams;
}

void Season::printOutAllMatchups(){
    for(int i = 0; i < matchups.size(); i++){
        if(i < 9){
            cout << "********************************************************************************" << endl;
            cout << "*                            Week " << i + 1 << "                                            *" << endl;
            cout << "********************************************************************************" << endl;
        }
        else{ //if double digit then one less space 
            cout << "********************************************************************************" << endl;
            cout << "*                            Week " << i + 1 << "                                           *" << endl;
            cout << "********************************************************************************" << endl;
        }

        for(int j = 0; j < matchups[0].size(); j++){
            cout << "* ";
            matchups[i][j].printMatchup();
        }
    }
}

void Season::printOutAllMatchupsForWeek(int weekNum){
    int index = weekNum - 1;

    for(int j = 0; j < matchups[0].size(); j++){
        matchups[index][j].printMatchup();
    }

}

void Season::generateSchedule(vector<string> &stages){
    vector<int> topRow;
    vector<int> bottomRow;
    vector<string> encodedOutput;

    //need to fill encodedOutput with the correct amount of empty strings
    if(totalNumberOfTeams % 2 == 0){
        for(int i = 0; i < totalNumberOfTeams - 1; i++){
            encodedOutput.push_back("");
        }
    }
    else{
        for(int i = 0; i < totalNumberOfTeams; i++){
            encodedOutput.push_back("");
        }
    }


    //in case there is an even number of teams
    if(totalNumberOfTeams % 2 == 0){
        for(int i = 1; i <= totalNumberOfTeams/2; i++){
            topRow.push_back(i);
        }
        for(int i = totalNumberOfTeams/2 + 1; i <= totalNumberOfTeams; i++){
            bottomRow.push_back(i);
        }
    }
    else{ //there is an odd number
        for(int i = 1; i <= totalNumberOfTeams/2 + 1; i++){
            topRow.push_back(i);
        }
        for(int i = totalNumberOfTeams/2 + 2; i <= totalNumberOfTeams; i++){
            bottomRow.push_back(i);
        }
        //need the bye team
        bottomRow.push_back(0);
    }

    //the topRow and bottomRow appropriately filled
    fillCodedOutputWith(encodedOutput, topRow, bottomRow);
    //randomly switch around weeks so that each season isn't identical
    randomizeWeeklySchedule(encodedOutput);

    generateMatchups(encodedOutput, stages);

}

void Season::createAHTeam(string newTeamName, vector<Hteam> &userTeams, int numPlayers, bool newIsMainTeam){
    Hteam tempTeam;
    Hplayer tempPlayer;
    int userInput;

    tempTeam.setTeamName(newTeamName);
    tempTeam.setIsMainTeam(newIsMainTeam);
    if(numPlayers == 0){ //then the number of players is not restricted
        cout << "How many players are on your team: ";
        cin >> userInput;
        tempTeam.setNumberOfPlayers(userInput);
        cin.ignore(); //dont want the new line character from previous entry
    }
    else{ //the number of players has already been set
        tempTeam.setNumberOfPlayers(numPlayers);
    }

    for(int i = 0; i < tempTeam.getNumberOfPlayers(); i++){
        tempPlayer = createAHplayer();
        tempTeam.addTeamMember(tempPlayer);
    } //all team members have been added

    userTeams.push_back(tempTeam);
}

void Season::fillCodedOutputWith(vector<string> &encodedOutput, vector<int> &topRow, vector<int> &bottomRow){
    if(totalNumberOfTeams % 2 == 0){//there is an even amount of teams
        for(int i = 0; i < totalNumberOfTeams - 1; i++){ //for each week i
            for(size_t j = 0; j < topRow.size(); j++){ //each matchup j per week
                encodedOutput[i].append(to_string(topRow[j]));
                encodedOutput[i].append(" ");
                encodedOutput[i].append(to_string(bottomRow[j]));
                encodedOutput[i].append(" ");
            }
            //the string has been completed, so rotate the teams
            rotateRoundRobinTeams(topRow, bottomRow);
        }
    }
    else{
        for(int i = 0; i < totalNumberOfTeams; i++){ //need an extra week for the bye
            for(size_t j = 0; j < topRow.size(); j++){ //each matchup j per week
                encodedOutput[i].append(to_string(topRow[j]));
                encodedOutput[i].append(" ");
                encodedOutput[i].append(to_string(bottomRow[j]));
                encodedOutput[i].append(" ");
            }
            //the string has been completed, so rotate the teams
            rotateRoundRobinTeams(topRow, bottomRow);
        }
    }
}

void Season::rotateRoundRobinTeams(vector<int> &topRow, vector<int> &bottomRow){
    int holder = topRow[1];
    topRow[1] = bottomRow[0];

    for(size_t i = 2; i < topRow.size(); i++){
        swap(topRow[i], holder);
    } //top row has been fixed

    for(int i = (bottomRow.size() - 1); i >= 0; i--){ //type int is necessay so that overflow does not occur
        swap(bottomRow[i], holder);                   //note that this will create a compiler warning, but not an error
    }
}

void Season::randomizeWeeklySchedule(vector<string> &encodedOutput){
    int index1;
    int index2;
    for(int i = 0; i < totalNumberOfTeams; i++){
        index1 = rand() % encodedOutput.size();
        index2 = rand() % encodedOutput.size();
        swap(encodedOutput[index1], encodedOutput[index2]);
    }
}

Cplayer Season::generateRandomComputerPlayer(vector<string> &fighters, vector<string> &idNames){
    Cplayer tempPlayer;
    int randomNumber;

    randomNumber = rand() % idNames.size();
    tempPlayer.setId(idNames[randomNumber]);

    randomNumber = rand() % fighters.size();
    tempPlayer.setFighter(fighters[randomNumber]);

    randomNumber = (rand() % 9) + 1;
    tempPlayer.setLevel(randomNumber);

    return tempPlayer;

}

Cteam Season::generateRandomComputerTeam(int numberOfPlayers, vector<string> &fighters,
                                 vector<string> &idNames, vector<string> &adjectives,
                                 vector<string> &nouns)
{
        Cteam tempTeam;
        Cplayer tempPlayer;
        int rand1 = rand() % adjectives.size();
        int rand2 = rand() % nouns.size();

        tempTeam.setTeamName(adjectives[rand1] + " " + nouns[rand2]);
        tempTeam.setNumberOfPlayers(numberOfPlayers);

        for(int i = 0; i < numberOfPlayers; i++){
            tempPlayer = generateRandomComputerPlayer(fighters, idNames);
            tempTeam.addTeamMember(tempPlayer);
        }

        return tempTeam;
}

Hplayer Season::createAHplayer(){
    printCreateAPlayerHelpMenu();
    Hplayer newPlayer;
    string s;

    cout << "\nUser: ";
    getline(cin, s);
    newPlayer.setUser(s);
    cout << "\nFighter: ";
    getline(cin, s);
    newPlayer.setFighter(s);
    cout << "\nCharacter: ";
    getline(cin, s);
    newPlayer.setCharacter(s);

    return newPlayer;

}

void Season::printCreateAPlayerHelpMenu(){
    cout << "######################################################" << endl;
    cout << "#           Create A Player - Help Menu              #" << endl;
    cout << "######################################################" << endl;
    cout << "# User:      Human player's name                     #" << endl;
    cout << "# Fighter:   Which playable fighter will you use?    #" << endl;
    cout << "# Character: (UserName/Profile) of your character    #" << endl;
    cout << "######################################################" << endl;
}
