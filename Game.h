#ifndef Game_H
#define Game_H

#include <string>
#include <map>
#include "MarkedMap.h"
#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include "Pos.h"
#include "Renderer.h"

class Renderer;


class Game {

protected:
    Map* gameMap=nullptr;
    Hero* gameHero=nullptr;
    std::vector<Monster*> gameMonsters;
    JSON commands;
    std::string command="";
    Pos* moveBlock=nullptr;
    bool isRun=false;
    std::vector<Renderer*> renderers;
    


public:
    Game();
    Game(const std::string& mapfilename);
    virtual ~Game();
    void run();
    void registerRenderer(Renderer* renderer);
    const Map* getMap() const;
    const Hero* getHero() const;

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

protected:
    Monster* findeMonster();
    bool inputCommand();
    void move();
    void fight();
    void setMap(Map* map);
    void putHero(Hero* hero, int x, int y);
    void putMonster(Monster* monster, int x, int y);


};


#endif //Game_H