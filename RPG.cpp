#include <iostream>
#include "Game.h"

int main(int argc, char** argv)
{
    if (argc == 1) {
        std::cerr << "Nem adott meg parametert!" << std::endl;
    }

    else if (argc < 7) {
        std::cerr << "Nem adott meg eleg adatot!" << std::endl;
    }

    else {

        Game* game = new Game(argv);
        game->Fight();
        delete game;
        
    }
}