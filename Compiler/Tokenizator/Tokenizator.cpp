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
IsValidToken(std::string tmp) {
    size_t lenght = tmp.size();
    for(int i=0; i<lenght; ++i) {
        if(tmp[i] == 'r') return FALSE;
    }

    return TRUE;
}


/***
 * Separate string to tokens and delete comments
 *
 * @param str
 * @return
 */
bool
Tokenizator::StringToTokens(std::string str) {
    static bool isComment = 0;

    if(str.empty() == 0) {
        if (!isComment) {
            deleteComment(&str, &isComment);

            char *tmp;
            char *cstr = new char[str.length() + 1];

            std::strcpy(cstr, str.c_str());
            tmp = strtok(cstr, " ");

            if (tmp != 0)
                while (tmp != NULL) {
                    if(!IsValidToken(tmp)) {
                        errors.push_back(std::pair<std::string , size_t> ("Invalid Token " + std::string(tmp) , line));
                        tmp = strtok(NULL, " ");
                        continue;
                    }

                    array.push_back(std::pair<std::string, size_t>(tmp, line));
                    tmp = strtok(NULL, " ");
                }
            else
                return FALSE;
        }
        else {
            deleteComment(&str , &isComment);
        }


            return TRUE;
    }

    return TRUE;
}

inline bool
Tokenizator::deleteComment(std::string* str , bool* isComment) {
    if(*isComment == 0) {
        size_t beginMultiLineComment = str->find(__BEGIN_MULTY_LINE_COMMENT__);

        if (beginMultiLineComment == str->npos) {
            deleteOneLineComment(str);
        }
        else {
            deleteMultiLineComments(str, isComment);
        }
    }
    else {
        deleteMultiLineComments(str , isComment);
    }

    return TRUE;
}

inline bool
Tokenizator::deleteOneLineComment(std::string* str) {
    size_t oneLineComments = str->find(__ONE_LINE_COMMENT__);
    if (oneLineComments != str->npos)
        str->erase(oneLineComments, str->size());//Deleting One Line Comment
}

inline bool
Tokenizator::deleteMultiLineComments(std::string* str , bool* isComment) {
    size_t beginMultiLineComment = str->find(__BEGIN_MULTY_LINE_COMMENT__);

    if(*isComment == 0) {
        size_t end_comments = str->find(__END_MULTY_LINE_COMMENT__);
        if (end_comments != str->npos) {
            str->erase(beginMultiLineComment , end_comments);
            return TRUE;
        }
        else {
            str->erase(beginMultiLineComment , str->size());
        }

        *isComment = 1;
    }
    else {
        size_t end_comments = str->find(__END_MULTY_LINE_COMMENT__);

        if (end_comments != str->npos) {
            str->erase(0 , end_comments + __END_MULTY_LINE_COMMENT__.size());
            *isComment = 0;

            deleteComment(str , isComment);
            StringToTokens(*str);
        }
    }
}



bool
Tokenizator::printArrayToConsole() {
    size_t lenght = array.size();
    size_t lenghtErr = errors.size();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "                       Result of Tokenizator                                    " << std::endl;
    std::cout << "TOKENS:                                                                         " << std::endl;
    std::cout << std::endl;

    for(int i=0; i<lenght; ++i) {
        std::cout << "Token: " << i << " " << array[i].first                                        << std::endl;
        std::cout << "Line: " << array[i].second                                                    << std::endl;
        std::cout << std::endl;
     }

    std::cout << std::endl;
    std::cout << "ERROR:"                                                                          << std::endl;
    for(int i=0; i<lenght; ++i) {
        std::cout << "Error: " << i << " " << errors[i].first                                       << std::endl;
        std::cout << "Line: " << errors[i].second                                                   << std::endl;
    }
    std::cout << std::endl;

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
        size_t lenghtErr = errors.size();

        fout << std::endl;
        fout << std::endl;
        fout << "================================================================================" << std::endl;
        fout << "                       Result of Tokenizator                                    " << std::endl;
        fout << "TOKENS:                                                                         " << std::endl;
        fout << std::endl;

        for(int i=0; i<lenght; ++i) {
            fout << "Token: " << i << " " << array[i].first                                        << std::endl;
            fout << "Line: " << array[i].second                                                    << std::endl;
            fout << std::endl;
        }

        fout << std::endl;
        fout << "ERROR:"                                                                          << std::endl;
        fout << std::endl;
        for(int i=0; i<lenghtErr; ++i) {
            fout << "Error: " << i << " " << errors[i].first                                      << std::endl;
            fout << "Line: " << errors[i].second                                                  << std::endl;
        }
        fout << std::endl;

        fout << "================================================================================" << std::endl;
        fout << std::endl;
        fout << std::endl;

        fout.close();
    }
}
