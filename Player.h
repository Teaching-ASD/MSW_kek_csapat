#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>

#define LEVELUPBOUNDARY 100

class Player : public Character {
    
    int XP = 0;
    int maxHp;

public:
    Player(std::string name, short hp, int dmg);
    void increaseXP();
    std::string toString();
private:
    void levelUp();

};

#endif
