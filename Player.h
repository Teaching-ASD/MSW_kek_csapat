#ifndef PLAYER_H
#define PLAYER_H


#include <string>

class Player
{
	
    const std::string name;
    int hp, dmg;

public:
	Player(std::string name, int hp, int dmg);
 
    std::string getName() const;
    int getHP() const;
    int getDMG() const;
    

    void DMG(Player* enemy);
    std::string toString();

    static Player* parseUnit(std::string input);
    static Player* parseUnit(std::istream& inputStream);

    
};



#endif
