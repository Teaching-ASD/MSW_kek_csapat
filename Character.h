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
#include "Pos.h"



class Character {


public: 

    struct Damage {

        int physical=0;
        int magical=0;

        Damage(){};

        Damage(int p, int m) : physical(p), magical(m) {};

        Damage operator+(const Damage& other){ 
            physical+=other.physical; 
            magical+=other.magical;
            return *this;
        }

        void operator+=(const Damage& other){
            physical+=other.physical; 
            magical+=other.magical;
        }
    
        void operator*=(const Damage& other){
            physical *= other.physical; 
            magical *= other.magical;
        }

        Damage operator+(int num){
            physical+=num; 
            magical+=num;
            return *this;
        }

        void operator+=(int num){
            physical+=num; 
            magical+=num;
        }
    
        void operator*=(int num){
            physical *= num; 
            magical *= num;
        }

    };

protected:   


    const std::string name; ///< This is the player name this is string variable
    int hp; ///< This is the player hp and dammage this is int variable
    double atksp; ///< This is the player cooldown this is double variable
    int def;

    Pos* position;
    Damage* damage;
    std::string texture;


public:


	Character(const std::string& name, int hp, int pd, int md, double atksp, int def, std::string& texture);
    ~Character();

    ///This is a simple getters for getting the players name, hp, dmg, cooldown 
    /**
     * \return The Character name
    */
    std::string getName() const;
    /**
     * \return The Character hp
    */
    int getHealthPoints() const;

    int getPhysicalDamage() const;

    int getMagicalDamage() const;

    /**
    * \return The Character cooldown
    */
    double getAttackCoolDown() const;

    int getDef() const;

    bool isAlive() const;///< This isAlive metods, we can check that the opject is alive.
    int sufferDamage(const Character& enemy/**< [in] this return integer,what player have dammage to enemy */);
    
    void setPosition(int x, int y);
    int getPositionX() const;
    int getPositionY() const;

    std::string getTexture() const;
  

};

#endif //Character_H
