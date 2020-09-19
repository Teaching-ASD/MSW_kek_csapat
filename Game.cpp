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

void Game::Fight()
{
    bool round=true;


    while(!isEnd()){

        std::cout << toString();

        switch (round)
        {
        case true:
            std::cout << players[0]->getName() << "->" << players[1]->getName() << std::endl;
            players[0]->DMG(players[1]);
            round = false;
            break;
        
        case false: 
            std::cout << players[1]->getName() << "->" << players[0]->getName() << std::endl;
            players[1]->DMG(players[0]);
            round = true;
            break;
        }
    }

    std::cout << toString();
    std::cout << getResoult();

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

std::string Game::getResoult()
{
    
    std::string resoult = "";


    if(players[0]->getHP()>players[1]->getHP()){
        resoult = players[1]->getName() + " died. " + players[0]->getName() + " win.\n";
    }
    else if(players[0]->getHP()<players[1]->getHP()){
        resoult = players[0]->getName() + " died. " + players[1]->getName() + " win.\n";
    }
    else {
        resoult = "draw.";
    }

    return resoult;

}