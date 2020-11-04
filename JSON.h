/**
 * \class Json
 * 
 * \ingroup Example package
 *  
 * \brief Json class
 * 
 * This is a Json class. Contain static methods for parser data from json format.
 *  
 * \author smauzerrichard (smauzer.richard47@gmail.com)
 * \version 1.0
 * \date 2020-10-13
 * 
 */



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
  
    static std::map/**[in] this is a map parameter*/<std::string /**[in] this is a string parameter*/, std::any/**[in] this is any parameter*/>  JsonParser(std::string fileOrString/**[in] this is string parameter */); 
    static std::map/**[in] this is a map parameter*/<std::string /**[in] this is a string parameter*/, std::any/**[in] this is any parameter*/>  JsonParser(std::istream& InputStream/**[in] this is isstring& parameter */);


private:
    static std::map/**[in] this is a map parameter*/<std::string/**[in] this is a string parameter*/, std::any/**[in] this is any parameter*/>  Parser(std::string json/**[in] this is a string parameter */);
    static void regexParser(std::smatch matches, std::string s, std::map<std::string, std::any>& jdm, std::regex reg, Regex_Type rt);///<This regexParser extract date from json format. 



};
#endif