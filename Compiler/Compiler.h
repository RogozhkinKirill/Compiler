//
// Created by пользователь on 29.03.2018.
//

#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H


#include "Tokenizator/Tokenizator.h"
#include "Checker/Checker.h"
#include "Logic/Logic.h"

class Compiler {
public:
    Tokenizator tokenizator;
    Checker checker;
    Logic logic;

    std::map<std::string , size_t> jumps;
    std::map<std::string , size_t> variables;

    Compiler() {}
    Compiler(std::string file);
    ~Compiler() {}
};


#endif //COMPILER_COMPILER_H
