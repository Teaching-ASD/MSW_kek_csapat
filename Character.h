
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
     * \return The Hero's name
    */
    std::string getName() const;
    /**
     * \return The Hero's hp
    */
    int getHP() const;
    /**
    * \return The Hero's dmg
    */
    int getDMG() const;
    /**
    * \return The Hero's cooldown
    */
    double getAtksp() const;


  
};

#endif