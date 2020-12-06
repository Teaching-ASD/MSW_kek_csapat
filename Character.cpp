#include "Character.h"



Character::Character(const std::string& name, int hp,int pd, int md, double atksp, int def, std::string& texture) : 
name(name), 
hp(hp), 
atksp(atksp),
def(def), 
position(new Pos),
damage(new Damage(pd, md)),
texture(texture)
{
}

Character::~Character(){
    delete position;
    delete damage;
}

std::string Character::getName() const {
    return name;
}  

int Character::getHealthPoints() const {
  return hp; 
}

  
double Character::getAttackCoolDown() const {
  return atksp;
}

bool Character::isAlive() const{
    return hp > 0;
}

int Character::sufferDamage(const Character& enemy) {

    int diff = 0;
    int defDiff = 0;
    int enemyPDamage = enemy.damage->physical;
    int enemyMDamage = enemy.damage->magical;

    if(enemyPDamage>=def) defDiff=enemyPDamage-def; 

    diff = hp-(defDiff+enemyMDamage);
    if ( diff >= 0){
        hp-=(defDiff+enemyMDamage);
        diff=(defDiff+enemyMDamage);
    }
    else {
        diff = hp;
        hp=0;
    }
    return diff;
}

void Character::setPosition(int x, int y){
    position->set(x,y);
}

int Character::getPositionX() const{
    return position->getX();
}

int Character::getPositionY() const {
    return position->getY();
}

int Character::getPhysicalDamage() const {
    return damage->physical;
}

int Character::getMagicalDamage() const {
    return damage->magical;
}

int Character::getDef() const {
    return def;
}


std::string Character::getTexture() const{
    return texture;
}