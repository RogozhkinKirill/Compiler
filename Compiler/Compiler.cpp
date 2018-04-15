#include "Compiler.h"

Compiler::Compiler(std::string file) {
    std::ifstream fin (file);
    if(fin.is_open() ) {
        tokenizator.(&fin);
        tokenizator.printArrayToFile();

        if(!tokenizator.errors.empty()) {
        }

        fin.close();
    }
}