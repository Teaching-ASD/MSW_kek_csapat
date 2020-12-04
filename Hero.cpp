#include "Hero.h"
#include "JSON.h"

#include <math.h>
#include <fstream>
#include <vector>
#include <stdexcept>


Hero::Hero(
    const std::string& name, 
    int hp, 
    int pd,
    int md, 
    double atksp,
    int def,
    int defPerLev,
    int xpPerLev,
    int hpPerLev,
    int dmgPerLev,
    double cdPerLev): 
    Character(name, hp, pd, md, atksp, def),
    defPerLev(defPerLev),
    xpPerLev(xpPerLev),
    hpPerLev(hpPerLev),
    dmgPerLev(dmgPerLev),
    cdPerLev(cdPerLev),
    maxHp(hp)
    {}

int Hero::getLevel() const {
    return level;
}
    
int Hero::getMaxHealthPoints() const{
    return maxHp;
}
    
void Hero::fightTilDeath(Monster* enemy){

        int diff = enemy->sufferDamage(*this);
        increaseXP(diff);

        if(!enemy->isAlive()) {return;}
    
        sufferDamage(*enemy);  

        double CD1 = atksp;
        double CD2 = enemy->getAttackCoolDown();

    while(isAlive() && enemy->isAlive()){
        if(CD1==CD2){

            diff = enemy->sufferDamage(*this);
            increaseXP(diff);
            
            sufferDamage(*enemy);

            CD1=atksp;
            CD2=enemy->getAttackCoolDown();          
        }
        else if(CD1<CD2){   
            diff = enemy->sufferDamage(*this);
            increaseXP(diff);
            CD1=atksp;
            CD2-=CD1;
        }
        else if(CD2<CD1){
            CD1-=CD2;        
            sufferDamage(*enemy);
            CD2=enemy->getAttackCoolDown();
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
        Damage pml(dmgPerLev,dmgPerLev);
        *damage += pml;
        atksp = (double) (atksp*cdPerLev);
        def+=defPerLev;
    } 
}

Hero* Hero::parse(std::string json){

   JSON jdm = JSON::parseFromFile(json);
         
   std::vector<std::string> PlayerData {
    "name",
    "base_health_points",
    "base_attack_cooldown",
    "experience_per_level",
    "health_point_bonus_per_level",
    "damage_bonus_per_level",
    "cooldown_multiplier_per_level",
    "defense",
    "defense_bonus_per_level", 
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
    int hp = jdm.get<int>("base_health_points");
    double atksp= jdm.get<double>("base_attack_cooldown");
    int xpPerLev = jdm.get<int>("experience_per_level");
    int hpPerLev = jdm.get<int>("health_point_bonus_per_level");
    int dmgPerLev = jdm.get<int>("damage_bonus_per_level");
    double cdPerLev = jdm.get<double>("cooldown_multiplier_per_level");
    int def = jdm.get<int>("defense");
    int defPerLev = jdm.get<int>("defense_bonus_per_level");

    Hero* player = new Hero(name, hp,d.physical,d.magical, atksp, def, defPerLev,  xpPerLev, hpPerLev, dmgPerLev, cdPerLev);
    return player;

}



bool operator==(const Hero& p1, const Hero& p2)
{ 
    return (
        p1.name==p2.name && 
        p1.hp==p2.hp && 
        p1.damage->physical==p2.damage->physical &&
        p1.damage->magical==p2.damage->magical &&
        p1.atksp==p2.atksp &&
        p1.cdPerLev == p2.cdPerLev &&
        p1.xpPerLev == p2.xpPerLev &&
        p1.hpPerLev == p2.hpPerLev &&
        p1.dmgPerLev == p2.dmgPerLev &&
        p1.level == p2.level 
        );
}
