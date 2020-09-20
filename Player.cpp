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

void Player::DMG(Player* enemy) {
    short dmgHp=enemy->getHP()-dmg; 
    enemy->setHP(dmgHp);
    if (enemy->getHP()<0){
        enemy->setHP(0);
    }
}   



std::string Player::toString() 
{
	return name + ": HP:" + std::to_string(hp) + ", DMG: " + std::to_string(dmg);
}
