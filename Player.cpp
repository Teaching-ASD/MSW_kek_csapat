#include "Player.h"


Player::Player(std::string name, short hp, unsigned short dmg): name(name), hp(hp), dmg(dmg) {

}

std::string Player::getName() const {
    return name;
}  

short Player::getHP() const {
  return hp; 
}

void Player::setHP(short newHP){
    hp=newHP;
}
    

unsigned short Player::getDMG() const{
    return dmg;
}
  