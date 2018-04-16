#include "Compiler.h"

Compiler::Compiler(std::string file) {
    std::ifstream fin (file);
    if(fin.is_open() ) {
        tokenizator.FileToString(&fin);
        tokenizator.printArrayToFile();

        if(tokenizator.errors.empty()) {
            checker.checking(tokenizator.array);
            checker.printArrayToFile();

            if (checker.error.empty()) {

            }
        }
    }
}