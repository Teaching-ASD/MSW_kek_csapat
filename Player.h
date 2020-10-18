#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>

#define LEVEL_BOUNDARY 100

class Player : public Character {
    
    int XP = 0;
    int level = 0;
    int maxHp;

public:
    Player(std::string name, int hp, int dmg);
    void increaseXP(int enemyHp);
    std::string getWinString();
    static Player* parseUnit(std::string fileName);
private:
    void levelUp();

};

#endif
