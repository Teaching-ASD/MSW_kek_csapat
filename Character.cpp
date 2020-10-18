#include "Character.h"

Character::Character(std::string name, int hp, int dmg, double atksp) : name(name), hp(hp), dmg(dmg), atksp(atksp) {

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
  
double Character::getAtksp() const {
  return atksp;
}




