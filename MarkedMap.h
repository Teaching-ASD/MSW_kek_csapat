#ifndef MARKED_MAP_H
#define MARKED_MAP_H

#include "Map.h"
#include "Pos.h"
#include <list>

class MarkedMap : public Map {

public:
    MarkedMap();
    MarkedMap(const std::string& filename);
    Pos getHeroPosition() const;
    std::list<Pos> getMonsterPositions(char c) const;    
};


#endif //MARKED_MAP_H