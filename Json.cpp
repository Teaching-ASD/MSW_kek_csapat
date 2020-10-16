#include "Json.h"
#include "ReadFileError.h"

#include <fstream>


std::map<std::string, std::any>  Json::JsonParser(std::string fileOrString)
{
    if (fileOrString.find_first_of("{") != std::string::npos){
        return Json::Parser(fileOrString);
    }

    std::ifstream jsonFile(fileOrString);

    if (jsonFile.fail()){
        throw ReadFileError(fileOrString);
    }

    return Json::JsonParser(jsonFile);
}

std::map<std::string, std::any>  Json::JsonParser(std::istream& InputStream){
    
    return Json::Parser(std::string(std::istreambuf_iterator<char>(InputStream), {}));
}


std::map<std::string, std::any> Json::Parser(std::string json) {
    
    std::smatch matches;
    std::regex objectRegex("\\{([\\s\\S]*)\\}");
    std::regex_search(json, matches, objectRegex);
    std::string oneObject = matches.str(1);

    std::map<std::string, std::any>  jdm;
   
   std::regex floatReg("\"([^\"]*)\" *: *([-+]?\\d+\\.\\d+)");
   std::regex strReg("\"([^\"]*)\" *: *\"([^\"]*)\"");
   std::regex intReg("\"([^\"]*)\" *: *(\\d+)");

    regexParser(matches,oneObject,jdm, strReg, Regex_Type::stringr);
    regexParser(matches,oneObject,jdm, floatReg, Regex_Type::floatr);
    regexParser(matches,oneObject,jdm, intReg, Regex_Type::intr);

    return jdm;
     
 }


 void Json::regexParser(std::smatch matches, std::string s, std::map<std::string, std::any>& jdm, std::regex reg, Regex_Type rt) {
 
    while (std::regex_search(s, matches, reg)) {
        if (!jdm[matches.str(1)].has_value()) {
            switch(rt){
            case stringr: 
              jdm[matches.str(1)] = matches.str(2);
              break;
            case floatr:
                jdm[matches.str(1)] = stof(matches.str(2));
                break;
            case intr:
                jdm[matches.str(1)] = stoi(matches.str(2));
                break;
            }
        }
        s = matches.suffix().str();
    }
}
