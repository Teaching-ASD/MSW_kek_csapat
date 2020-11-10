#include "Character.h"

Character::Character(const std::string& name, int hp, int dmg, double atksp) : name(name), hp(hp), dmg(dmg), atksp(atksp) {

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

int Character::sufferDammage(const Character& enemy) {
    int diff = hp-enemy.getDamage();
    if ( diff >= 0){
        hp-=enemy.getDamage();
        diff=enemy.getDamage();
    }
    else {
        diff = hp;
        hp=0;
    }
    return diff;
}







