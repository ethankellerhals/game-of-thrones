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
