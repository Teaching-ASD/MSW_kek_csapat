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
    bool round=true;


    while(!isEnd()){

        std::cout << toString();

        switch (round)
        {
        case true:
            std::cout << players[0]->getName() << "->" << players[1]->getName() << std::endl;
            players[1]->DMG(players[0]);
            round = false;
            break;
        
        case false: 
            std::cout << players[1]->getName() << "->" << players[0]->getName() << std::endl;
            players[0]->DMG(players[1]);
            round = true;
            break;
        }
    }

    std::cout << toString();
    std::cout << getResult();

}

bool Game::isEnd() const
{
    bool end = false;

    for (auto player : players){
        if(player->getHP()<=0){
            end = true;
        }
    }
    return end;



}

std::string Game::toString()
{
    std::string status = "";

    for(auto player : players){
        status += player->toString() + "\n";
    }

    return status;
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
