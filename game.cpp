#include "game.h"
#include "warriors.h"
#include "heroes.h"
#include "cities.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//ALL COMMENTS FOR ALGORITHMS IN PROJECT3.CPP

int Game::split(string str, char c) {
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
        	if (word.length() == 0) continue;
            //cout << word << endl;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j;
}

Game::Game() {

}

Game::Game(bool turn, int r, int c, int points, int money) {

}

int Game::readMapFile(string fileName) {
    ifstream file;
    file.open(fileName);
    char split = ',';
    string line;
    int i = 0;
    while (getline(file, line)) { //get line from file
        int j = 0;
        string item;
        stringstream ss; //parse the line
        ss << line;
        getline(ss, item, split); //split it based on the comma char
        map[i][j] = item;
        while (getline(ss, item, split)) {
            map[i][j] = item;
            j++;
        }
        i++;
    }
    file.close();
    return 0;
}

int Game::readHeroFile(string fileName) {
    ifstream file;
    file.open(fileName);
    char split = ',';
    string line;
    string name, ship;
    int money, influence, armySize, row, col;
    vector<Warrior> warriors;
    int i = 0;
    while (getline(file, line)) { //get line from file
        string item, item2, item3, item4, item5, item6, item7;
        stringstream ss;
        ss << line;
        getline(ss, item, split);
        name = item;
        int j = 0;
        while (j == 0) {
            getline(ss, item, split);
            money = stoi(item);
            j++;
        }
        while (j == 1) {
            getline(ss, item2, split);
            influence = stoi(item2);
            j++;
        }
        while (j == 2) {
            getline(ss, item3, split);
            armySize = stoi(item3);
            j++;
        }
        //j = 3
        int k = 0;
        while (k < 4) {
            getline(ss, item4, split);
            Warrior temp;
            // temp.setWarriorName(item4);
            // heroes[k].addHeroWarrior(temp); //will get a seg fault
            k++;
        }
        i++;
        while (j == 3) {
            getline(ss, item5, split);
            row = stoi(item5);
            j++;
        }
        while (j == 4) {
            getline(ss, item6, split);
            col = stoi(item6);
            j++;
        }
        while (j == 5) {
            getline(ss, item7, split);
            ship = item7;
            j++;
        }
        heroes.push_back(Hero(name, money, influence, armySize, (vector<Warrior>) warriors, row, col, ship));
    }
    file.close();
    return 0;
}

int Game::readWarriorFile(string fileName) {
    ifstream file;
    file.open(fileName);
    string warrior, free, ship, dragonGlass;
    int strength, loyalty, morale;
    char split = ',';
    string line = "";
    while (getline(file, line)) { //get line from file
        string item, item1, item2, item3, item4, item5, item6;
        stringstream ss; //parse the line
        ss << line;
        getline(ss, item, split); //split it based on the comma char
        warrior = item;
        int j = 0;
        while (j == 0) {
            getline(ss, item, split);
            strength = stoi(item);
            j++;
        }
        while (j == 1) {
            getline(ss, item2, split);
            loyalty = stoi(item2);
            j++;
        }
        while (j == 2) {
            getline(ss, item3, split);
            morale = stoi(item3);
            j++;
        }
        while (j == 3) {
            getline(ss, item4, split);
            free = item4;
            j++;
        }
        while (j == 4) {
            getline(ss, item5, split);
            ship = item5;
            j++;
        }
        while (j == 5) {
            getline(ss, item6, split);
            dragonGlass = item6;
            j++;
        }
        warriors.push_back(Warrior(warrior, strength, loyalty, morale, free, ship, dragonGlass));
    }
    file.close();
    return 0;
}

int Game::readCityFile(string fileName) {
    ifstream file;
    file.open(fileName);
    string line = "";
    while (getline(file, line)) { //get line from file
        string item, item2, item3, item4;
        stringstream ss;
        ss << line;
        getline(ss, item, ',');
        string letter = item;
        string name;
        int points, money, armySize;
        int j = 0;
        while (j == 0) {
            getline(ss, item, ',');
            name = item;
            j++;
        }
        while (j == 1) {
            getline(ss, item2, ',');
            money = stoi(item2);
            j++;
        }
        while (j == 2) {
            getline(ss, item3, ',');
            armySize = stoi(item3);
            j++;
        }
        while (j == 3) {
            getline(ss, item4, ',');
            points = stoi(item4);
            j++;
        }
        cities.push_back(City(letter, name, money, armySize, points));
    }
    file.close();
    return 0;
}

void Game::printMiniMap() {
    // cout << endl;
    // cout << "Here are " << playerHero.getHeroName() << "'s surroundings!" << endl;

    char water = '~';
    char land = '*';
    char outOfBounds = '#';
    int newRow = playerHero.getRow() - 4;
    int newCol = playerHero.getCol() - 5;

    //keep the player within bounds
    // if (newRow < 0) {
    //     newRow = 0;
    // }
    // else if (newRow > 25) {
    //     newRow = 25;
    // }
    // if (newCol < 0) {
    //     newCol = 0;
    // }
    // else if (newCol > 16) {
    //     newCol = 16;
    // }

    //map +- 3 for row and col, print around playerPosition
    string oneOne[row][col];

    for (int i = newRow; i < (newRow + 7); i++) {
        for (int j = newCol; j < (newCol + 7); j++) {
            oneOne[i][j] = map[i][j];
        }
    }

    cout << endl;

    for (int i = newRow; i < (newRow + 7); i++) {
        for (int j = newCol; j < (newCol + 7); j++) {
            if (i > row || i < 0) {
                cout << outOfBounds;
            }
            else if (j > col || j < 0) {
                cout << outOfBounds;
            }
            else {
                if (oneOne[i][j] == "w") {
                    cout << water;
                }
                else if (oneOne[i][j] == "p") {
                    cout << land;
                }
                else {
                    cout << oneOne[i][j];
                }
            }
        }
        cout << endl;
    }
}

bool Game::nextToHero() {
    bool nextTo = false;
    int row1, col1;
    int row2, col2;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j) {
                continue;
            }
            else {
                row1 = heroes[i].getRow();
                row2 = heroes[j].getRow();
                col1 = heroes[i].getCol();
                col2 = heroes[j].getCol();

                if ((row1 - row2) <= 2 && (row1 - row2) >= -2) {
                    if ((col1 - col2) <= 2 && (col1 - col2) >= -2) {
                        //need to be able to set the opoonent hero
                        nextTo = true;
                    }
                    else {
                        nextTo = false;
                    }
                }
                else {
                    nextTo = false;
                }
            }
        }
    }
    return nextTo;
}

string Game::getMap() {
    return map[row][col];
}

int Game::getPlayerPosition() {
    return playerHero.getHeroPosition();
}

void Game::setPlayerPosition(int r, int c) {
    playerHero.setHeroPosition(r, c);
}

string Game::getMapLocation(int r, int c) {
    return map[r][c];
}

void Game::setHero(int i) {
    i++;
    switch(i) {
        case 1:
            playerHero = heroes[0];
            break;
        case 2:
            playerHero = heroes[1];
            break;
        case 3:
            playerHero = heroes[2];
            break;
        case 4:
            playerHero = heroes[3];
            break;
        case 5:
            playerHero = heroes[4];
            break;
        case 6:
            playerHero = heroes[5];
            break;
    }
}

void Game::setOpponentHero() {
    if (nextToHero() == 1) {

    }
}

string Game::getPlayerName() {
    return playerName;
}

void Game::setPlayerName(string name) {
    playerName = name;
}

void Game::startGame() {
    string playerName;
    string choice;
    string heroChoice;
    string playerHeroChoice;
    int playerMoney;
    int playerInfluence;
    int playerArmySize;
    int playerRow, playerCol;


    cout << "Welcome to the Game of Thrones!" << endl;
    cout << "State your name, Your Grace: ";
    cin >> playerName;
    cout << endl;
    cout << "Would you like to choose a hero " << playerName << ", Your Grace? (Y/N): ";
    cin >> heroChoice;
    cout << endl;

    setPlayerName(playerName);

    if (heroChoice == "Y" || heroChoice == "y" || heroChoice == "yes" || heroChoice == "YES" || heroChoice == "Yes") {
        cout << "Select your hero using the numerical options:" << endl;
        cout << "1. Cersei Lannister" << endl;
        cout << "2. Stannis Baratheon" << endl;
        cout << "3. Jon Snow" << endl;
        cout << "4. Sansa Stark" << endl;
        cout << "5. Euron Greyjoy" << endl;
        cout << "6. Daenerys Targaryen" << endl;
        cout << "Hero: ";
        cin >> playerHeroChoice;
        bool badChoice = true;
        int playerChoice = stoi(playerHeroChoice);
        while (badChoice == true) {
            switch (playerChoice) {
                case 1:
                    cout << "You've chosen the Hero: Cersei Lannister!" << endl;
                    setHero(0);
                    //player = game.setHero(0);
                    //how to set main hero object equal to game hero object for player
                    badChoice = false;
                    break;
                case 2:
                    cout << "You've chosen the Hero: Stannis Baratheon!" << endl;
                    setHero(1);
                    badChoice = false;
                    break;
                case 3:
                    cout << "You've chosen the Hero: Jon Snow!" << endl;
                    setHero(2);
                    badChoice = false;
                    break;
                case 4:
                    cout << "You've chosen the Hero: Sansa Stark!" << endl;
                    setHero(3);
                    badChoice = false;
                    break;
                case 5:
                    cout << "You've chosen the Hero: Euron Greyjoy!" << endl;
                    setHero(4);
                    badChoice = false;
                    break;
                case 6:
                    cout << "You've chosen the Hero: Daenerys Targaryen!" << endl;
                    setHero(5);
                    badChoice = false;
                    break;
                default:
                    //fix this infinite loop
                    cout << "Error: Enter a number 1-6." << endl;
                    break;
            }
        }
    }
    else if (heroChoice == "N" || heroChoice == "n" || heroChoice == "no" || heroChoice == "NO" || heroChoice == "No") {
        heroes.push_back(playerHero);
        playerHero.setHeroName(playerName);
        cout << "Your Grace " << playerName << ", you have chosen to go on this journey ";
        cout << "alone. Please provide starting values for your adventure." << endl;
        cout << "Pick your starting values:" << endl;
        cout << "(Money, influence, and army size must be between 0-10000.)" << endl;
        cout << "Money: ";
        cin >> playerMoney;
        if ((playerMoney > 10000) || (playerMoney < 0)) { //need it to go back to asking for money if not in bounds
            cout << "Please enter a value between 0-10000." << endl;
        }
        else {
            playerHero.setHeroMoney(playerMoney);
        }
        cout << "Influence: ";
        cin >> playerInfluence;
        if ((playerInfluence > 10000) || (playerInfluence < 0)) {
            cout << "Please enter a value between 0-10000." << endl;
        }
        else {
            playerHero.setHeroInfluence(playerInfluence);
        }
        cout << "Army size: ";
        cin >> playerArmySize;
        if ((playerArmySize > 10000) || (playerArmySize < 0)) {
            cout << "Please enter a value between 0-10000." << endl;
        }
        else {
            playerHero.setHeroArmySize(playerArmySize);
        }
        cout << "Now choose your location ('x' must be between 1-16 and 'y' must be between 1-25)." << endl;
        cout << "X-coordinate: ";
        cin >> playerCol;
        if ((playerCol > 16) || (playerCol < 1)) {
            cout << "Please enter a value between 1-16." << endl;
        }
        else {
            playerHero.setCol(playerCol);
        }
        cout << "Y-coordinate: ";
        cin >> playerRow;
        if ((playerRow > 25) || (playerRow < 1)) {
            cout << "Please enter a value between 1-25." << endl;
        }
        else {
            playerHero.setRow(playerRow);
        }
        playerHero.setHeroShip("yes");
    }
}

void Game::playTurn() {

    string choice;
    cout << endl;
    cout << "Money: " << playerHero.getHeroMoney() << endl;
    cout << "Army size: " << playerHero.getHeroArmySize() << endl;
    cout << "Influence: " << playerHero.getHeroInfluence() << endl;
    cout << "Points: " << playerHero.getHeroPoints() << endl;
    printMiniMap();
    cout << endl;
    displayMenu();
    cout << "Choice: ";
    cin >> choice;

    int menuChoice = stoi(choice);
    string direction;
    const static int row = 25;
    const static int col = 16;
    bool badChoice = true;
    while (badChoice == true) { //try to prevent user error
        switch (menuChoice) {
            case 1:
                cout << "Which direction do you want to travel? (N/S/E/W): ";
                cin >> direction;

                if (direction == "N" || direction == "n" || direction == "north" || direction == "NORTH" || direction == "North") {
                    int checkPosition = playerHero.getRow() - 1; //check to see if it's out of bounds or not

                    //if statement might not work
                    if (checkPosition < 0) {
                        cout << "Error: player will be out of bounds. Choose again." << endl;
                        badChoice = true;
                    }
                    //not sure if this is the correct syntax, might need to use player.getHeroPosition()
                    //need the map array
                    else if (getMapLocation(checkPosition, playerHero.getCol()) == "w") { //if the user wants to go into the water, check for ship
                        if (playerHero.getHeroShip() == 1) {
                            playerHero.setHeroPosition(checkPosition, playerHero.getCol());

                        }
                        else {
                            cout << "Error: you are attempting to go onto water without a ship." << endl;
                            badChoice = true;
                        }
                    }
                    else {
                        playerHero.setHeroPosition(checkPosition, playerHero.getCol());

                    }
                }
                else if (direction == "S" || direction == "s" || direction == "south" || direction == "SOUTH" || direction == "South") {
                    int checkPosition = playerHero.getRow() + 1;
                    if (checkPosition > 25) {
                        cout << "Error: player will be out of bounds. Choose again." << endl;
                        badChoice = true;
                    }
                    //same thing as last else if
                    else if (getMapLocation(checkPosition, playerHero.getCol()) == "w") {
                        if (playerHero.getHeroShip() == 1) {
                            playerHero.setHeroPosition(checkPosition, playerHero.getCol());

                        }
                        else {
                            cout << "Error: you are attempting to go onto water without a ship." << endl;
                            badChoice = true;
                        }
                    }
                    else {
                        playerHero.setHeroPosition(checkPosition, playerHero.getCol());

                    }
                }
                else if (direction == "E" || direction == "e" || direction == "east" || direction == "EAST" || direction == "East") {
                    int checkPosition = playerHero.getCol() + 1;
                    //if statement might not work
                    if (checkPosition > 16) {
                        cout << "Error: player will be out of bounds. Choose again." << endl;
                        badChoice = true;
                    }
                    //samething as last else if
                    else if (getMapLocation(playerHero.getRow(), checkPosition) == "w") {
                        if (playerHero.getHeroShip() == 1) {
                            playerHero.setHeroPosition(playerHero.getRow(), checkPosition);
                            badChoice = false;
                        }
                        else {
                            cout << "Error: you are attempting to go onto water without a ship." << endl;
                            badChoice = true;
                        }
                    }
                    else {
                        playerHero.setHeroPosition(playerHero.getRow(), checkPosition);

                    }
                }
                else if (direction == "W" || direction == "w" || direction == "west" || direction == "WEST" || direction == "West") {
                    int checkPosition = playerHero.getCol() - 1;
                    //if statement might not work
                    if (checkPosition < 0) {
                        cout << "Error: player will be out of bounds. Choose again." << endl;
                        badChoice = true;
                    }
                    else if (getMapLocation(playerHero.getRow(), checkPosition) == "w") {
                        if (playerHero.getHeroShip() == 1) {
                            playerHero.setHeroPosition(playerHero.getRow(), checkPosition);

                        }
                        else {
                            cout << "Error: you are attempting to go onto water without a ship." << endl;
                            badChoice = true;
                        }
                    }
                    else {
                        playerHero.setHeroPosition(playerHero.getRow(), checkPosition);

                    }
                }
                else {
                    cout << "Error: enter a possible character/direction." << endl;
                    badChoice = true;
                }

                badChoice = false;
                break;
            case 2:
                for (int j = 0; j < playerHero.getNumWarriors(); j++) {
                    playerHero.setHeroWarriorStrength(playerHero.getHeroWarriorStrength(j) + 1, j);
                }
                break;
            case 3:
                if (playerHero.getNumWarriors() == 0) {
                    cout << "You have zero warriors and your position has not changed." << endl;
                    badChoice = false;
                }
                else {
                    for (int j = 0; j < playerHero.getNumWarriors(); j++) {
                        cout << "Your warrior(s) morale has increased by 1." << endl;
                        cout << playerHero.getHeroWarriorMoral(j) << endl;
                        playerHero.setHeroWarriorMoral(playerHero.getHeroWarriorMoral(j) + 1, j);
                        cout << playerHero.getHeroWarriorMoral(j) << endl;
                        badChoice = false;
                    }
                }
                break;
        }
    }
}

void Game::winterIsComing() {
    int event;
    srand(time(NULL));

    cout << "Winter is Coming!" << endl;

    event = rand() % 1 + 4;
    switch (event) {
        //loyalty and morale for the warrios cannot exceed 100
        //strength cannot exceed 200
        case 1: { //drought
            cout << "All your warriors morale and strength will decrease by 10!" << endl;
            for (int i = 0; i < playerHero.getNumWarriors(); i++) {
                playerHero.setHeroWarriorMoral(playerHero.getHeroWarriorMoral(i) - 10, i);
                playerHero.setHeroWarriorStrength(playerHero.getHeroWarriorStrength(i) - 10, i);
            }
            break;
        }
        case 2: {//deserters
            if ((playerHero.getHeroArmySize() - 10) < 0) {
                playerHero.setHeroArmySize(0);
            }
            else {
                playerHero.setHeroArmySize(playerHero.getHeroArmySize() - 10);
            }
            for (int i = 0; i < playerHero.getNumWarriors(); i++) {
                playerHero.setHeroWarriorLoyalty(playerHero.getHeroWarriorLoyalty(i) - 10, i);
            }
            break;
        }
        case 3: {//jackpot
            playerHero.setHeroMoney(playerHero.getHeroMoney() * 2);
            break;
        }
        case 4: { //kindness

            playerHero.setHeroArmySize(playerHero.getHeroArmySize() + 10);
            for (int i = 0; i < playerHero.getNumWarriors(); i++) {
                playerHero.setHeroWarriorLoyalty(playerHero.getHeroWarriorLoyalty(i) + 10, i);
            }
            break;
        }
    }
}

bool Game::whiteWalkers() {
    //cout << "Sad news! The White Walkers are approaching your location. Would you like to battle them now? (Y/N): "
    int heroPowerScore = playerHero.getHeroArmySize();
    bool battleWon = false;
    int battleCounter = 0;

    for (int i = 0; i < playerHero.getNumWarriors(); i++) {
        heroPowerScore += (playerHero.getHeroWarriorStrength(i) * (playerHero.getHeroWarriorMoral(i) / 50));
    }

    while (battleCounter < 3) {

    }
}

void Game::displayMenu() {
    cout << "Select a numerical option:" << endl;
    cout << "========Main Menu========" << endl;
    cout << "1. Travel" << endl;
    cout << "2. Rest" << endl;
    cout << "3. Consult with the gods" << endl;
}

void Game::heroEncounterMenu() {
    cout << "Select a numerical option:" << endl;
    cout << "========Hero Encounter========" << endl;
    cout << "1. Give a speech" << endl;
    cout << "2. Buy outright" << endl;
    cout << "3. Battle" << endl;
    cout << "4. Quit" << endl;
}

bool Game::heroEncounter() {

    heroEncounterMenu();

    string choice;
    bool encounterOver = false;
    bool gameOver = false;
    cout << "Choice: ";
    cin >> choice;

    int menuChoice = stoi(choice);

    while (encounterOver == false) {
        switch (menuChoice) {
            case 1: {
                int prob = (1 - (opponent.getHeroWarriorMoral(0) / 100) * (playerHero.getHeroInfluence() / 1600));

                if (prob <= 0) {
                    playerHero.setHeroInfluence(playerHero.getHeroInfluence() / 2);
                    encounterOver = true;
                }
                else {
                    cout << opponent.getHeroName() << " has retired." << endl;
                    playerHero.setHeroMoney(playerHero.getHeroMoney() + opponent.getHeroMoney());
                    playerHero.setHeroInfluence(playerHero.getHeroInfluence() + opponent.getHeroInfluence());
                    playerHero.setHeroArmySize(playerHero.getHeroArmySize() + opponent.getHeroArmySize());
                    //playerHero also gains opponents warriors
                    //heroes.erase();
                    encounterOver = true;
                }
                break;
            }
            case 2: {
                int prob = (1 - (opponent.getHeroWarriorLoyalty(0) / 100) * (playerHero.getHeroMoney() / 17800));

                if (prob <= 0) {
                    playerHero.setHeroMoney(playerHero.getHeroMoney() / 2);
                    encounterOver = true;
                }
                else {
                    cout << opponent.getHeroName() << " has retired." << endl;
                    playerHero.setHeroMoney(playerHero.getHeroMoney() + opponent.getHeroMoney());
                    playerHero.setHeroInfluence(playerHero.getHeroInfluence() + opponent.getHeroInfluence());
                    playerHero.setHeroArmySize(playerHero.getHeroArmySize() + opponent.getHeroArmySize());
                    //playerHero also gains opponents warriors
                    //heroes.erase();
                    encounterOver = true;
                }
                break;
            }
            case 3: {
                if (playerHero.getNumWarriors() == 0 && opponent.getNumWarriors() > 0) {
                    encounterOver = true;
                    gameOver = true;
                    return gameOver;
                }
                else if (opponent.getNumWarriors() == 0 && playerHero.getNumWarriors() > 0) {
                    cout << opponent.getHeroName() << " has retired." << endl;
                    playerHero.setHeroMoney(playerHero.getHeroMoney() + opponent.getHeroMoney());
                    playerHero.setHeroInfluence(playerHero.getHeroInfluence() + opponent.getHeroInfluence());
                    playerHero.setHeroArmySize(playerHero.getHeroArmySize() + opponent.getHeroArmySize());
                    //playerHero also gains opponents warriors
                    //heroes.erase();
                    encounterOver = true;
                }
                else if (opponent.getNumWarriors() > 1) {
                    //choose opponents warrior at random
                }
                else {
                    int playerValue = playerHero.getHeroArmySize() * playerHero.getHeroWarriorStrength(0);
                    int opponentValue = opponent.getHeroArmySize() * opponent.getHeroWarriorStrength(0);
                    if (playerValue > opponentValue) {
                        cout << opponent.getHeroName() << " has retired." << endl;
                        playerHero.setHeroMoney(playerHero.getHeroMoney() + opponent.getHeroMoney());
                        playerHero.setHeroInfluence(playerHero.getHeroInfluence() + opponent.getHeroInfluence());
                        playerHero.setHeroArmySize(playerHero.getHeroArmySize() + opponent.getHeroArmySize());
                        //playerHero also gains opponents warriors
                        //heroes.erase();
                        encounterOver = true;
                    }
                    else {
                        encounterOver = true;
                        gameOver = true;
                        return gameOver;
                    }
                }
                break;
            }
        }
    }
    return gameOver;
}

void Game::endOfGame() {
    //name, hero, number of points
    ofstream file;
    file.open("resultsGOT.txt");
    file << "<Name> | <Hero> | <Points> " << endl;
    file << getPlayerName() << " | " << playerHero.getHeroName() << " | " << playerHero.getHeroPoints() << endl;
}
