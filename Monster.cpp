#include "Monster.h"
#include "JSON.h"
#include <vector>
#include <stdexcept>



Monster* Monster::parse(const std::string& json){

    JSON jdm = JSON::parseFromFile(json); 

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

