#ifndef COMPILER_LANGUAGE_H
#define COMPILER_LANGUAGE_H

#include <string>
#include <map>

#define language_symbols(str , name) const std::string name = str;
#define enum_code(code , name) name = code



//Special symbols
language_symbols(";" , __ONE_LINE_COMMENT__);
language_symbols("/;" , __BEGIN_MULTY_LINE_COMMENT__);
language_symbols(";/" , __END_MULTY_LINE_COMMENT__);


enum _flags {
    enum_code(0x0 , ERROR_),
    enum_code(0x1 , FUNCTION_),
    enum_code(0x2 , NUMBER_),
    enum_code(0x3 , REGISTER_),
    enum_code(0x4 , LABEL_),
    enum_code(0xff , VARIABLE_),

    enum_code(0xdd , NOTHING_)
};



class LanguageElement {
public:
    LanguageElement() {}
    LanguageElement(_flags flag , size_t code) : flag(flag) , code(code) {}

    virtual
   ~LanguageElement() {}

    _flags getFlag() {return flag;}
    size_t getCode() {return code;}

//protected:
    _flags flag;
    size_t code;
};


//Valid symbols
class Language : public LanguageElement {

public:
    Language();

    virtual
   ~Language() {}

    LanguageElement* what(std::string str);
    LanguageElement* isFunction(std::string str);
    LanguageElement* isRegister(std::string str);
    LanguageElement* isNumber(std::string str);

private:
    //TODO: come up an idea how to set valid simbols
    //std::map<std::string , std::string> validSymbols;
    std::map<std::string , size_t> validFunctions;
    std::map<std::string , size_t> registers;
};


std::string flagToString(_flags);

#endif //COMPILER_LANGUAGE_H
