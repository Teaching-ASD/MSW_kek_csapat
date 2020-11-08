/**
 * \class Character
 * 
 * \ingroup Example package
 *  
 * \brief Character class
 * 
 * This is a Charater class. Character have name, health, damage, and cooldown.
 * Character is base class for RPG fight.
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
    const std::string& name,
    int hp, 
    int dmg, 
    double atksp) : Character(name, hp, dmg, atksp){}

    static Monster parse(const std::string& json);

  
};

#endif