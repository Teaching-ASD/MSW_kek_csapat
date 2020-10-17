#include "Player.h"
#include "Json.h"
#include <vector>
#include <stdexcept>



Player::Player(std::string name, int hp, int dmg): name(name), hp(hp), dmg(dmg) {

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


Player* Player::parseUnit(std::string input){

   std::map<std::string, std::any> jdm = Json::JsonParser(input);

   return Player::parseHelper(jdm);

}

Player* Player::parseUnit(std::istream& input){

   std::map<std::string, std::any> jdm = Json::JsonParser(input);

   return Player::parseHelper(jdm);
}

Player* Player::parseHelper(std::map<std::string, std::any>& jdm){
     
   std::vector<std::string> PlayerData {"name", "hp", "dmg"};
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

    Player* player = new Player(name,hp,dmg);

    return player;
}