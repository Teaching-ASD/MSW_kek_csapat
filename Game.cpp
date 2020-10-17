#include "Game.h"
#include <sstream>
#include <iostream>

Game::Game(Player* c1, Player* c2)
{
    players.push_back(c1);
    players.push_back(c2);
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

        switch (round)
        {
        case true:
               players[1]->DMG(players[0]);
               players[0]->increaseXP();
               players[1]->increaseXP();
               round=false;
            break;
        
        case false:
               players[0]->DMG(players[1]);
               players[1]->increaseXP();
               players[0]->increaseXP();
               round=true;
            break;
        }
    }

    std::cout << getResult() << std::endl;

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
        players[0]->increaseXP();
    }
    else {
        result = players[1]->getName() + " win. Remain hp: " + std::to_string(players[1]->getHP()); 
        players[1]->increaseXP();
    }

    return result;

}
