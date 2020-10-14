#include "Player.h"
#include <fstream>
#include <sstream>

Player::Player(std::string name, int hp, int dmg, double atksp): name(name), hp(hp), dmg(dmg), atksp(atksp) {

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
//add attackspeed getters
double Player::getAtksp() const{
    return atksp;
}


void Player::DMG(Player* enemy) {
    this->hp-=enemy->getDMG(); 
    if (hp<0){
        hp=0;
    }
} 

Player* Player::parseUnit(std::string fileName){


    std::ifstream inf;
    inf.exceptions(std::ifstream::failbit);
    inf.open(fileName);
    std::stringstream ss;

    char start_end;
    char sep;

    std::string type;

    std::string name, sHp, sDmg, sAtksp;
    int hp, dmg;
    double atksp;

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
      //Floating point number
      ss >> type >> sep >> sAtksp;
      

      hp = std::stoi(sHp);
      dmg = std::stoi(sDmg);
      atksp = std::stod(sAtksp);

      Player* p = new Player(name,hp,dmg,atksp);
      return p;

    }
    else {
        return nullptr;
    }

}
