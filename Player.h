#ifndef PLAYER_H
#define PLAYER_H


#include <string>

class Player
{
	
    const std::string name;
    int hp, dmg;

public:
	Player(std::string name, int hp, int dmg);
    
    //Getters
    std::string getName() const;
    short getHP() const;
    unsigned short getDMG() const;
    
    //Functions
    void DMG(Player* enemy);
    std::string toString();

    //Static 
    static Player* parseUnit(std::string fileName);

};

#endif
