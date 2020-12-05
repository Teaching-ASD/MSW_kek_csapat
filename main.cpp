#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Map.h"
#include "Game.h"





const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." }
};

void bad_exit(int exitcode){
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char** argv){
    if (argc != 2) bad_exit(1);
    if (!std::filesystem::exists(argv[1])) bad_exit(2);

    std::string hero_file;
    std::list<std::string> monster_files;
    try {
        JSON scenario = JSON::parseFromFile(argv[1]); 
        if (!(scenario.count("hero")&&scenario.count("monsters"))) bad_exit(3);
        else {
            hero_file=scenario.get<std::string>("hero");
            JSON::list monster_file_list=scenario.get<JSON::list>("monsters");
            for(auto monster_file : monster_file_list)
                monster_files.push_back(std::get<std::string>(monster_file));
        }
    } catch (const JSON::ParseException& e) {bad_exit(4);}

    Hero* hero=nullptr;
    std::vector<Monster*> monsters;
    Map* map=nullptr;

    try { 
        hero = Hero::parse(hero_file);
        for (const auto& monster_file : monster_files)
            monsters.push_back(Monster::parse(monster_file));        
        map = new Map("./Maps/Map1.txt");

        Game game;

        game.setMap(map);
        game.putHero(hero, 1, 1);

        game.putMonster(monsters[0],2,1);
        game.putMonster(monsters[1],3,3);
        game.putMonster(monsters[2],5,3);
        game.putMonster(monsters[3],5,3);
        game.putMonster(monsters[4],5,4);
        game.putMonster(monsters[5],5,6);
        game.putMonster(monsters[6],5,6);
        game.putMonster(monsters[7],5,6);

        game.run();

    } 
    catch (const JSON::ParseException& e) {bad_exit(4);}
    
    catch(const Map::WrongIndexException& me){
        std::cout << me.what() << std::endl;
    }

    catch(const Map::FileException& me){
        std::cout << me.what() << std::endl;
    }

    catch(const Game::AlreadyHasHeroException& ge){
        std::cout << ge.what() << std::endl;
    }

    catch(const Game::AlreadyHasUnitsException& ge){
        std::cout << ge.what() << std::endl;
    }
    
    catch(const Game::AlreadyStartedException& ge){
        std::cout << ge.what() << std::endl;
    }
      
    catch(const Game::MonsterAlreadyContains& ge){
        std::cout << ge.what() << std::endl;
    }
    
    catch(const Game::NotInitializedException& ge){
        std::cout << ge.what() << std::endl;
    }

    catch(const Game::OccupiedException& ge){
        std::cout << ge.what() << std::endl;
    }

    
    delete hero;
    delete map;

    if(!monsters.empty()){
        for(auto monster : monsters){
            delete monster;
        }
    }

    return 0;
}
