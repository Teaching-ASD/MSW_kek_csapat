#include "JSON.h"
#include <fstream>
#include <iostream>


JSON::JSON(const std::map<std::string, std::any>& jsonData) : jsonData(jsonData){

}

bool JSON::count(std::string key) const{
    return jsonData.count(key);
}



JSON JSON::parseFromString(std::string str){

   return JSON::parser(str);

}

JSON JSON::parseFromFile(std::string file){

    std::ifstream jsonFile(file);
    return JSON::parseFromIstream(jsonFile);

}


JSON JSON::parseFromIstream(std::istream& is){

    return JSON::parser(std::string(std::istreambuf_iterator<char>(is), {}));

}

JSON JSON::parser(std::string json) {
    
    std::smatch matches;
    std::regex objectRegex("\\{([\\s\\S]*)\\}");
    std::regex_search(json, matches, objectRegex);
    std::string oneObject = matches.str(1);
    std::map<std::string, std::any> jdm;
   
    std::regex floatReg("\"([^\"]*)\" *: *([-+]?\\d+\\.\\d+)");
    std::regex strReg("\"([^\"]*)\" *: *\"([^\"]*)\"");
    std::regex intReg("\"([^\"]*)\" *: *(\\d+)");

    regexParser(matches,oneObject,jdm, strReg, Regex_Type::stringr);
    regexParser(matches,oneObject,jdm, floatReg, Regex_Type::floatr);
    regexParser(matches,oneObject,jdm, intReg, Regex_Type::intr);

    JSON jsonObject(jdm);

    return jsonObject;
     
 }


void JSON::regexParser(std::smatch matches, std::string s, std::map<std::string, std::any>& jdm, std::regex reg, Regex_Type rt) {
 

    while (std::regex_search(s, matches, reg)) {
        if (!jdm[matches.str(1)].has_value()) {
            switch(rt){
            case stringr: 
              jdm[matches.str(1)] = matches.str(2);
              break;
            case floatr:
                jdm[matches.str(1)] = stod(matches.str(2));
                break;
            case intr:
                jdm[matches.str(1)] = stoi(matches.str(2));
                break;
            }
        }
        s = matches.suffix().str();
    }
}
