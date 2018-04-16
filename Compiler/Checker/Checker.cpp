#include "Checker.h"


/***
 * Compare token with code
 *
 * @param tokens from Tokenizator
 * @return
 */
bool
Checker::checking(std::vector<Tokens> tokens)
{
    for(int i=0; i<tokens.size(); ++i) {
        LanguageElement* element = what(tokens[i].getToken());

        if(element == nullptr)
            return FALSE;
        else {
            if(element->flag == ERROR_)
                error.push_back(tokens[i] );
            else
                array.push_back(CheckerElement(element->code , tokens[i].getLine() , element->flag) );
        }
    }

    return TRUE;
}


bool
Checker::printArrayToFile(void) {
    std::string file = getFile("\\Test_result.txt");
    std::ofstream fout(file ,  std::ofstream::out | std::ofstream::app);

    if(fout.is_open()) {
        size_t lenght = array.size();
        size_t lenghtErr = error.size();

        fout << std::endl;
        fout << std::endl;
        fout << "================================================================================" << std::endl;
        fout << "                         Result of Checker                                      " << std::endl;
        fout << "TOKENS:                                                                         " << std::endl;
        fout << std::endl;

        for(int i=0; i<lenght; ++i) {
            char str[10];
            fout << "Name: " << i << " 0x" << itoa(array[i].getName() , str , 16)                  << std::endl;
            fout << "Flag: " << i << " " << flagToString(array[i].getFlag())                       << std::endl;
            fout << "Line: " << array[i].getLine()                                                 << std::endl;
            fout << std::endl;
        }

        fout << std::endl;
        fout << "ERROR:"                                                                          << std::endl;
        fout << std::endl;
        for(int i=0; i<lenghtErr; ++i) {
            fout << "Error: " << i << " " << error[i].getToken()                                  << std::endl;
            fout << "Line: " << error[i].getLine()                                               << std::endl;
        }
        fout << std::endl;

        fout << "================================================================================" << std::endl;
        fout << std::endl;
        fout << std::endl;

        fout.close();
    }
}

bool
Checker::printArrayToConsole(void) {
    size_t lenght = array.size();
    size_t lenghtErr = error.size();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "                         Result of Checker                                      " << std::endl;
    std::cout << "TOKENS:                                                                         " << std::endl;
    std::cout << std::endl;

    for(int i=0; i<lenght; ++i) {
        std::cout << "Name: " << i << " " << array[i].getName()                                     << std::endl;
        std::cout << "Flag: " << i << " " << array[i].getFlag()                                     << std::endl;
        std::cout << "Line: " << array[i].getLine()                                                 << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "ERROR:"                                                                          << std::endl;
    for(int i=0; i<lenghtErr; ++i) {
        std::cout << "Error: " << i << " " << error[i].getToken()                                  << std::endl;
        std::cout << "Line: " << error[i].getLine()                                                << std::endl;
    }
    std::cout << std::endl;

    std::cout << "================================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}