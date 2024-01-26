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
