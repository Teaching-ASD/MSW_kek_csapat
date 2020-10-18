/**
 * \class Player
 * 
 * \ingroup Example package
 *  
 * \brief Player class
 * 
 * This is a Player class. Player have name, health, damage, and cooldown.Every player has got own cooldown so it can change the fight end.
 * \author smauzerrichard (smauzer.richard47@gmail.com)
 * \version 1.0
 * \date 2020-10-13
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H


#include "Character.h"
#include <string>
#include <any>
#include <map>


#define LEVEL_BOUNDARY 100

class Player : public Character {
    
    int XP = 0;
    int level = 0;
    int maxHp;

public:
///This is a constuctor for Player
	Player(
    std::string name /**[in] this is a name parameter*/, 
    int hp/**[in] this is a hp parameter*/, 
    int dmg/**[in] this is a dmg parameter*/, 
    double atksp/**[in] this is a cooldown parameter*/);
    void increaseXP(int enemyHp);
    std::string getWinString();

    static Player* parseUnit(std::string input);
    static Player* parseUnit(std::istream& inputStream);

    friend bool operator==(const Player& p1, const Player& p2);


    bool Combat(Player* enemy/**< [in] The p2 as combat parameter */);
    bool isEnd(Player* enemy/**< [in] The p2 as isEnd parameter */)const;

private:
    void levelUp();
    static Player* parseHelper(std::map<std::string, std::any>& jdm);
    void sufferDammage(Player* enemy/**< [in] The enemy Player as parameter ,This is private parameter*/);
};

inline bool operator==(const Player& p1, const Player& p2) {
    return (p1.name==p2.name && p1.hp==p2.hp && p1.dmg==p2.dmg);
}

#endif
