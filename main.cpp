#include <iostream>
#include <fstream>
#include <array>
#include "Compiler/Tokenizator/Tokenizator.h"

int main() {

    std::ifstream fin ("D:\\Study\\Programming\\Projects\\Test\\Test.txt");
    if(fin.is_open() ) {
        Tokenizator tkn(&fin);

        tkn.printArrayToFile();
        fin.close();
    }

    return 0;
}
