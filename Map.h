#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <stdexcept>
  
  

class Map {

public:
	typedef enum type 
	{ 
		Wall='#',
		Free=' ',
		Monsters='M',
		Hero='H',
		Monster='m',
		Monster1 = '1',
		Monster2 = '2',
		Monster3 = '3',
	}type;

protected:
	std::vector<std::string> storedGameMap;
	std::size_t width=0;

public:
	Map();
    Map(const std::string& filename);
	virtual Map::type get(int x, int y)const;
	std::size_t getWidth() const;
	std::size_t getHeight() const;
	std::size_t getRowLenght(int r)const;
	virtual void setBlock(Map::type t, int x, int y);

	class WrongIndexException : virtual public std::runtime_error {
		public:
		    explicit WrongIndexException(const std::string& msg) : std::runtime_error("Wrong index: " + msg) {}
	};

	class FileException : virtual public std::runtime_error {
		public:
		    explicit FileException(const std::string& msg) : std::runtime_error("File exception: " + msg) {}
	};

	friend bool operator==(const Map& map1, const Map& map2);

};



#endif //MAP_H