#ifndef WARRIORS_H
#define WARRIORS_H
#include <string>
#include <vector>

using namespace std;

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
#endif
