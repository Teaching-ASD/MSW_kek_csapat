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

     friend bool operator==(const Player& p1, const Player& p2);
    
};

inline bool operator==(const Player& p1, const Player& p2) {
    return (p1.name==p2.name && p1.hp==p2.hp && p1.dmg==p2.dmg);
}

#endif
