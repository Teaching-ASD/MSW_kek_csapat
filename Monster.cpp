#include "Monster.h"
#include "JSON.h"
#include <vector>
#include <stdexcept>

Monster Monster::parse(std::string json){

   JSON jdm = JSON::parseFromFile(json); 

   std::vector<std::string> PlayerData {
    "name",
    "health_points",
    "damage",
    "attack_cooldown",
   };


    std::vector<std::string>::size_type i;
   for (i = 0; i < PlayerData.size(); i++)
   {
        if (!jdm.count(PlayerData.at(i)) ) {
            throw JSON::ParseException();
        }
    }

    std::string name = jdm.get<std::string>("name");
    int hp = jdm.get<int>("health_points");
    int dmg = jdm.get<int>("damage");
    double atksp = jdm.get<double>("attack_cooldown");
    
    Monster monster(name, hp, dmg, atksp);

    return monster;
}
