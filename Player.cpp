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

void Player::sufferDammage(Player* enemy) {
    this->hp-=enemy->getDMG(); 
    if (hp<0){
        hp=0;
    }
}

bool Player::Combat(Player* p2){

        p2->sufferDammage(this);
        sufferDammage(p2);
        

        float CD1=atksp;
        float CD2=p2->getAtksp();

    while(!isEnd(p2)){
        if(CD1==CD2){
            p2->sufferDammage(this);
            sufferDammage(p2);
            
            CD1=atksp;
            CD2=p2->getAtksp();          
        }
        if(CD1<CD2){
            CD2-=CD1;
            p2->sufferDammage(this);
            
            CD1=atksp;
            }
        else if(CD2<CD1){
            CD1-=CD2;
            sufferDammage(p2);
            
            CD2=p2->getAtksp();
        }
    }
    return true;
}
bool Player::isEnd(Player* p2) const
{
    return (hp==0 || p2->getHP()==0);

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
