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

