#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <fstream>

#include "PreparedGame.h"
#include "ObserverTextRenderer.h"
#include "HeroTextRenderer.h"
#include "CharacterSVGRenderer.h"
#include "ObserverSVGRenderer.h"





const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." }
};

void bad_exit(int exitcode){
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char** argv){
    if (argc != 2) bad_exit(1);
    if (!std::filesystem::exists(argv[1])) bad_exit(2);

    std::ofstream file("log.txt");
    std::string SVGFile1 = "Character.svg";
    std::string SVGFile2 = "Observer.svg";

    try {
        PreparedGame pg(argv[1]);
        pg.registerRenderer(new ObserverTextRenderer(file));
        pg.registerRenderer(new HeroTextRenderer());
        pg.registerRenderer(new CharacterSVGRenderer(SVGFile1));
        pg.registerRenderer(new ObserverSVGRenderer(SVGFile2));
        pg.run();
    } 
    catch (const std::exception& ex ){
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
