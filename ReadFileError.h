#ifndef READ_FILE_ERROR_H
#define READ_FILE_ERROR_H

#include <stdexcept>
#include <string>

class ReadFileError : virtual public std::runtime_error {

public:
    
    explicit ReadFileError(const std::string& fileName) : std::runtime_error("File not found file or cannot be opened: " + fileName){}

};
#endif