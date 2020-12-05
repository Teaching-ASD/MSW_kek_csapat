#include "Monster.h"
#include "JSON.h"
#include <vector>
#include <stdexcept>



Monster* Monster::parse(const std::string& json){

   JSON jdm = JSON::parseFromFile(json); 

   std::vector<std::string> PlayerData {
    "name",
    "health_points",
    "attack_cooldown",
    "defense"
   };


    std::vector<std::string>::size_type i;
   for (i = 0; i < PlayerData.size(); i++)
   {

        if (!jdm.count(PlayerData.at(i)) ) {
            throw JSON::ParseException();
        }
    }

    
    Damage d;

    if(jdm.count("damage")) d.physical=jdm.get<int>("damage");
    if(jdm.count("magical-damage")) d.magical=jdm.get<int>("magical-damage");

    std::string name = jdm.get<std::string>("name");
    int hp = jdm.get<int>("health_points");
    double atksp = jdm.get<double>("attack_cooldown");
    int def = jdm.get<int>("defense");
    
    Monster* monster = new Monster(name, hp, d.physical, d.magical, atksp, def);

    return monster;
}
