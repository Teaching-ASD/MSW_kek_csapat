#include "Character.h"
#include "Player.h"
#include <fstream>
#include <sstream>

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


Player* Character::parseUnit(std::string fileName){


    std::ifstream inf;
    inf.exceptions(std::ifstream::failbit);
    inf.open(fileName);
    std::stringstream ss;

    char start_end;
    char sep;

    std::string type;

    std::string name, sHp, sDmg;
    int hp, dmg;

    if (inf.is_open()) {
      
      ss << inf.rdbuf();
      inf.close();

      ss >> start_end;
      //Read String
      ss >> type >> sep >> name;
      name.erase(name.begin(), name.begin()+1);
      name.erase(name.end()-2, name.end());
   

      //Read Integer
      ss >> type >> sep >> sHp;
      sHp.erase(sHp.end()-1);
      ss >> type >> sep >> sDmg;

      hp = std::stoi(sHp);
      dmg = std::stoi(sDmg);

      Player* p = new Player(name,hp,dmg);
      return p; 

    }
    else {
        return nullptr;
    }

}