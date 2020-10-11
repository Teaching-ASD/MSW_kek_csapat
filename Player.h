#ifndef PLAYER_H
#define PLAYER_H


#include <string>

class Player
{
	
    const std::string name;
    int hp, dmg;
    float atksp;

public:
	Player(std::string name, int hp, int dmg, float atksp);
    
    //Getters
    std::string getName() const;
    short getHP() const;
    unsigned short getDMG() const;
    float getAtksp() const;
    //Functions
    void DMG(Player* enemy);
    std::string toString();

    //Static 
    static Player* parseUnit(std::string fileName);

};

#endif
