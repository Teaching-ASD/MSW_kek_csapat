#include "../JSON.cpp"
#include "../Hero.cpp"
#include "../Monster.cpp"
#include "../Character.cpp"
#include<gtest/gtest.h>
#include <fstream>

// 1. ha whitespace-eket noveljuk 
// 2. kulcsok sorrendjet megvaltoztatjuk, akkor ugyanazt a strukturat adja vissza.
// 3. Character és Hero alapvető függvényinek tesztje
    // 4. getterek setterek jók-e
    // 5. Két hero egyenlő-e
    // 6. Exceptionoket dobnak-e ha kell
    // 7. levelup harc 
//8. Teljes teszt


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

    Hero hero1 ("Prince Aidan of Khanduras",30, 3, 1.1, 20, 5, 1, 0.9);
    Hero hero2 = Hero::parse("../Dark_Wanderer.json");

    EXPECT_EQ(hero1,hero2);

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}