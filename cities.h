#ifndef CITIES_H
#define CITIES_H
#include <string>
#include <vector>

using namespace std;

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
#endif
