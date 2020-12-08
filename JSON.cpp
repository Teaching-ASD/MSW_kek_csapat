#include "JSON.h"
#include <fstream>



const std::map<JSON::Regex_Type, std::regex> JSON::regmap = {
{Regex_Type::jsonStringReg,  std::regex("\"([^\"]*)\" *: *\"([^\"]*)\"")},
{Regex_Type::jsonFloatReg, std::regex("\"([^\"]*)\" *: *([-+]?\\d+\\.\\d+)")},
{Regex_Type::jsonIntReg, std::regex("\"([^\"]*)\" *: *(\\d+)")},
{Regex_Type::jsonList, std::regex("\"([^\"]*)\" *: *\\[([\\s\\S]*)\\]")},
{Regex_Type::StringReg, std::regex("\"([^\"]*)\"")},
{Regex_Type::FloatReg, std::regex("([-+]?\\d+\\.\\d+)")},
{Regex_Type::IntReg, std::regex("([-+]?\\d+)")},
{Regex_Type::jsonObject, std::regex("\\{([\\s\\S]*)\\}")},
};

std::smatch JSON::matches;

JSON::JSON(const std::map<std::string, std::any>& jsonData) : jsonData(jsonData){

}

JSON::~JSON() {
    jsonData.clear();
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

std::string JSON::findeJsonObject(std::string json){
    std::regex_search(json, matches, regmap.at(Regex_Type::jsonObject));
    std::string oneObject = matches.str(1);
    return oneObject;
}

JSON JSON::parser(std::string json) {

    std::string oneObject = JSON::findeJsonObject(json);
   
    std::map<std::string, std::any> jdm;

    Regex_Type regTypArray[4] = 
    {
        Regex_Type::jsonStringReg, 
        Regex_Type::jsonFloatReg,
        Regex_Type::jsonIntReg,
        Regex_Type::jsonList
    };

    for(int i=0; i<4 ; i++){ 
        regexParser(oneObject,jdm, regTypArray[i], regmap.at(regTypArray[i]));
    }

    JSON jsonObject(jdm);

    return jsonObject;
     
 }


void JSON::regexParser(std::string s, std::map<std::string, std::any>& jdm, Regex_Type rt ,std::regex reg) {

    while (std::regex_search(s, matches, reg)) {
         if (!jdm[matches.str(1)].has_value()) {
            switch(rt){
            case Regex_Type::jsonStringReg: 
              jdm[matches.str(1)] = matches.str(2);
              break;
            case Regex_Type::jsonFloatReg:
                jdm[matches.str(1)] = stod(matches.str(2));
                break;
            case Regex_Type::jsonIntReg:
                jdm[matches.str(1)] = stoi(matches.str(2));
                break;
            case Regex_Type::jsonList:
                JSON::makeJsonList(jdm , matches.str(1), matches.str(2));
                break;
            default:
                break;
            }
        }
        s = matches.suffix().str();
    }
}

void JSON::makeJsonList(std::map<std::string, std::any>& jdm, std::string key, std::string value){
    
    JSON::list jl;
    
    while(std::regex_search(value, matches, regmap.at(Regex_Type::StringReg))){
        jl.push_back(matches.str(1));
        value = matches.suffix().str();
    }

    if(!jl.empty()) jdm[key]=jl;

    while(std::regex_search(value, matches, regmap.at(Regex_Type::FloatReg))){
        jl.push_back(stod(matches.str(1)));
        value = matches.suffix().str();
    }

    if(!jl.empty()) jdm[key]=jl;

    while(std::regex_search(value, matches, regmap.at(Regex_Type::IntReg))){
        jl.push_back(stoi(matches.str(1)));
        value = matches.suffix().str();
    }

    if(!jl.empty()) jdm[key]=jl;

}