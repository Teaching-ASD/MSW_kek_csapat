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
#include <variant>
#include <list>



class JSON
{    


    enum class Regex_Type {
        jsonObject,
        jsonIntReg,
        jsonFloatReg,
        jsonStringReg,
        jsonList,
        IntReg,
        FloatReg,
        StringReg     
    };

    static const std::map<Regex_Type, std::regex> regmap;
    static std::smatch matches;
  
    std::map<std::string, std::any> jsonData;

public:

    typedef std::variant<int, double, std::string> v;
	typedef std::list<v> list;
  
    JSON()=default;
    explicit JSON(const std::map<std::string/**[in] this is string parameter */, std::any/**[in] this is any parameter */>& jsonData);
    bool count(std::string key) const;
    
    template<typename T/**[in] this is a name of T template */>
    T get(std::string key/**[in] this is a input key, what is in the map*/) const;
     /**
    * \return correct type value, from json.
    */
    ///This is the string parser
    static JSON parseFromString(std::string str/**[in] this is string parameter */); 
    ///This is the file parser
    static JSON parseFromFile(std::string file/**[in] this is file parameter */);
    ///This is the istream parser
    static JSON parseFromIstream(std::istream& is/**[in] this is istring& parameter */);
    
    struct ParseException {};    

private:
    static JSON parser(std::string json/**[in] this is a string parameter */);
    static void regexParser(std::string s, std::map<std::string, std::any>& jdm, Regex_Type rt ,std::regex reg);///<This regexParser extract date from json format. 
    static std::string findeJsonObject(std::string json);
    static void makeJsonList(std::map<std::string, std::any>& jdm, std::string key, std::string value);
};


template<typename T>
inline T JSON::get(std::string key) const {

    try{
        return std::any_cast<T>(jsonData.at(key));
    }
    catch(std::bad_any_cast& bc){
        throw JSON::ParseException();
    }
}



#endif //JSON_H