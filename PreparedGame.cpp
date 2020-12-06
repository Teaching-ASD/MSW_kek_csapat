#include "PreparedGame.h"


PreparedGame::PreparedGame(const std::string& filename){

    JSON json = JSON::parseFromFile(filename);
    
    std::string jsonFile = json.get<std::string>("map");
    gameMap = new MarkedMap(jsonFile);

    jsonFile = json.get<std::string>("hero");
    gameHero = Hero::parse(jsonFile);
    Pos pos= gameMap->getHeroPosition();
    if(pos.isEmpty()) throw Game::NotInitializedException("Hero is not initialized!");
    gameHero->setPosition(pos.getX(), pos.getY());    

    std::string monster = json.get<std::string>("monster-1");
    storeAllMonster(monster,'1');

    monster = json.get<std::string>("monster-2");
    storeAllMonster(monster,'2');

    monster = json.get<std::string>("monster-3");
    storeAllMonster(monster,'3');

    
}

PreparedGame::~PreparedGame(){
    delete gameHero;
    delete gameMap;
    for(auto monster : gameMonsters){
        delete monster;
    }
    gameMonsters.clear();
}

void PreparedGame::storeAllMonster(const std::string& monsterType, char monsterChar){
    
    std::list<Pos> monsterPos = gameMap->getMonsterPositions(monsterChar);

    for(const auto& pos : monsterPos) {
        gameMonsters.push_back(Monster::parse(monsterType));
        gameMonsters.back()->setPosition(pos.getX(),pos.getY());
    }
}