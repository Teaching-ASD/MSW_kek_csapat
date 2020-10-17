#include "Game.h"
#include <sstream>
#include <iostream>

Game::Game(Player* p1, Player* p2)
{
    players.push_back(p1);
    players.push_back(p2);
}

Game::~Game()
{

    for (auto player : players)
    {
        delete player;
    }
 
}

void Game::Fight()
{
  
    while(!players[0]->Combat(players[1]));
           
    std::cout << getResult() << std::endl;
}


std::string Game::getResult()
{
    
    std::string result;
    
    if(players[0]->getHP() > 0 ){
        result = players[0]->getName() + " win. Remain hp: " + std::to_string(players[0]->getHP()); 
    }
    else {
        result = players[1]->getName() + " win. Remain hp: " + std::to_string(players[1]->getHP()); 
    }

    return result;

}
