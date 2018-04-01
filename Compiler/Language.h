//
// Created by пользователь on 31.03.2018.
//

#ifndef COMPILER_LANGUAGE_H
#define COMPILER_LANGUAGE_H

#include <string>
#include <map>

#define language_symbols(str , name) const std::string name = str;

//Special symbols
language_symbols(";" , __ONE_LINE_COMMENT__);
language_symbols("/;" , __BEGIN_MULTY_LINE_COMMENT__);
language_symbols(";/" , __END_MULTY_LINE_COMMENT__);

//Valid symbols
/*class ValidSymbols {
    std::map validSymbols;
    std::map validFunctions;

public:
    ValidSymbols();
    ValidSymbols(std::string fileWithLanguage);

   ~ValidSymbols();

    bool IsValidToken(std::string str);
};
*/
//Exceptions

#endif //COMPILER_LANGUAGE_H
