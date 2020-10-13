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

        

   float pl1=players[0]->getAtksp();
   float pl2=players[1]->getAtksp();
   bool firstRound = true;
    while(!isEnd()){
        if(firstRound){
            
        players[1]->DMG(players[0]);
        if(players[1]->getHP()<=0){
                    continue;
        }
        players[0]->DMG(players[1]);
        firstRound=false;
        }
        else{
            if(pl1==pl2){
                players[1]->DMG(players[0]);
                if(players[1]->getHP()<=0){
                    continue;
                }
                players[0]->DMG(players[1]);
                
                pl1=players[0]->getAtksp();
                pl2=players[1]->getAtksp();          
            }
            if(pl1<pl2){
                pl2-=pl1;
                players[1]->DMG(players[0]);
                
                pl1=players[0]->getAtksp();
                }
            else if(pl2<pl1){
                pl1-=pl2;
                players[0]->DMG(players[1]);
                
                pl2=players[1]->getAtksp();
            }
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
    }
    else {
        result = players[1]->getName() + " win. Remain hp: " + std::to_string(players[1]->getHP()); 
    }

    return result;

}
