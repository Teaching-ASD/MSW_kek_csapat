#ifndef PREPARED_GAME_H
#define PREPARED_GAME_H

#include "Game.h"
#include "MarkedMap.h"


class PreparedGame : public Game {

 MarkedMap* gameMarkedMap;

public:
    PreparedGame(const std::string& filename);
    void storeAllMonster(const std::string& monsterType, char monsterChar);
    ~PreparedGame();

};



#endif // PREPARED_GAME_H