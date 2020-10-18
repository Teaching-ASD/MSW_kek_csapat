/**
 * \class Game
 * 
 * \ingroup Example package
 *  
 * \brief Game class
 * 
 * This is a Game class. Game contain players and manange there methods in the game.
 * \author smauzerrichard (smauzer.richard47@gmail.com)
 * \version 1.0
 * \date 2020-10-13
 * 
 */


#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <vector>

#define PLAYER_NUMBER 2

class Game
{
	std::vector<Player*> players;///<Contain players in vector.

public:
	Game(char** argv/**[in] this is a char** parameter*/); ///<Game constructor from argument list.
    Game(std::istream& s/**[in] this is a ifstream& parameter*/); ///<Game constructor from istream.
    Game(std::string s1/**[in] this is a string parameter*/, std::string s2/**[in] this is a string parameter*/); ///<Game construktor from two string.
	~Game();///<This is Game destructor.
    void Fight(); ///<RPG fight between TWO Player.
private:
    bool isEnd() const; ///<Player hp is 0 return true. Help Fight loop.
    void printResult() const; ///<Print fight Result to stdo.

};
#endif