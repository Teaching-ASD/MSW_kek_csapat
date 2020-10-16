#ifndef GAME_H
#define GAME_H


#include "Player.h"
#include <vector>

#define PLAYER_NUMBER 2

class Game
{
	std::vector<Player*> players;

public:
	Game(char** argv);
    Game(std::istream& s);
    Game(std::string, std::string);
	~Game();
    void Fight();
private:
    bool isEnd() const;
    std::string toString();
    std::string getResult();

};
#endif