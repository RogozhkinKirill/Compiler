//
// Created by пользователь on 29.03.2018.
//

#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H


#include "Tokenizator/Tokenizator.h"
#include "Checker/Checker.h"

class Compiler {
public:
    Tokenizator tokenizator;
    Checker checker;

    Compiler() {}
   ~Compiler() {}
};


#endif //COMPILER_COMPILER_H
