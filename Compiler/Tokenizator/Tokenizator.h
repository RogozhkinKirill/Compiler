//
// Created by пользователь on 29.03.2018.
//

#ifndef COMPILER_TOKENIZATOR_H
#define COMPILER_TOKENIZATOR_H

#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <afxres.h>
#include <iostream>

#include "../Language.h"
#include "../../debug_log.h"
#include "../../errors_warning.h"


class Tokenizator {
public:
    std::vector<std::pair<std::string , size_t> > array;
    std::vector<std::pair<std::string , size_t> > errors;
//    ValidSymbols language;
    size_t line;

    Tokenizator();
    Tokenizator(std::ifstream* file);

    ~Tokenizator();

    bool FileToString(std::ifstream* file);
    bool StringToTokens(std::string str);

    bool printArrayToConsole();
    bool printArrayToFile();

    inline bool deleteComment(std::string* str , bool* isComment);
    inline bool deleteOneLineComment(std::string*);
    inline bool deleteMultiLineComments(std::string* str , bool* isComment);
};


#endif //COMPILER_TOKENIZATOR_H
