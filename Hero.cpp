#include "Player.h"
#include <math.h>
#include <fstream>
#include "Json.h"
#include <vector>
#include <stdexcept>




Player::Player(std::string name, int hp, int dmg, double atksp) : Character(name, hp, dmg, atksp), maxHp(hp) {

}

bool Player::Combat(Player* enemy){

        enemy->sufferDammage(this);
        increaseXP(enemy->getHP());

        sufferDammage(enemy);
        enemy->increaseXP(hp);       

        double CD1=atksp;
        double CD2=enemy->getAtksp();

    while(!isEnd(enemy)){
        if(CD1==CD2){
            
            enemy->sufferDammage(this);
            increaseXP(enemy->getHP());
            
            sufferDammage(enemy);
            enemy->increaseXP(hp);
            
            CD1=atksp;
            CD2=enemy->getAtksp();          
        }
        if(CD1<CD2){
            CD2-=CD1;
            enemy->sufferDammage(this);
            increaseXP(enemy->getHP());
            
            
            CD1=atksp;
            }
        else if(CD2<CD1){
            CD1-=CD2;
            sufferDammage(enemy);
            enemy->increaseXP(hp);
            
            CD2=enemy->getAtksp();
        }
    }
    return true;
}

void Player::sufferDammage(Player* enemy) {
    hp-=enemy->getDMG();
    if (hp<0){
        hp=0;
    }
}


bool Player::isEnd(Player* enemy) const
{
    return (hp==0 || enemy->getHP()==0);
}



void Player::increaseXP(int enemyHp){
    
    if(enemyHp < dmg){
        XP += enemyHp;
    }
    else XP += dmg;

    if(XP>=LEVEL_BOUNDARY) levelUp();
}

std::string Player::getWinString(){
    return name + " wins. Remaining HP: " + std::to_string(hp) 
    + ", current level: " + std::to_string(level) 
    + ", current experience: " + std::to_string(XP) 
    + ", current attack speed: " + std::to_string(atksp) +'\n';
}


void Player::levelUp(){

    while (XP>=LEVEL_BOUNDARY){
        level++;
        XP-=LEVEL_BOUNDARY;
        hp = (int) round(maxHp * 1.1);
        maxHp = hp;
        dmg = (int) round(dmg*1.1);
        atksp = (double) (atksp*0.9);
    } 
}

Player* Player::parseUnit(std::string input){

   std::map<std::string, std::any> jdm = Json::JsonParser(input);

   return Player::parseHelper(jdm);
}

Player* Player::parseUnit(std::istream& input){

   std::map<std::string, std::any> jdm = Json::JsonParser(input);
   return Player::parseHelper(jdm);
}


Player* Player::parseHelper(std::map<std::string, std::any>& jdm){
     
   std::vector<std::string> PlayerData {"name", "hp", "dmg" ,"atksp"};
   std::vector<std::string>::size_type i;
   for (i = 0; i < PlayerData.size(); i++)
   {
        if (jdm.find(PlayerData[i]) == jdm.end())
        {
            throw std::invalid_argument("Json does not contain all data for the Player initialization.");
        }
    }

    std::string name = std::any_cast<std::string>(jdm["name"]);
    int hp = std::any_cast<int>(jdm["hp"]);
    int dmg = std::any_cast<int>(jdm["dmg"]);
    double atksp= std::any_cast<double>(jdm["atksp"]);
  
    Player* player = new Player(name,hp,dmg,atksp);

    return player;

}