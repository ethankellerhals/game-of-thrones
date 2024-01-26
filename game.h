#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>

using namespace std;

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
#endif
