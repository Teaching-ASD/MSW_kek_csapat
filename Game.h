#ifndef Game_H
#define Game_H

#include <string>
#include <map>
#include "Map.h"
#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include "Pos.h"


class Game {

    Map* gameMap=nullptr;
    Hero* gameHero=nullptr;
    std::vector<Monster*> gameMonsters;
    JSON commands;
    JSON unicodes;
    std::string command="";
    Pos* moveBlock=nullptr;
    bool isRun=false;
    
    const std::string hero = "\u251C\u2524";
    const std::string monster = "M";
    const std::string monsters = "MM";
    const std::string Free = "\u2591";
    const std::string Wall = "\u2588";
    const std::string left_TopCorner = "\u2554";
    const std::string right_TopCorner = "\u2557";
    const std::string topAndBotFrame = "\u2550";
    const std::string leftAndRightFrame = "\u2551";
    const std::string left_BotCorner = "\u255A";
    const std::string right_BotCorner ="\u255D";

public:
    Game();
    Game(const std::string& mapfilename);
    ~Game();
    void setMap(Map* map);
    void putHero(Hero* hero, int x, int y);
    void putMonster(Monster* monster, int x, int y);
    void run();
    void printMap()const;
    void printRadius()const;


    friend bool operator==(const Game& game1, const Game& game2);

    class OccupiedException : virtual public std::runtime_error {
		public:
		    explicit OccupiedException(const std::string& msg) : std::runtime_error("Occupide: " + msg) {}
	};

    class AlreadyHasHeroException : virtual public std::runtime_error {
		public:
		    explicit AlreadyHasHeroException(const std::string& msg) : std::runtime_error("Already has Hero: " + msg) {}
	};

    class AlreadyHasUnitsException : virtual public std::runtime_error {
		public:
		    explicit AlreadyHasUnitsException(const std::string& msg) : std::runtime_error("Already has units: " + msg) {}
	};

    class NotInitializedException: virtual public std::runtime_error {
		public:
		    explicit NotInitializedException(const std::string& msg) : std::runtime_error("Game not initialized: " + msg) {}
	};

    class AlreadyStartedException : virtual public std::runtime_error {
		public:
		    explicit AlreadyStartedException(const std::string& msg) : std::runtime_error("Game already started: " + msg) {}
	};

    class MonsterAlreadyContains : virtual public std::runtime_error {
		public:
		    explicit MonsterAlreadyContains(const std::string& msg) : std::runtime_error("This monster already contains: " + msg) {}
	};

private:
    
    Monster* findeMonster();
    bool inputCommand();
    void move();
    void fight();


};


#endif //Game_H