#include "Player.h"
#include <math.h>


Player::Player(std::string name, short hp, int dmg) : Character(name, hp, dmg), maxHp(hp) {

} 

void Player::increaseXP(){
    XP += dmg;
    if(XP>=LEVELUPBOUNDARY) levelUp();
}

std::string Player::toString(){
    return  Character::toString() + " XP : " + std::to_string(XP) + '\n';
}

void Player::levelUp(){

    while (XP>=100){
        XP-=100;
        hp = round(maxHp * 1.1);
        maxHp = hp;
        dmg = round(dmg*1.1);
    } 
}

