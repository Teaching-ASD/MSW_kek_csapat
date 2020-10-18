
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>


class Character {
   
protected:   
    const std::string name;
    int hp;
    int dmg;

public:
	Character(std::string name, int hp, int dmg);
    
    //Getters
    std::string getName() const;
    int getHP() const;
    int getDMG() const;
    
    //Functions
    void DMG(Character* enemy);
    std::string toString();
  
};

#endif