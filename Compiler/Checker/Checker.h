//
// Created by пользователь on 29.03.2018.
//

#ifndef COMPILER_CHECKER_H
#define COMPILER_CHECKER_H


#include <string>
#include <vector>
#include "../Tokenizator/Tokenizator.h"
#include "../Language.h"

struct CheckerElement {
public:
    CheckerElement(std::string name , size_t line , _flags flag) :
            name(name) , line(line) , flag(flag) {}
   ~CheckerElement() {}

    std::string getToken() {return name;}
    size_t      getLine()  {return line;}
    size_t      getFlag()  {return flag;}

protected:
    std::string name;
    size_t line;
    _flags flag;
};

class Checker {
public:
    std::vector<CheckerElement> array;
    std::vector<CheckerElement> error;

    Checker();
   ~Checker();

    bool checking(std::vector<Tokens> tokens);

    bool isFunction(Tokens token);
    bool isNumber(Tokens token);
    bool isRegister(Tokens token);
};


#endif //COMPILER_CHECKER_H
