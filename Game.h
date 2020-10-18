#ifndef GAME_H
#define GAME_H


#include "Player.h"
#include <vector>


class Game
{
	std::vector<Player*> players;

public:
	Game(Player* p1, Player* p2);
	~Game();
    void Fight();
private:
    bool isEnd() const;
    void printResult() const;

};
#endif