OBJS := Character.o Hero.o JSON.o main.o Monster.o
CFLAGS := -std=c++17 -lstdc++fs -Wall -Wextra -g
FILES := Character.cpp Hero.cpp JSON.cpp main.cpp Monster.cpp
CC := g++
VLG := --error-exitcode=1 --leak-check=full 
TESTFLDR := UnitTest
JSON := ./Scenarios/scenario1.json 
STCD := --enable=warning,style,performance --error-exitcode=1 --output-file=cppcheck_report.txt

build: $(OBJS)
	$(CC) $(CFLAGS) -o build $(OBJS)

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
clean:
	rm -rf $(OBJS) build ./DOCS

doc:
	doxygen doxconf

valgrind: build
	valgrind $(VLG) ./build $(JSON) 

callgrid: build
	valgrind --tool=callgrind ./build $(JSON) 

staticCodaAnalysis:
	cppcheck $(FILES) $(STCD)

creategoogletest:
	$ (cd $(TESTFLDR) && cmake $(TESTFLDR) && make)

unittest: creategoogletest
	$ (cd $(TESTFLDR) && ./runTests)

test: valgrind callgrid unittest