/**
 * \class Player
 * 
 * \ingroup Example package
 *  
 * \brief Player class
 * 
 * This is a Player class. Player inheritance from character. They have character field and xp, lvl and maxHp. They can do anything that character can do. Pluss they can fight and level up. 
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
    void increaseXP(int enemyHp);///<Player increase xp while attack the another player.
    std::string getWinString();///<Get string if the player is win.

    static Player* parseUnit(std::string input);///<parserUnit data from json format string or file.
    static Player* parseUnit(std::istream& inputStream);///<parserUnit data from json format string or file or is string.

    friend bool operator==(const Player& p1/**[in] this is First Player reference*/, const Player& p2/**[in] this is Secound Player reference*/); ///<Comparsion operator.


    bool Combat(Player* enemy/**< [in] The p2 as combat parameter */);
    bool isEnd(Player* enemy/**< [in] The p2 as isEnd parameter */)const;

private:
    void levelUp();///< This is levelUp method. While players fight with each other and when someone win, they can lvl up.
    static Player* parseHelper(std::map<std::string, std::any>& jdm);///<Help code redundance.
    void sufferDammage(Player* enemy/**< [in] The enemy Player as parameter ,This is private parameter*/);
};

inline bool operator==(const Player& p1/**[in] this is First Player reference*/, const Player& p2/**[in] this is Secound Player reference*/)///<Comparsion operator.
{ 
    return (p1.name==p2.name && p1.hp==p2.hp && p1.dmg==p2.dmg);///<return player compersion.
}

#endif
