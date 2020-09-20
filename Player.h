#ifndef PLAYER_H
#define PLAYER_H


#include <string>

class Player
{
	const std::string name;
	short hp;
	const unsigned short dmg;

public:
	Player(std::string name, short hp, unsigned short dmg);
    std::string getName() const;
    short getHP() const;
    unsigned short getDMG() const;
    void DMG(Player* enemy);
    std::string toString();


};

#endif
