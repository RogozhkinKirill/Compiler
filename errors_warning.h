//
// Created by пользователь on 30.03.2018.
//

#ifndef STACK_S_ERRORS_WARNING_H
#define STACK_S_ERRORS_WARNING_H

#include <cstdio>
#include <fstream>

//define
typedef int WnE; //WnE == warning and errors
#define error_(x , y) const WnE y = x;
#define warning_(x , y) const WnE y = x;

#define add_WnE(result , WnE) if(result & WnE != WnE) \
result += WnE;


///ERRORS
error_(0b10000000000000000000000000000000 , __INVALID_VALUE__);
error_(0b01000000000000000000000000000000 , __OVERFLOW__);

///WARNING
warning_(0b00000000000000000000000000000001 , __NULL_POINTER__);
warning_(0b00000000000000000000000000000010 , __NULL_VALUE__);
warning_(0b00000000000000000000000000000100 , __UNABLE_TO_COMPLETE__);
warning_(0b00000000000000000000000000001000 , __CHANGED_PRIVATE_ZONE__);
warning_(0b00000000000000000000000000010000 , __FILLED__);





class Error : public std::exception{
    std::string err;
public:
    Error(std::string str) : err(str) {}
    ~Error() {}

    std::string getError() {
        return err;
    }
};



/**
 * Create string with path to str which in the same directory as errors_warnings.h
 */
std::string
getFile(std::string str);

#endif //STACK_S_ERRORS_WARNING_H

