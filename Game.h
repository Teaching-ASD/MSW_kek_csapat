#ifndef GAME_H
#define GAME_H


#include "Player.h"
#include <vector>


class Game
{
	std::vector<Player*> players;

public:
	Game(char** argv);
	~Game();
    void Fight();
private:
    bool isEnd() const;
    std::string toString();
    std::string getResoult();

};
#endif