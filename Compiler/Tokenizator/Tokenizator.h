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


struct Tokens {
public:
    Tokens(std::string str , size_t line) :
            token(str),
            line(line) {}
    ~Tokens() {}

    std::string getToken() {return token;}
    size_t getLine() {return line;}

protected:
    std::string token;
    size_t line;

};


class Tokenizator {
public:
    std::vector<Tokens> array;
    std::vector<Tokens> errors;
    size_t line;

    Tokenizator();
    Tokenizator(std::ifstream* file);

    ~Tokenizator();

    bool tokenizing(std::ifstream* file);
    bool printArrayToConsole();
    bool printArrayToFile();
protected:
    bool FileToString(std::ifstream* file);

    bool StringToTokens(std::string str);

    inline bool deleteComment(std::string* str , bool* isComment);
    inline bool deleteOneLineComment(std::string*);
    inline bool deleteMultiLineComments(std::string* str , bool* isComment);
};

#endif //COMPILER_TOKENIZATOR_H
