#include "Player.h"
#include "Json.h"
#include <vector>
#include <stdexcept>




Player::Player(std::string name, int hp, int dmg, double atksp): name(name), hp(hp), dmg(dmg), atksp(atksp) {

}

std::string Player::getName() const {
    return name;
}  

int Player::getHP() const {
  return hp; 
}

int Player::getDMG() const{
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
   for (int i = 0; i < PlayerData.size(); i++)
   {
        if (jdm.find(PlayerData[i]) == jdm.end())
        {
            throw std::invalid_argument("Json does not contain all data for the Player initialization.");
        }
    }

    std::string name = std::any_cast<std::string>(jdm["name"]);
    int hp = std::any_cast<int>(jdm["hp"]);
    int dmg = std::any_cast<int>(jdm["dmg"]);
    float atksp= std::any_cast<float>(jmd["atksp"]);
  
    Player* player = new Player(name,hp,dmg,atksp);

    return player;
}