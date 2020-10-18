#include "Game.h"
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
        switch (round)
        {
        case true:
               players[1]->DMG(players[0]);
               players[0]->increaseXP(players[1]->getDMG());
               round=false;
            break;
        
        case false:
               players[0]->DMG(players[1]);
               players[1]->increaseXP(players[0]->getDMG());
               round=true;
            break;
        }
    }

    printResult();

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

void Game::printResult() const
{
    
    if(players[0]->getHP() > 0 ){
        std::cout << players[0]->getWinString();
        
    }
    else {
        std::cout << players[1]->getWinString(); 
     
    }
}
