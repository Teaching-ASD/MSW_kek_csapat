#include "../JSON.cpp"
#include "../Hero.cpp"
#include "../Monster.cpp"
#include "../Character.cpp"
#include "../Map.cpp"
#include "../Game.cpp"
#include "../Pos.cpp"
#include "../MarkedMap.cpp"
#include<gtest/gtest.h>
#include <fstream>
#include <list>


class JsonTest : public ::testing::Test {
    protected:
    JSON scenario;
    JSON hero;
    JSON monster;
    void SetUp() override {
        
        ASSERT_NO_THROW({
        
        scenario = JSON::parseFromFile("../Scenarios/scenario1.json");
        
        std::ifstream heroFile("../Dark_Wanderer.json");
        hero = JSON::parseFromIstream(heroFile);
        
        std::string mstring ("{\"health_points\" : 10, \"damage\" : 1, \"attack_cooldown\" : 2.8, \"race\"\n\n : \"undead\", \"name\"              :           \"Zombie\"}");
        monster = JSON::parseFromString(mstring);
        
        });
    }

};

TEST_F(JsonTest, count) {

    //Scenarios parseFromFile
    ASSERT_TRUE(scenario.count("hero"));
    ASSERT_TRUE(scenario.count("monsters"));
    ASSERT_FALSE(scenario.count("Ogre"));


    //Hero parseFromIstream
    ASSERT_TRUE(hero.count("name"));
    ASSERT_TRUE(hero.count("base_health_points"));
    ASSERT_FALSE(hero.count("ideidjied"));

    //Mosnter parseFromString
    ASSERT_TRUE(monster.count("name"));
    ASSERT_TRUE(monster.count("health_points"));
    ASSERT_FALSE(monster.count("ideidjied"));

}

TEST_F(JsonTest, get) {
    
    //Scenarios parseFromFile
    ASSERT_NO_THROW(scenario.get<std::string>("hero"));
    ASSERT_THROW(scenario.get<int>("hero"), JSON::ParseException);

    std::string heroFile = scenario.get<std::string>("hero");
    std::string expected = "Dark_Wanderer.json";

    EXPECT_EQ(heroFile, expected);

    //Hero parseFromIstream
    ASSERT_NO_THROW(hero.get<double>("cooldown_multiplier_per_level"));
    double cdpl = hero.get<double>("cooldown_multiplier_per_level");
    EXPECT_NEAR(cdpl, 0.9, 1e-6);

}

TEST(HeroTest, ObjectEqualJson){

    Hero hero1 ("Prince Aidan of Khanduras",30, 3, 2, 1.1, 2, 1, 20, 5, 1, 0.9);
    Hero* hero2 = Hero::parse("../Dark_Wanderer.json");
    
    EXPECT_EQ(hero1,*hero2);

    delete hero2;

}



class MapTest : public ::testing::Test {
    protected:
        Map* map;
        void SetUp() override {
             ASSERT_NO_THROW(map = new Map("../Maps/Map1.txt"));
        }   
        void TearDown() override {
            delete map;
        }
};

TEST_F(MapTest, MapInitialization){

    Map testMap("../Maps/Map1.txt");

    ASSERT_EQ(*map, testMap);

    EXPECT_EQ(testMap.getHeight(), 7);
    EXPECT_EQ(testMap.getWidth(), 14);
}

TEST_F(MapTest, getMap){

    EXPECT_EQ(map->get(0,13),Map::type::Wall);
    EXPECT_EQ(map->get(0,3),Map::type::Wall);
    EXPECT_EQ(map->get(1,1),Map::type::Free);

}

TEST_F(MapTest, setMap){

    EXPECT_EQ(map->get(1,1),Map::type::Free);
    map->setBlock(Map::type::Hero, 1,1);
    EXPECT_EQ(map->get(1,1),Map::type::Hero);

}

TEST_F(MapTest, Exception){

    ASSERT_NO_THROW(map->get(0,13));
    ASSERT_NO_THROW(map->setBlock(Map::type::Free,1,1));
    
    ASSERT_THROW(map->get(20,30), Map::WrongIndexException);
    ASSERT_THROW(map->setBlock(Map::type::Monster,50,80), Map::WrongIndexException);
}



class GameTest : public ::testing::Test {
    protected:
        Game* game;
        Hero* hero;
        Map* map;
        std::vector<Monster*> monsters;
        void SetUp() override {
            game = new Game();
            hero = new Hero("Prince Aidan of Khanduras",30, 2, 2, 1.1,2,1,20,5, 1, 0.9);
            monsters.push_back(new Monster("Zombie", 10, 1,0,2.8, 1));
            monsters.push_back(new Monster("Zombie", 10, 1, 1, 2.8, 1));
            monsters.push_back(new Monster("Fallen", 4, 2,1, 1.6, 2));
            
            
            ASSERT_THROW(game->putHero(hero,1,1), Map::WrongIndexException);
            ASSERT_THROW(game->putMonster(monsters[0],3,3), Map::WrongIndexException);                
  

            ASSERT_NO_THROW(map = new Map("../Maps/Map1.txt"));
            ASSERT_NO_THROW(game->setMap(map));

            ASSERT_THROW(game->putHero(hero, 4,4), Game::OccupiedException);
            ASSERT_NO_THROW(game->putHero(hero, 5,3));
            ASSERT_THROW(game->putHero(hero, 1,1), Game::AlreadyHasHeroException);

            ASSERT_THROW(game->putMonster(monsters[0], 4,4), Game::OccupiedException);
            ASSERT_NO_THROW(game->putMonster(monsters[0],3,3));
            ASSERT_THROW(game->putMonster(monsters[1], 5,3), Game::OccupiedException);
 
        }   
        void TearDown() override {
           delete game;
        }
};

TEST_F(GameTest, setMap){

    Game testGame;
    Map* testMap = new Map("../Maps/Map1.txt");
    Hero* testHero = new Hero("Prince Aidan of Khanduras",30, 2,3, 1.1,3,1,20,5, 1, 0.9);
    Monster* testMonster= new Monster("Zombie", 10, 1, 0, 2.8, 1);

    testGame.setMap(testMap);

    ASSERT_NO_THROW(testGame.putHero(testHero, 5,3));
    ASSERT_NO_THROW(testGame.putMonster(testMonster,3,3));
    EXPECT_EQ(*game, testGame);

}


TEST_F(GameTest, putHero){

    EXPECT_EQ(map->get(5,3),Map::type::Hero);
    
    EXPECT_EQ(hero->getPositionX(),5);
    EXPECT_EQ(hero->getPositionY(),3);

}

TEST_F(GameTest, putMonster){
   
    EXPECT_EQ(map->get(3,3),Map::type::Monster);
    EXPECT_EQ(monsters[0]->getPositionX(),3);
    EXPECT_EQ(monsters[0]->getPositionY(),3);

    ASSERT_NO_THROW(game->putMonster(monsters[1],3,3));
    ASSERT_THROW(game->putMonster(monsters[1], 3,3), Game::MonsterAlreadyContains);

}

TEST_F(GameTest, run){

    Game rawGame;
    ASSERT_THROW(rawGame.run(), Game::NotInitializedException);
    Map* map1 = new Map("../Maps/Map1.txt");
    rawGame.setMap(map1);
    ASSERT_THROW(rawGame.run(), Game::NotInitializedException);


}

TEST(DamageTest, Operators){
    

    Character::Damage dmg (1,1);

    dmg+=10; 

    EXPECT_EQ(dmg.physical, 11);
    EXPECT_EQ(dmg.magical, 11);

    dmg*=2;

    EXPECT_EQ(dmg.physical, 22);
    EXPECT_EQ(dmg.magical, 22);

    dmg=dmg+10;

    EXPECT_EQ(dmg.physical, 32);
    EXPECT_EQ(dmg.magical, 32);

    Character::Damage addDmg(2,2);

    dmg+=addDmg;

    EXPECT_EQ(dmg.physical, 34);
    EXPECT_EQ(dmg.magical, 34);

    dmg*=addDmg;

    EXPECT_EQ(dmg.physical, 68);
    EXPECT_EQ(dmg.magical, 68);

    dmg=dmg+addDmg;

    EXPECT_EQ(dmg.physical, 70);
    EXPECT_EQ(dmg.magical, 70);


    Character::Damage* pointerDmg = new Character::Damage(1,1);

    *pointerDmg+=10;

    EXPECT_EQ(pointerDmg->physical, 11);
    EXPECT_EQ(pointerDmg->magical, 11);

}

class Fight : public ::testing::Test {

protected:
    Hero*  hero;
    std::vector<Monster*> monsters;
    void SetUp() override {

        ASSERT_NO_THROW({
            hero = Hero::parse("../Dark_Wanderer.json");
            monsters.push_back(Monster::parse("../Zombie.json"));
            monsters.push_back(Monster::parse("../Zombie.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Zombie.json"));
            monsters.push_back(Monster::parse("../Zombie.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
            monsters.push_back(Monster::parse("../Fallen.json"));
        });
        
    }   
    void TearDown() override {
        delete hero;
        for(auto& monster : monsters){
            delete monster;
        }
    }
};

TEST_F(Fight, DefenseAndMagic){


    EXPECT_EQ(hero->getPhysicalDamage(), 3);
    EXPECT_EQ(hero->getMagicalDamage(), 2);
    EXPECT_EQ(hero->getDef(), 2);

    EXPECT_EQ(monsters[0]->getPhysicalDamage(), 2);
    EXPECT_EQ(monsters[0]->getMagicalDamage(), 1);

    hero->sufferDamage(*monsters[0]);

    EXPECT_EQ(hero->getHealthPoints(), 29);

    monsters[0]->sufferDamage(*hero);

    EXPECT_EQ(monsters[0]->getHealthPoints(), 6);

    for(auto monster : monsters){
        while(monster->isAlive()){
            int diff = monster->sufferDamage(*hero);
            hero->increaseXP(diff);
        }
    }

    EXPECT_EQ(hero->getPhysicalDamage(), 6);
    EXPECT_EQ(hero->getMagicalDamage(), 5);
    EXPECT_EQ(hero->getDef(), 5);
    EXPECT_EQ(hero->getLevel(), 4);

}


TEST(MarkedMap, functionTest){

    MarkedMap  markedMap("../Maps/MarkedMap.txt");

    EXPECT_EQ(markedMap.get(0,13),Map::type::Wall);
    EXPECT_EQ(markedMap.get(0,3),Map::type::Wall);
    EXPECT_EQ(markedMap.get(1,1),Map::type::Free);
    EXPECT_EQ(markedMap.get(1,2),Map::type::Hero);
    EXPECT_EQ(markedMap.get(3,2),Map::type::Monster1);
    EXPECT_EQ(markedMap.get(3,3),Map::type::Monster2);

    Pos pos = markedMap.getHeroPosition();
    
    EXPECT_EQ(pos.getX(),1);
    EXPECT_EQ(pos.getY(),2);     

    std::list<Pos> monsters = markedMap.getMonsterPositions('1');
    
    EXPECT_EQ(monsters.size(),3);

    EXPECT_EQ(monsters.back().getX(),5);
    EXPECT_EQ(monsters.back().getY(),6);


}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}