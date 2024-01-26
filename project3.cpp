//Project 3 - Game of Thrones
//Ethan Kellerhals
//Punith
//C9: https://ide.c9.io/kellerhalseth/erk_csci1300
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

//NOT COMPLETE
//finish interface
//fix the minimap for hero 6
//figure out how to put warriors into vector after reading hero file
//hero battles
//need to be able to set the opoonent hero

class Warrior {
private:
    string warriorName;
    int warriorStrength;
    int warriorLoyalty;
    int warriorMoral;
    bool warriorFreedom;
    bool warriorShip;
    bool warriorDragonGlass;
public:
    Warrior();
    Warrior(string warrior, int strength, int loyalty, int morale, string free, string ship, string dragonGlass);
    string getWarriorName();
    void setWarriorName(string warrior);
    int getWarriorStrength();
    void setWarriorStrength(int strength);
    int getWarriorLoyalty();
    void setWarriorLoyalty(int loyalty);
    int getWarriorMoral();
    void setWarriorMoral(int morale);
    bool getWarriorFreedom();
    void setWarriorFreedom(string free);
    bool getWarriorShip();
    void setWarriorShip(string ship);
    bool getWarriorDragonGlass();
    void setWarriorDragonGlass(string dragonGlass);
};

class Hero {
private:
    string heroName;
    int heroMoney;
    int heroInfluence;
    int heroArmySize;
    vector<Warrior> heroWarriors;
    //vector<City> heroCity;
    bool heroShip;
    const static int row = 25;
    const static int col = 16;
    int rowPosition;
    int colPosition;
    int heroPosition[row][col];
    int heroWarriorMoral;
    int heroWarriorStrength;
    int heroWarriorLoyalty;
    int heroPoints;
public:
    Hero();
    Hero(string hero, int money, int influence, int armySize, vector<Warrior> currentWarriors, int yRow, int xCol, string ship); //ship might need to be bool
    string getHeroName();
    void setHeroName(string hero);
    int getHeroArmySize();
    void setHeroArmySize(int armySize);
    int getHeroInfluence();
    void setHeroInfluence(int influence);
    int getHeroMoney();
    void setHeroMoney(int money);
    void setHeroWarriors(vector<Warrior> warriors);
    // more
    int getHeroPosition();
    void setHeroPosition(int yRow, int xCol);
    int getNumWarriors();
    int getRow();
    void setRow(int yRow);
    int getCol();
    void setCol(int xCol);
    bool getHeroShip();
    void setHeroShip(string ship);

    //Your gonna want to to return a warrior here  I think
    Warrior getHeroWarrior(int i);
    int getHeroWarriorMoral(int i);
    int getHeroWarriorStrength(int i);
    int getHeroWarriorLoyalty(int i);
    void setHeroWarriorMoral(int warriorMoral, int index);
    void setHeroWarriorStrength(int warriorStrength, int index);
    void setHeroWarriorLoyalty(int warriorLoyalty, int index);
    int getHeroPoints();
    void addHeroWarrior(Warrior nWarrior);

};

class City {
private:
    string cityLetter;
    string cityName;
    int cityMoney;
    int cityArmySize;
    int cityPoints;
public:
    City();
    City(string letter, string name, int money, int armySize, int points);
    string getCityLetter();
    void setCityLetter(string letter);
    string getCityName();
    void setCityName(string name);
    int getCityMoney();
    void setCityMoney(int money);
    int getCityArmySize();
    void setCityArmySize(int armySize);
    int getCityPoints();
    void setCityPoints(int points);
};

class Game {
private:
    const static int row = 25;
    const static int col = 16;
    string map[row][col];
    vector<Hero> heroes;
    vector<City> cities;
    vector<Warrior> warriors;
    Hero playerHero;
    Hero opponent;
    string playerName;
public:
    Game();
    Game(bool turn, int r, int c, int points, int money);
    int readMapFile(string fileName);
    int readHeroFile(string fileName);
    int readWarriorFile(string fileName);
    int readCityFile(string fileName);
    //possibly adding more
    bool nextToHero();
    int split(string str, char c);
    void printMiniMap();
    string getMap();
    int getPlayerPosition();
    void setPlayerPosition(int r, int c);
    string getMapLocation(int r, int c);
    void setHero(int i);
    void playTurn();
    void winterIsComing();
    void startGame();
    void displayMenu();
    void heroEncounterMenu();
    bool heroEncounter();
    void endOfGame();
    string getPlayerName();
    void setPlayerName(string name);
    void setOpponentHero();
    bool whiteWalkers();
};

Hero::Hero() {
    heroName = "";
    heroMoney = 0;
    heroInfluence = 0;
    heroArmySize = 0;
    vector<Warrior> heroWarriors;
}

Hero::Hero(string hero, int money, int influence, int armySize, vector<Warrior> currentWarriors, int yRow, int xCol, string ship) {
    heroName = hero;
    heroMoney = money;
    heroInfluence = influence;
    heroArmySize = armySize;
    vector<Warrior> heroWarriors = (vector<Warrior>) currentWarriors;
    rowPosition = yRow;
    colPosition = xCol;
    if (ship == "no") {
        heroShip = false;
    }
    else {
        heroShip = true;
    }
}

string Hero::getHeroName() {
    return heroName;
}

void Hero::setHeroName(string hero) {
    heroName = hero;
}

int Hero::getHeroArmySize() {
    return heroArmySize;
}

void Hero::setHeroArmySize(int armySize) {
    heroArmySize = armySize;
}

int Hero::getHeroInfluence() {
    return heroInfluence;
}

void Hero::setHeroInfluence(int influence) {
    heroInfluence = influence;
}

int Hero::getHeroMoney() {
    return heroMoney;
}

void Hero::setHeroMoney(int money) {
    heroMoney = money;
}

Warrior Hero::getHeroWarrior(int index) {

    return heroWarriors[index];
}

int Hero::getHeroPosition() {
    return  heroPosition[rowPosition][colPosition];
}

void Hero::setHeroPosition(int yRow, int xCol) {
    rowPosition = yRow;
    colPosition = xCol;
}

int Hero::getNumWarriors() {
    int numWarriors;
    for (int i = 0; i < heroWarriors.size(); i++) {
        numWarriors++;
    }
    return numWarriors;
}

int Hero::getRow() {
    return rowPosition;
}

void Hero::setRow(int yRow) {
    rowPosition = yRow;
}

int Hero::getCol() {
    return colPosition;
}

void Hero::setCol(int xCol) {
    colPosition = xCol;
}

void Hero::setHeroShip(string ship) {
    if (ship == "no") {
        heroShip = false;
    }
    else {
        heroShip = true;
    }
}

bool Hero::getHeroShip() {
    return heroShip;
}

int Hero::getHeroWarriorMoral(int index) {
    return heroWarriors[index].getWarriorMoral();
}

int Hero::getHeroWarriorLoyalty(int index) {
    return heroWarriors[index].getWarriorLoyalty();
}

int Hero::getHeroWarriorStrength(int index) {
    return heroWarriors[index].getWarriorStrength();
}

void Hero::setHeroWarriorMoral(int warriorMoral, int index) {
    heroWarriorMoral = warriorMoral;
    heroWarriors[index].setWarriorMoral(heroWarriorMoral);
}

void Hero::setHeroWarriorLoyalty(int warriorLoyalty, int index) {
    heroWarriorLoyalty = warriorLoyalty;
    heroWarriors[index].setWarriorLoyalty(heroWarriorLoyalty);
}

void Hero::setHeroWarriorStrength(int warriorStrength, int index) {
    heroWarriorStrength = warriorStrength;
    heroWarriors[index].setWarriorStrength(heroWarriorStrength);
}

void Hero::addHeroWarrior(Warrior nWarrior){
    heroWarriors.push_back(nWarrior);
}

int Hero::getHeroPoints() {
    return heroPoints;
}

//Warrior
Warrior::Warrior() {
    warriorName = "";
    warriorStrength = 0;
    warriorLoyalty = 0;
    warriorMoral = 0;
}

Warrior::Warrior(string warrior, int strength, int loyalty, int morale, string free, string ship, string dragonGlass) {
    warriorName = warrior;
    warriorStrength = strength;
    warriorLoyalty = loyalty;
    warriorMoral = morale;

    if (free == "no") {
        warriorFreedom = false;
    }
    else {
        warriorFreedom = true;
    }
    if (ship == "no") {
        warriorShip = false;
    }
    else {
        warriorShip = true;
    }
    if (dragonGlass == "no") {
        warriorDragonGlass = false;
    }
    else {
        warriorDragonGlass = true;
    }
}

string Warrior::getWarriorName() {
    return warriorName;
}

void Warrior::setWarriorName(string warrior) {
    warriorName = warrior;
}

int Warrior::getWarriorStrength() {
    return warriorStrength;
}

void Warrior::setWarriorStrength(int strength) {
    warriorStrength = strength;
}

int Warrior::getWarriorLoyalty() {
    return warriorLoyalty;
}

void Warrior::setWarriorLoyalty(int loyalty) {
    warriorLoyalty = loyalty;
}

int Warrior::getWarriorMoral() {
    return warriorMoral;
}

void Warrior::setWarriorMoral(int morale) {
    warriorMoral = morale;
}

bool Warrior::getWarriorFreedom() {
    return warriorFreedom;
}

void Warrior::setWarriorFreedom(string free) {
    if (free == "no") {
        warriorFreedom = false;
    }
    else {
        warriorFreedom = true;
    }
}

City::City() {
    cityLetter = '\0';
    cityName = "";
    cityMoney = 0;
    cityArmySize = 0;
    cityPoints = 0;
}

City::City(string letter, string name, int money, int armySize, int points) {
    cityLetter = letter;
    cityName = name;
    cityMoney = money;
    cityArmySize = armySize;
    cityPoints = points;
}

string City::getCityLetter() {
    return cityLetter;
}

void City::setCityLetter(string letter) {
    cityLetter = letter;
}

string City::getCityName() {
    return cityName;
}

void City::setCityName(string name) {
    cityName = name;
}

int City::getCityMoney() {
    return cityMoney;
}

void City::setCityMoney(int money) {
    cityMoney = money;
}

int City::getCityArmySize() {
    return cityArmySize;
}

void City::setCityArmySize(int armySize) {
    cityArmySize = armySize;
}

int City::getCityPoints() {
    return cityPoints;
}

void City::setCityPoints(int points) {
    cityPoints = points;
}

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
            map[i][j] = item; //add all of the file info to map array in game class
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
        name = item; //set hero name
        int j = 0;
        //abusing getline
        while (j == 0) {
            getline(ss, item, split);
            money = stoi(item); //get hero money
            j++;
        }
        while (j == 1) {
            getline(ss, item2, split);
            influence = stoi(item2); //get hero influence
            j++;
        }
        while (j == 2) {
            getline(ss, item3, split);
            armySize = stoi(item3); //get hero army size
            j++;
        }
        //j = 3
        int k = 0;
        while (k < 4) {
            getline(ss, item4, split);
            Warrior temp;
            // temp.setWarriorName(item4);
            // heroes[k].addHeroWarrior(temp); //will get a seg fault, but should get hero's warriors
            k++;
        }
        i++;
        while (j == 3) {
            getline(ss, item5, split);
            row = stoi(item5); //get hero row
            j++;
        }
        while (j == 4) {
            getline(ss, item6, split);
            col = stoi(item6); //get hero col
            j++;
        }
        while (j == 5) {
            getline(ss, item7, split);
            ship = item7; //if has ship or not
            j++;
        }
        //add all of the information from file to vector
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
        //abusing getline
        while (j == 0) {
            getline(ss, item, split);
            strength = stoi(item); //get strength
            j++;
        }
        while (j == 1) {
            getline(ss, item2, split);
            loyalty = stoi(item2); //get loyalty, etc
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
        //add all of the file information to the warriors vector
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
        //abusing getline
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
        //add all of the file info to cities vector
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
    int newRow = playerHero.getRow() - 4; //get the row/col from the players location and set newRow
    int newCol = playerHero.getCol() - 5; //and newCol to the top left box of the 7x7 array

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

    for (int i = newRow; i < (newRow + 7); i++) { //copy the map from the file to the new minimap array
        for (int j = newCol; j < (newCol + 7); j++) {
            oneOne[i][j] = map[i][j];
        }
    }

    cout << endl;

    for (int i = newRow; i < (newRow + 7); i++) { //print out a 7x7 array
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
    return map[row-1][col-1];
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
    switch(i) { //depending on what the user chose, set that equal to the playerHero instance
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
    //trying to figure out how to set the opponent hero
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

    setPlayerName(playerName); //set playerName incase they want to create their own warrior

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
        while (badChoice == true) { //loop just incase user doesn't choose a number between 1-6
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
    //all setting playerHero getter/setters to whatever the user inputs
    else if (heroChoice == "N" || heroChoice == "n" || heroChoice == "no" || heroChoice == "NO" || heroChoice == "No") {
        heroes.push_back(playerHero); //will get a segfault
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
        if ((playerInfluence > 10000) || (playerInfluence < 0)) { //edge case for user error
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
    //one of the main functions of the program
    string choice;
    cout << endl;
    //output all the current stats and print the minimap/displayMenu
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
                    if (checkPosition < 0) { //check the position to make sure it's not out of bounds
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
                        playerHero.setHeroPosition(checkPosition, playerHero.getCol()); //set the new user position

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
                if (playerHero.getNumWarriors() == 0) { //check to see if player has any warriors
                    cout << "You have zero warriors and your position has not changed." << endl;
                    badChoice = false;
                }
                for (int j = 0; j < playerHero.getNumWarriors(); j++) {
                    cout << "Your warrior(s) strength has increased by 1." << endl;
                    playerHero.setHeroWarriorStrength(playerHero.getHeroWarriorStrength(j) + 1, j); //add one to all of the playerHero warrior strength
                    badChoice = false;
                }
                break;
            case 3:
                if (playerHero.getNumWarriors() == 0) {
                    cout << "You have zero warriors and your position has not changed." << endl;
                    badChoice = false;
                }
                else {
                    for (int j = 0; j < playerHero.getNumWarriors(); j++) { //add 1 to every hero warriors morale
                        cout << "Your warrior(s) morale has increased by 1." << endl;
                        playerHero.setHeroWarriorMoral(playerHero.getHeroWarriorMoral(j) + 1, j);
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
                playerHero.setHeroWarriorMoral(playerHero.getHeroWarriorMoral(i) - 10, i); //add 10 to hero warriors morale and strength
                playerHero.setHeroWarriorStrength(playerHero.getHeroWarriorStrength(i) - 10, i);
            }
            break;
        }
        case 2: {//deserters
            if ((playerHero.getHeroArmySize() - 10) < 0) { //check to see if player's army will be negative
                playerHero.setHeroArmySize(0);
            }
            else {
                playerHero.setHeroArmySize(playerHero.getHeroArmySize() - 10);
            }
            for (int i = 0; i < playerHero.getNumWarriors(); i++) {
                playerHero.setHeroWarriorLoyalty(playerHero.getHeroWarriorLoyalty(i) - 10, i); //subtract 10 from warrior loyalty
            }
            break;
        }
        case 3: {//jackpot
            playerHero.setHeroMoney(playerHero.getHeroMoney() * 2); //double player's money
            break;
        }
        case 4: { //kindness

            playerHero.setHeroArmySize(playerHero.getHeroArmySize() + 10);
            for (int i = 0; i < playerHero.getNumWarriors(); i++) {
                playerHero.setHeroWarriorLoyalty(playerHero.getHeroWarriorLoyalty(i) + 10, i); //add 10 to warrior loyalty
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
                //get the probability of the battle
                int prob = (1 - (opponent.getHeroWarriorMoral(0) / 100) * (playerHero.getHeroInfluence() / 1600));

                if (prob <= 0) { //if less than zero, player loses half their influence
                    playerHero.setHeroInfluence(playerHero.getHeroInfluence() / 2);
                    encounterOver = true;
                }
                else {
                    //if the player wins, add opponents money/influence/army
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
                //get the probability of the battle
                int prob = (1 - (opponent.getHeroWarriorLoyalty(0) / 100) * (playerHero.getHeroMoney() / 17800));

                if (prob <= 0) { //if less than zero, player loses half their money
                    playerHero.setHeroMoney(playerHero.getHeroMoney() / 2);
                    encounterOver = true;
                }
                else {
                    //if player wins
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
                if (playerHero.getNumWarriors() == 0 && opponent.getNumWarriors() > 0) { //if the player has zero and opponent has >= 1, player loses
                    encounterOver = true;
                    gameOver = true;
                    return gameOver;
                }
                else if (opponent.getNumWarriors() == 0 && playerHero.getNumWarriors() > 0) { //if opponent has zero warriors
                    //player gains opponents army/money/influence
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
                    int playerValue = playerHero.getHeroArmySize() * playerHero.getHeroWarriorStrength(0); //get player "strength"
                    int opponentValue = opponent.getHeroArmySize() * opponent.getHeroWarriorStrength(0); //get opponent "strength"
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
    //writes to file
    ofstream file;
    file.open("resultsGOT.txt");
    file << "<Name> | <Hero> | <Points> " << endl;
    file << getPlayerName() << " | " << playerHero.getHeroName() << " | " << playerHero.getHeroPoints() << endl;
}

int main() {
    Game game;
    int turnCount = 0;
    bool gameOver = false;

    game.readMapFile("mapGOT.txt");
    game.readCityFile("citiesGOT.txt");
    game.readWarriorFile("warriorsGOT.txt");
    game.readHeroFile("heroesGOT.txt");

    game.startGame();

    while (gameOver == false) {
        game.playTurn();
        turnCount++;
        if (turnCount == 12) {
            gameOver = true;
        }
        if (game.nextToHero() == 1) {
            game.heroEncounter();
            if (game.heroEncounter() == 1) {
                gameOver = true;
            }
        }
    }
    if (gameOver == true) {
        game.endOfGame();
    }
}
