#include "Character.h"

Character::Character(std::string name, int hp, int dmg, double atksp) : name(name), hp(hp), dmg(dmg), atksp(atksp) {

}

std::string Character::getName() const {
    return name;
}  

int Character::getHealthPoints() const {
  return hp; 
}

int Character::getDamage() const{
    return dmg;
}
  
double Character::getAttackCoolDown() const {
  return atksp;
}

bool Character::isAlive() const{
    return hp > 0;
}









