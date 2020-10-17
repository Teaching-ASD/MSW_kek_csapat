#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <map>
#include <any>
#include <string>
#include <regex>



class Json
{    
    
    enum Regex_Type {intr, stringr, floatr};

public:
  
    static std::map<std::string, std::any>  JsonParser(std::string fileOrString); 
    static std::map<std::string, std::any>  JsonParser(std::istream& InputStream);


private:
    static std::map<std::string, std::any>  Parser(std::string json);
    static void regexParser(std::smatch matches, std::string s, std::map<std::string, std::any>& jdm, std::regex reg, Regex_Type rt);



};
#endif