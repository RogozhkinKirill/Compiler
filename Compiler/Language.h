#ifndef COMPILER_LANGUAGE_H
#define COMPILER_LANGUAGE_H

#include <string>
#include <map>

#define language_symbols(str , name) const std::string name = str;
#define enum_code(code , name) name = code
#define ADD_FUNCTION(code , name) validFunctions.insert(std::pair<std::string , int> (name , code) );


//Special symbols
language_symbols(";" , __ONE_LINE_COMMENT__);
language_symbols("/;" , __BEGIN_MULTY_LINE_COMMENT__);
language_symbols(";/" , __END_MULTY_LINE_COMMENT__);


enum _flags {
    enum_code(0x0 , ERROR_),
    enum_code(0x1 , FUNCTION_),
    enum_code(0x2 , NUMBER_),
    enum_code(0x3 , REGISTER_),
    enum_code(0x4 , VARIABLE_)
};



//Valid symbols
class Language {

public:
    Language();
   ~Language() {}
    bool IsValidToken(std::string str);

private:
    std::map<std::string , std::string> validSymbols;
    std::map<std::string , std::string> validFunctions;
    std::map<std::string , std::string> registers;
};



#endif //COMPILER_LANGUAGE_H
