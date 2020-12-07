#ifndef RENDERER_H
#define RENDERER_H

#include "Game.h"

class Game;

class Renderer {

public:
    virtual void render(const Game& ) const=0;
};


#endif // RENDERER_H