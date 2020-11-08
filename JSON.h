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

#ifndef JSON_H
#define JSON_H

#include <map>
#include <any>
#include <string>
#include <regex>


class JSON
{    
    
    std::map<std::string, std::any> jsonData;
    enum Regex_Type {intr, stringr, floatr};

public:

    JSON()=default;
    JSON(std::map<std::string, std::any> jsonData);
    bool count(std::string key) const;
    
    template<typename T>
    T get(std::string key) const;

    static JSON parseFromString(std::string str/**[in] this is string parameter */); 
    static JSON parseFromFile(std::string file/**[in] this is isstring& parameter */);
    static JSON parseFromIstream(std::istream& is/**[in] this is isstring& parameter */);
    
    struct ParseException : public std::exception {};    

private:
    static JSON parser(std::string json/**[in] this is a string parameter */);
    static void regexParser(std::smatch matches, std::string s, std::map<std::string, std::any>& jdm, std::regex reg, Regex_Type rt);///<This regexParser extract date from json format. 

};


template<typename T>
inline T JSON::get(std::string key) const {

    T value;

    try{
        value = std::any_cast<T>(jsonData.at(key));
        return value;
    }
    catch(std::bad_any_cast& bc){
        throw JSON::ParseException();
    }
}



#endif