#include "game.h"
#include "warriors.h"
#include "heroes.h"
#include "cities.h"
#include <iostream>
#include <vector>

using namespace std;

//ALL COMMENTS FOR ALGORITHMS IN PROJECT3.CPP

Hero::Hero() {
    heroName = "";
    heroMoney = 0;
    heroInfluence = 0;
    heroArmySize = 0;
    vector<Warrior> heroWarriors = {};
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

}
