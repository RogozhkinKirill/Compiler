#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H


#include "Tokenizator/Tokenizator.h"
#include "Checker/Checker.h"
#include "Logic/Logic.h"

class Compiler {
public:
    Compiler() {}
    Compiler(std::string file) {compiling(file);}
   ~Compiler() {}

    bool compiling(std::string file);

private:
    //1st STAGE
    Tokenizator tokenizator;
    //2nd STAGE
    Checker checker;
    //3rd STAGE
    Logic logic;

    std::map<std::string , size_t> jumps;
    std::map<std::string , size_t> variables;

    bool createBinaryFile(std::vector<LogicElement> LogicResult);
};


#endif //COMPILER_COMPILER_H
