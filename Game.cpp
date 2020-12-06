#include "Game.h"
#include <iostream>



Game::Game(){
    commands = JSON::parseFromFile("./GameData/Commands.json");
    moveBlock = new Pos();
}


Game::Game(const std::string& mapfilename) : gameMap(new MarkedMap(mapfilename)){
    Game();
}


Game::~Game(){
   delete moveBlock;
}

const Map* Game::getMap() const {
    return gameMap;
}

void Game::registerRenderer(Renderer* renderer) {
    renderers.push_back(renderer);
}


void Game::setMap(Map* map){

    if(isRun) 
        throw Game::AlreadyStartedException("You can\'t initialize map after game started.");

    if(gameHero || !gameMonsters.empty()) 
        throw Game::AlreadyHasUnitsException("You can\'t set a new map when you alredy has units on it.");
   
    gameMap = map;

}


void Game::putHero(Hero* hero, int x, int y){

    if(!gameMap) throw Map::WrongIndexException("Map is uninitialized.");
    
    if(gameHero || !hero) throw Game::AlreadyHasHeroException("One map one hero.");
    
    bool canSet = gameMap->get(x,y)==Map::type::Free;
    
    if(!canSet) throw Game::OccupiedException("You can put a hero only free position.");

    gameMap->setBlock(Map::type::Hero, x, y);
    gameHero = hero;
    gameHero->setPosition(x,y);

}

void Game::putMonster(Monster* monster, int x, int y){
    

    if(!gameMap) throw Map::WrongIndexException("Map is uninitialized.");
    
    if(!gameMonsters.empty()) {
        if(std::find(gameMonsters.begin(), gameMonsters.end(), monster) != gameMonsters.end())
            throw Game::MonsterAlreadyContains(monster->getName());
    }

    Map::type block = gameMap->get(x,y);
    bool canSet = block==Map::type::Free || block==Map::type::Monster || block==Map::type::Monsters;
    
    if(!canSet) throw Game::OccupiedException("You can put a monster free or monster(s) position.");
    if(block==Map::type::Free) block = Map::type::Monster;
    else block = Map::type::Monsters;


    gameMap->setBlock(block, x, y);      
    gameMonsters.push_back(monster);
    gameMonsters.back()->setPosition(x,y);     
 
} 

bool Game::inputCommand(){
    
    std::cout << "move: "; 
    std::cin >> command;
    std::cin.clear();
    return commands.count(command);

}


void Game::move(){
    
    while(!inputCommand()) {
        std::cout << "Unknow command: " << command << std::endl;
    }

    moveBlock->set(gameHero->getPositionX(), gameHero->getPositionY());


    switch (commands.get<int>(command))
    {
    case 0:
        moveBlock->IDX(true);
        break;
    case 1: 
        moveBlock->IDX(false);
        break;
    case 2: 
        moveBlock->IDY(true);
        break;
    case 3: 
        moveBlock->IDY(false);
        break;
    default:
        break;
    }


    Map::type blockType = gameMap->get(moveBlock->getX(), moveBlock->getY());


    bool isWall = Map::type::Wall == blockType;

    if(isWall) return;

    bool isMonster = Map::type::Monster1 == blockType ||  Map::type::Monster2 == blockType ||
    blockType == Map::type::Monster3;

    if(isMonster) fight();

    bool isFree = Map::type::Free == blockType;

    if(isFree){
        gameMap->setBlock(Map::type::Free, gameHero->getPositionX(),gameHero->getPositionY());
        gameHero->setPosition(moveBlock->getX(),moveBlock->getY());
        gameMap->setBlock(Map::type::Hero, moveBlock->getX(),moveBlock->getY());
    }

}

void Game::fight(){
    Monster* enemy=findeMonster();
    while(enemy){

        std::cout 
                << gameHero->getName() << "(" << gameHero->getLevel()<<")"
                << " vs "
                << enemy->getName()
                <<std::endl;
        
        gameHero->fightTilDeath(enemy);

        if(!enemy->isAlive()) {
            auto it = std::find(gameMonsters.begin(), gameMonsters.end(), enemy);
            if (it != gameMonsters.end()) gameMonsters.erase(it);
            delete enemy;
        }
        enemy=findeMonster();
    }
    
    if(gameHero->isAlive()) gameMap->setBlock(Map::type::Free, moveBlock->getX(), moveBlock->getY());
}

Monster* Game::findeMonster(){

    if(!gameHero->isAlive() || gameMonsters.empty()) return nullptr;

    for(const auto& monster : gameMonsters){
        if(moveBlock->getX() == monster->getPositionX() &&
           moveBlock->getY() == monster->getPositionY()){
             return monster;
        }
    }
    return nullptr;
}


void Game::run() {

    if(!(gameMap && gameHero)) throw Game::NotInitializedException("You should initialize map and hero.");
    
    isRun = true;

    while (gameHero->isAlive() && !gameMonsters.empty()) {
        for(const auto& renderer : renderers){
            renderer->render(*this);
        }
        move();
    }

    std::cout << (gameHero->isAlive() ? gameHero->getName() + " clear the map." : "The hero died.") << std::endl;
    
}


bool operator==(const Game& game1, const Game& game2){
    return *game1.gameMap==*game2.gameMap;
}