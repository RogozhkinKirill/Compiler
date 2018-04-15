#include <iostream>
#include <fstream>
#include <array>
#include "Compiler/Tokenizator/Tokenizator.h"
#include "Compiler/Checker/Checker.h"

int main() {

    std::ifstream fin ("D:\\Study\\Programming\\Projects\\C_C++\\ILab\\Compiler\\Test.txt");
    if(fin.is_open() ) {
        Tokenizator tkn(&fin);
        tkn.printArrayToFile();

        if(tkn.errors.empty() ) {
            Checker chr(tkn.array);
            chr.printArrayToFile();
        }

        fin.close();
    }


    return 0;
}
