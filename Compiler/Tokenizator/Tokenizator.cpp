//
// Created by пользователь on 29.03.2018.
//

#include "Tokenizator.h"

///Creators
Tokenizator::Tokenizator() {
    line = 0;
}
Tokenizator::Tokenizator(std::ifstream* file) {
    line = 0;
    FileToString(file);
}

///Destroyer
Tokenizator::~Tokenizator() {}

/**
 * Separate file to tokens and contain tokens to array in
 *              std::pair(first - string token, second - size_t line)
 *
 * @param file
 * @return TRUE if work finished correct
 *         FALSE if work finished incorrect
 */
bool
Tokenizator::FileToString(std::ifstream* file)
{
    std::string str;

    if(file->is_open()) {
        while(std::getline(*file , str) ) {
            ++line;
            StringToTokens(str);
        }
    }

    return TRUE;
}

bool
Tokenizator::StringToTokens(std::string str) {
    if(str.empty() == 0) {
        size_t comments = str.find(__ONE_LINE_COMMENT__);
        if(comments != str.npos)
            str.erase(comments , str.size());//Deleting One Line Comment

        char* tmp;
        char *cstr = new char[str.length() + 1];

        std::strcpy(cstr, str.c_str());
        tmp = strtok(cstr, " ");

        if (tmp != 0)
            while (tmp != NULL) {
                std::pair<std::string, size_t> pair(tmp, line);
                array.push_back(pair);
                tmp = strtok(NULL , " ");
            }
        else
            return FALSE;
        return TRUE;
    }

    return TRUE;
}

bool
Tokenizator::printArrayToConsole() {
    size_t lenght = array.size();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "                       Result of Tokenizator                                    " << std::endl;
    std::cout << "TOKENS                                                                          " << std::endl;
    std::cout << std::endl;

    for(int i=0; i<lenght; ++i) {
        std::cout << "Token: " << i << " " << array[i].first                                        << std::endl;
        std::cout << "Line: " << array[i].second                                                    << std::endl;
        std::cout << std::endl;
     }

    std::cout << "================================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

bool
Tokenizator::printArrayToFile() {
    std::string file = getFile("\\Tokenizator_result.txt");
    std::ofstream fout(file);

    if(fout.is_open()) {
        size_t lenght = array.size();

        fout << std::endl;
        fout << std::endl;
        fout << "================================================================================" << std::endl;
        fout << "                       Result of Tokenizator                                    " << std::endl;
        fout << "TOKENS                                                                          " << std::endl;
        fout << std::endl;

        for(int i=0; i<lenght; ++i) {
            fout << "Token: " << i << " " << array[i].first                                        << std::endl;
            fout << "Line: " << array[i].second                                                    << std::endl;
            fout << std::endl;
        }

        fout << "================================================================================" << std::endl;
        fout << std::endl;
        fout << std::endl;

        fout.close();
    }
}

