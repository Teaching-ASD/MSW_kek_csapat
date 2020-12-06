#include "PreparedGame.h"


PreparedGame::PreparedGame(const std::string& filename){

    JSON json = JSON::parseFromFile(filename);
    
    std::string jsonFile = json.get<std::string>("map");
    gameMap = new MarkedMap(jsonFile);
    MarkedMap* markedMap = static_cast<MarkedMap*>(gameMap);
    if(markedMap==nullptr) throw Map::WrongIndexException("Wrong map type.");

    jsonFile = json.get<std::string>("hero");
    gameHero = Hero::parse(jsonFile);
    Pos pos= markedMap->getHeroPosition();
    if(pos.isEmpty()) throw Game::NotInitializedException("Hero is not initialized!");
    gameHero->setPosition(pos.getX(), pos.getY());    

    std::string monster = json.get<std::string>("monster-1");
    storeAllMonster(monster,'1', markedMap);

    monster = json.get<std::string>("monster-2");
    storeAllMonster(monster,'2', markedMap);

    monster = json.get<std::string>("monster-3");
    storeAllMonster(monster,'3', markedMap);

    
}

PreparedGame::~PreparedGame(){
    delete gameHero;
    delete gameMap;
    for(auto monster : gameMonsters){
        delete monster;
    }
    gameMonsters.clear();
}

void PreparedGame::storeAllMonster(const std::string& monsterType, char monsterChar, const MarkedMap* mMap){
    
    std::list<Pos> monsterPos = mMap->getMonsterPositions(monsterChar);

    for(const auto& pos : monsterPos) {
        gameMonsters.push_back(Monster::parse(monsterType));
        gameMonsters.back()->setPosition(pos.getX(),pos.getY());
    }
}