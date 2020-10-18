#include "Player.h"
#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>



Player::Player(std::string name, int hp, int dmg) : Character(name, hp, dmg), maxHp(hp) {

} 

void Player::increaseXP(int enemyHp){
    
    if(enemyHp < dmg){
        XP += enemyHp;
    }
    else XP += dmg;

    if(XP>=LEVEL_BOUNDARY) levelUp();
}

std::string Player::getWinString(){
    return name + " wins. Remaining HP: " + std::to_string(hp) + ", current level: " + std::to_string(level) + ", current experience: " + std::to_string(XP) + '\n';
}


void Player::levelUp(){

    while (XP>=LEVEL_BOUNDARY){
        level++;
        XP-=LEVEL_BOUNDARY;
        hp = (int) round(maxHp * 1.1);
        maxHp = hp;
        dmg = (int) round(dmg*1.1);
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