#include "Character.h"

Character::Character(std::string name, int hp, int dmg) : name(name), hp(hp), dmg(dmg) {

}

std::string Character::getName() const {
    return name;
}  

int Character::getHP() const {
  return hp; 
}

int Character::getDMG() const{
    return dmg;
}

void Character::DMG(Character* enemy) {
    hp-=enemy->getDMG(); 
    if (hp<0){
        hp=0;
    }
}   

std::string Character::toString() 
{
	return name + ": HP:" + std::to_string(hp) + ", DMG: " + std::to_string(dmg);
}


