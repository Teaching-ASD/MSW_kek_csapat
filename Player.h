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

#include <string>

class Player
{
    const std::string name; ///< This is the player name this is string variable
    int hp, dmg; ///< This is the player hp and dammage this is int variable
    double atksp;  ///< This is the player cooldown this is double variable
    

public:
    ///This is a constuctor for Player
	Player(std::string name /**[in] this is a name parameter*/, int hp/**[in] this is a hp parameter*/, int dmg/**[in] this is a dmg parameter*/, double atksp/**[in] this is a cooldown parameter*/);
    
    ///This is a simple getters for getting the players name, hp, dmg, cooldown 
    /**
     * \return The Hero's name
    */
    std::string getName() const;
    /**
     * \return The Hero's hp
    */
    short getHP() const;
    /**
    * \return The Hero's dmg
    */
    unsigned short getDMG() const;
    /**
    * \return The Hero's cooldown
    */
    double getAtksp() const;
   
    static Player* parseUnit(std::string fileName/**< [in] Name of the file */);
    bool Combat(Player* p2);
    bool isEnd(Player* p2)const;

private:
    void sufferDammage(Player* enemy/**< [in] The enemy Player as parameter */);
};

#endif
