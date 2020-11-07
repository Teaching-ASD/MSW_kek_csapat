
OBJS := Character.o Hero.o JSON.o main.o Monster.o
CFLAGS := -std=c++17
CC := g++

default: build

build: $(OBJS)
	$(CC) $(CFLAGS) -o add $(OBJS)

Character.o: Character.cpp
	$(CC) $(CFLAGS) -c Character.cpp

Hero.o: Hero.cpp
	$(CC) $(CFLAGS) -c Hero.cpp

JSON.o: JSON.cpp
	$(CC) $(CFLAGS) -c JSON.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Monster.o: Monster.cpp
	$(CC) $(CFLAGS) -c Monster.cpp

doc:
	doxygen Doxyfile

clean:
	rm -rf *.o add ./html ./latex