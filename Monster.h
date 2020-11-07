/**
 * \class Monster
 * 
 * \ingroup Example package
 *  
 * \brief Monster class
 * 
 * This is a Monster class. Monster have name, health, damage, and cooldown.
 * Monster is base class for RPG fight.
 * They can fight but they can't take experience.
 * More complex game features in the Player child class.
 * 
 * \author smauzerrichard (smauzer.richard47@gmail.com)
 * \version 1.0
 * \date 2020-10-13
 * 
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "Character.h"

class Monster : public Character {
   

public:

	Monster(
    std::string name, ///< This is the player name this is string variable
    int hp, ///< This is the player hp this is int variable
    int dmg, ///< This is the player dmg this is int variable
    double atksp) : Character(name, hp, dmg, atksp){}

    static Monster parse(std::string json/**< [in] Name of the json */);

  
};

#endif //Monster_H