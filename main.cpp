#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

#include "PreparedGame.h"
#include "ObserverTextRenderer.h"





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

    try { 
        PreparedGame pg(argv[1]);
        pg.registerRenderer(new ObserverTextRenderer());
        pg.run();
    } 
    catch (const std::exception& ex ){
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
