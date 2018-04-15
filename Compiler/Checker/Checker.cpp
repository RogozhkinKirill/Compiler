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
    for(int i=0; i<tokens.size(); ++i)
    {
        if(isFunction(tokens[i]) ) {
            array.push_back(CheckerElement(tokens[i].getToken() , tokens[i].getLine() , FUNCTION_));
        }
        else if(isNumber(tokens[i]) ) {
            array.push_back(CheckerElement(tokens[i].getToken() , tokens[i].getLine() , NUMBER_));
        }
        else if(isRegister(tokens[i]) ) {
            array.push_back(CheckerElement(tokens[i].getToken() , tokens[i].getLine() , REGISTER_));
        }
        else {
            error.push_back(CheckerElement(tokens[i].getToken() , tokens[i].getLine() , ERROR_));
        }
    }

    return TRUE;
}

bool
Checker::isFunction(Tokens token) {

}

bool
Checker::isNumber(Tokens token);

bool
Checker::isRegister(Tokens token);