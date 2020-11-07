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

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
   
protected:   
        
    const std::string name; ///< This is the player name this is string variable
    int hp, dmg; ///< This is the player hp and dammage this is int variable
    double atksp; ///< This is the player cooldown this is double variable

public:
	Character(std::string name, int hp, int dmg, double atksp);

    ///This is a simple getters for getting the players name, hp, dmg, cooldown 
    /**
     * \return The Character name
    */
    std::string getName() const;
    /**
     * \return The Character hp
    */
    int getHealthPoints() const;
    /**
    * \return The Character dmg
    */
    int getDamage() const;
    /**
    * \return The Character cooldown
    */
    double getAttackCoolDown() const;

    bool isAlive() const;///< This isAlive metods,we can check that the enemy or hero is alive.

    int sufferDammage(Character& enemy/**< [in] this is enemy player parameter */);


};

#endif 