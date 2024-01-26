#ifndef HEROES_H
#define HEROES_H
#include "warriors.h"
#include <string>
#include <vector>

using namespace std;

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
#endif
