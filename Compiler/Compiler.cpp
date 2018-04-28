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

                if(CheckingLogicStageResult)
                    createBinaryFile(logic.array);
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


bool
Compiler::createBinaryFile(std::vector<LogicElement> logicResult) {
    std::string file = getFile("\\a.isw");
    std::ofstream fout (file , std::ios::binary);

    if(!fout.is_open()) {return false;}
    else {
        for(std::vector<LogicElement>::iterator it = logicResult.begin(); it != logicResult.end(); ++it) {
            size_t value = it->getValue(1);
            fout.write(reinterpret_cast<char*>(&value), sizeof value);

            value = it->getValue(2);
            fout.write(reinterpret_cast<char*>(&value), sizeof value);

            value = it->getValue(3);
            fout.write(reinterpret_cast<char*>(&value), sizeof value);
        }

        fout.close();
    }

    return  true;
}