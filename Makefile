add: Character.o Hero.o JSON.o main.o Monster.o
	g++ -Wall -o add Character.o Hero.o JSON.o main.o Monster.o

Character.o: Character.cpp
	g++ -Wall -c Character.cpp

Hero.o: Hero.cpp
	g++ -Wall -c Hero.cpp

JSON.o: JSON.cpp
	g++ -Wall -c JSON.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

Monster.o: Monster.cpp
	g++ -Wall -c Monster.cpp

doc:
	doxygen Doxyfile