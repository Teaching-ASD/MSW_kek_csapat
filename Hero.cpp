#include "Hero.h"
#include "JSON.h"

#include <math.h>
#include <fstream>
#include <vector>
#include <stdexcept>


Hero::Hero(
    std::string name, 
    int hp, 
    int dmg, 
    double atksp,
    int xpPerLev,
    int hpPerLev,
    int dmgPerLev,
    double cdPerLev): 
    Character(name, hp, dmg, atksp),
    xpPerLev(xpPerLev),
    hpPerLev(hpPerLev),
    dmgPerLev(dmgPerLev),
    cdPerLev(cdPerLev) {
        maxHp=hp;
    }

int Hero::getLevel() const {
    return level;
}
    
int Hero::getMaxHealthPoints() const{
    return maxHp;
}
    
void Hero::fightTilDeath(Monster& enemy){

        int diff = enemy.sufferDammage(*this);
        increaseXP(diff);

        if(!enemy.isAlive()) {return;}
    
        sufferDammage(enemy);  

        double CD1 = atksp;
        double CD2 = enemy.getAttackCoolDown();

    while(isAlive() && enemy.isAlive()){
        if(CD1==CD2){

            diff = enemy.sufferDammage(*this);
            increaseXP(diff);
            
            sufferDammage(enemy);

            CD1=atksp;
            CD2=enemy.getAttackCoolDown();          
        }
        if(CD1<CD2){
            CD2-=CD1;
            
        
            diff = enemy.sufferDammage(*this);
            increaseXP(diff);

            CD1=atksp;
        }
        else if(CD2<CD1){
            CD1-=CD2;
        
            sufferDammage(enemy);
            
            CD2=enemy.getAttackCoolDown();
        }
        
    }

}



void Hero::increaseXP(int diff){

    xp+=diff;
    if(xp>=xpPerLev) levelUp();

}


void Hero::levelUp(){

    while (xp>=xpPerLev){
        level++;
        xp-=xpPerLev;
        maxHp += hpPerLev;
        hp=maxHp;
        dmg += dmgPerLev;
        atksp = (double) (atksp*cdPerLev);
    } 
}

Hero Hero::parse(std::string json){

   JSON jdm = JSON::parseFromFile(json);
         
   std::vector<std::string> PlayerData {
    "name",
    "base_health_points",
    "base_damage",
    "base_attack_cooldown",
    "experience_per_level",
    "health_point_bonus_per_level",
    "damage_bonus_per_level",
    "cooldown_multiplier_per_level"
   };


   std::vector<std::string>::size_type i;
   for (i = 0; i < PlayerData.size(); i++)
   {
        if (!jdm.count(PlayerData.at(i)) ) {
            throw JSON::ParseException();
        }
    }

    std::string name = jdm.get<std::string>("name");
    int hp = jdm.get<int>("base_health_points");
    int dmg = jdm.get<int>("base_damage");
    double atksp= jdm.get<double>("base_attack_cooldown");
    int xpPerLev = jdm.get<int>("experience_per_level");
    int hpPerLev = jdm.get<int>("health_point_bonus_per_level");
    int dmgPerLev = jdm.get<int>("damage_bonus_per_level");
    double cdPerLev = jdm.get<double>("cooldown_multiplier_per_level");


    Hero player(name, hp, dmg, atksp, xpPerLev, hpPerLev, dmgPerLev, cdPerLev);
    return player;

}



bool operator==(const Hero& p1, const Hero& p2)
{ 
    return (p1.name==p2.name && p1.hp==p2.hp && p1.dmg==p2.dmg);
}