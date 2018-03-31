//
// Created by пользователь on 30.03.2018.
//

#ifndef STACK_S_ERRORS_WARNING_H
#define STACK_S_ERRORS_WARNING_H

#include <cstdio>
#include <fstream>

//define
typedef int WnE; //WnE == warning and errors
#define error(x , y) const WnE y = x;
#define warning(x , y) const WnE y = x;

#define add_WnE(result , WnE) if(result & WnE != WnE) \
result += WnE;


///ERRORS
error(0b10000000000000000000000000000000 , __INVALED_VALUE__);
error(0b01000000000000000000000000000000 , __OVERFLOW__);

///WARNING
warning(0b00000000000000000000000000000001 , __NULL_POINTER__);
warning(0b00000000000000000000000000000010 , __NULL_VALUE__);
warning(0b00000000000000000000000000000100 , __UNABLE_TO_COMPLETE__);
warning(0b00000000000000000000000000001000 , __CHANGED_PRIVATE_ZONE__);
warning(0b00000000000000000000000000010000 , __FILLED__);


/**
 * Create string with path to str which in the same directory as errors_warnings.h
 */
std::string
getFile(std::string str);

#endif //STACK_S_ERRORS_WARNING_H

