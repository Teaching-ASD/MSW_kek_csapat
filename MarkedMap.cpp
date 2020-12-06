#include "MarkedMap.h"
#include <filesystem>
#include <fstream>

MarkedMap::MarkedMap() : Map() {
}

MarkedMap::MarkedMap(const std::string& filename) : Map(filename){

}

MarkedMap::~MarkedMap(){}

Pos MarkedMap::getHeroPosition() const {
    Pos pos;
    for(std::size_t row=0; row<storedGameMap.size(); row++){
        for(std::size_t col = 0; col < storedGameMap.at(row).size(); col++){
            if(storedGameMap.at(row).at(col)==Map::type::Hero) {
                pos.set(row,col);
                return pos;  
            }
        }
    }
    return pos;
}

std::list<Pos> MarkedMap::getMonsterPositions(char c) const {
    std::list<Pos> monsters;
    Pos pos;
    for(std::size_t row=0; row<storedGameMap.size(); row++){
        for(std::size_t col = 0; col < storedGameMap.at(row).size(); col++){
                if(storedGameMap.at(row).at(col)==c) {
                    pos.set(row,col);
                    monsters.push_back(pos);
                }
        }
    }
    return monsters;
}


