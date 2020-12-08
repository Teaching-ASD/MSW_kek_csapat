#include "Map.h"
#include <filesystem>
#include <fstream>
#include <cstddef>

Map::Map(){
    
}

Map::Map(const std::string& filename){
    
     if (std::filesystem::exists(filename)){
        std::ifstream file(filename);
        if(file.is_open()){
            std::string rawRow;
            while(std::getline(file, rawRow)){
                std::size_t found = rawRow.find_last_of('#');
                std::string row = rawRow.substr(0,found+1); 
                if(row.size()>width) width=row.size();
                storedGameMap.push_back(row);
            }
            file.close();
        }
     }
    else throw Map::FileException("file is not accessible.");
}

Map::~Map() {}

Map::type Map::get(int x, int y) const {
    try{
        return (Map::type) storedGameMap.at(x).at(y);
    }
    catch (std::out_of_range& out){
        throw Map::WrongIndexException("Out of range.");
    }
}


void Map::setBlock(type t, int x, int y){
    
    try{
          storedGameMap.at(x).at(y) = t;
    }
    catch(std::out_of_range& oor){
        throw Map::WrongIndexException("Out of range.");
    }
}


bool operator==(const Map& map1, const Map& map2){
    
    bool equal = false;
    equal = map1.storedGameMap.size()==map2.storedGameMap.size();
    for(std::size_t r=0; r<map1.storedGameMap.size() && equal; r++){
            equal = map1.storedGameMap[r].size()==map2.storedGameMap[r].size();

    for(std::size_t c=0; c < map1.storedGameMap[r].size() && equal; c++)
                    equal = map1.storedGameMap[r][c]==map2.storedGameMap[r][c];
    }
    
    return equal;

}

std::size_t Map::getWidth() const{
    return width;
}

std::size_t Map::getHeight() const{
    return storedGameMap.size();
}

std::size_t Map::getRowLenght(int r)const{
    try{
        return storedGameMap.at(r).size();
    }
    catch (std::out_of_range& e){
        throw Map::WrongIndexException("Out of range.");
    }
}
