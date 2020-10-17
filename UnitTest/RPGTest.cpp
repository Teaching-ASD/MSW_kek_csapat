#include "../Json.cpp"
#include "../Player.cpp"
#include "../Game.cpp"
#include<gtest/gtest.h>



TEST(PlayerParseUnitTest, stringInput) {

Player p1("Kakarott", 3000, 400);

Player p2 = *(Player::parseUnit("{\"name\" : \"Kakarott\", \"hp\" : 3000, \"dmg\" : 400}"));

ASSERT_EQ(p1,p2);

}


TEST(PlayerParseUnitTest, fileNameInput) {

 Player p1("Kakarott", 3000, 400);

Player p2 = *(Player::parseUnit("../Units/player1.json"));

ASSERT_EQ(p1,p2);

}


TEST(PlayerParseUnitTest, istreamInput) {

Player p1("Kakarott", 3000, 400);

std::ifstream file ("../Units/player1.json");

Player p2 = *(Player::parseUnit(file));

ASSERT_EQ(p1, p2);

}


TEST(JsonTest, ReadFile) {

    ASSERT_THROW(Json::JsonParser("notexist.json"), ReadFileError);
    ASSERT_NO_THROW(Json::JsonParser("../Units/player1.json"));

}

TEST(JsonTest, CastException) {

    std::map<std::string, std::any> jdm = Json::JsonParser("{\"string\" : \"playerName\", \"int\" : 3000, \"float\" : 400.0}");
    
    ASSERT_NO_THROW(std::any_cast<std::string>(jdm["string"]));
    ASSERT_EQ(std::any_cast<std::string>(jdm["string"]), "playerName");

    ASSERT_NO_THROW(std::any_cast<int>(jdm["int"]));
    ASSERT_EQ(std::any_cast<int>(jdm["int"]), 3000);

    ASSERT_NO_THROW(std::any_cast<float>(jdm["float"]));
    ASSERT_EQ(std::any_cast<float>(jdm["float"]), 400.0);

}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}