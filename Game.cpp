#include "Game.h"
#include <sstream>
#include <iostream>

Game::Game(char** argv)
{
    std::stringstream ss;
    std::string p1, p2;
    short hp1, hp2, dmg1, dmg2;

    for (argv++; *argv != NULL; ++argv) {
        ss << *argv << '\n';
    }

    ss >> p1 >> hp1 >> dmg1;
    ss >> p2 >> hp2 >> dmg2;

    players.push_back(new Player(p1, hp1, dmg1));
    players.push_back(new Player(p2, hp2, dmg2));

}

Game::~Game()
{

    for (auto player : players)
    {
        delete player;
    }
 
}


std::string Game::toString()
{
    std::string status = "";

    for(auto player : players){
        status += player->toString() + "\n";
    }

    return status;
}