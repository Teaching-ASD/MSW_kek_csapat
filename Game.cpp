#include "Game.h"
#include <iostream>

Game::Game(char** argv)
{
   for(argv++; *argv!=NULL; argv++) {
   players.push_back(Player::parseUnit(*argv));
   }
}

Game::Game(std::istream& s)
{

    int i = 0;
    while (i < PLAYER_NUMBER) {
            std::cout << i+1 << ".Json: ";
            players.push_back(Player::parseUnit(s));
            s.clear();
            i++;
        }
}

Game::Game(std::string s1, std::string s2)
{
      players.push_back(Player::parseUnit(s1));
      players.push_back(Player::parseUnit(s2));
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




