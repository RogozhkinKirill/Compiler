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
    CheckerElement(size_t name , size_t line , _flags flag) :
            name(name) , line(line) , flag(flag) {}
   ~CheckerElement() {}

    size_t getName() {return name;}
    size_t getLine() {return line;}
    _flags getFlag() {return flag;}

protected:
    size_t name;
    size_t line;
    _flags flag;
};

class Checker : public Language {
public:
    std::vector<CheckerElement> array;
    std::vector<Tokens> error;

    Checker() : Language() {}
    Checker(std::vector<Tokens> tokens) : Language() {checking(tokens);}
   ~Checker() {}

    bool checking(std::vector<Tokens> tokens);

    bool printArrayToConsole();
    bool printArrayToFile();
};


#endif //COMPILER_CHECKER_H
