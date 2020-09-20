#include "Player.h"


Player::Player(std::string name, short hp, unsigned short dmg): name(name), hp(hp), dmg(dmg) {

}

std::string Player::getName() const {
    return name;
}  

short Player::getHP() const {
  return hp; 
}

unsigned short Player::getDMG() const{
    return dmg;
}

void Player::DMG(Player* enemy) {
    hp-=enemy->getDMG(); 
    if (hp<0){
        hp=0;
    }
}   



std::string Player::toString() 
{
	return name + ": HP:" + std::to_string(hp) + ", DMG: " + std::to_string(dmg);
}

