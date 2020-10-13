#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
	
    const std::string name;
    int hp, dmg;
    double atksp;

public:
	Player(std::string name, int hp, int dmg, double atksp);
    
    //Getters
    std::string getName() const;
    short getHP() const;
    unsigned short getDMG() const;
    double getAtksp() const;
    //Functions
    void DMG(Player* enemy);
    std::string toString();

    //Static 
    static Player* parseUnit(std::string fileName);

};

#endif
