/**
 * \class Hero
 * 
 * \ingroup Example package
 *  
 * \brief Hero class
 * 
 * This is a Hero class. Hero inheritance from character. They have character field and xp, lvl and maxHp. They can do anything that character can do. Pluss they can fight and level up. 
 * \author smauzerrichard (smauzer.richard47@gmail.com)
 * \version 1.0
 * \date 2020-10-13
 * 
 */

#ifndef HERO_H
#define HERO_H


#include "Character.h"
#include "Monster.h"


class Hero : public Character {
    
    int xp = 0;
    int level = 1;
    int maxHp;
    int xpPerLev;
    int hpPerLev;
    int dmgPerLev;
    double cdPerLev;


public:
///This is a constuctor for Hero
    Hero(
    const std::string& name /**[in] this is a name parameter*/, 
    int hp/**[in] this is a hp parameter*/, 
    int dmg/**[in] this is a dmg parameter*/, 
    double atksp/**[in] this is a cooldown parameter*/,
    int xpPerLev,
    int hpPerLev,
    int dmgPerLev,
    double cdPerLev);


    void increaseXP(int diff);///<Hero increase xp while attack the another player.

    friend bool operator==(const Hero& p1/**[in] this is First Hero reference*/, const Hero& p2/**[in] this is Secound Hero reference*/); ///<Comparsion operator.

    void fightTilDeath(Monster& enemy/**< [in] The p2 as combat parameter */);
    
    static Hero parse(std::string json);

    int getLevel() const;
    int getMaxHealthPoints() const;


private:
    void levelUp();///< This is levelUp method. While players fight with each other and when someone win, they can lvl up.


};



#endif
