#include "Compiler.h"

bool
Compiler::compiling(std::string file) {
    std::ifstream fin (file);
    if(fin.is_open() ) {
        bool TokenizingStageResult = tokenizator.tokenizing(&fin);
        tokenizator.printArrayToFile();

        if(TokenizingStageResult) {
            bool CheckingStageResult = checker.checking(tokenizator.array);
            checker.printArrayToFile();

            if(CheckingStageResult ) {
                bool CheckingLogicStageResult = logic.checkLogic(checker.array);
                logic.printArrayToFile();
            }
        }

        fin.close();
    }
    else {
        std::cout << "Maybe next time I will work" << std::endl;
        //Time delay
        for(int i=0; i<700000000; ++i) {}
        std::cout << "File does not exist..." << std::endl;
        std::cout << "Try again" << std::endl;
    }
}