#include <stdlib.h>
#include <iostream>

#include "Language.h"

/***
 * Encoding is
 *          first two numbers in a function code is
 *                                          code of FUNCTION
 *          second two numbers in a function code is
 *                                          code of DESTINATION
 *          third two numbers in a function code is
 *                                          code os SOURCE
 *
 *
 *          FUNCTION:
 *                  00 - int
 *                  01 - mov
 *
 *                  02 - push
 *                  03 - pop
 *
 *                  04 - inc
 *                  05 - dec
 *                  06 - add
 *                  07 - sub
 *                  08 - mul
 *                  09 - div
 *                  0a - pow
 *
 *                  0b - shl
 *                  0c - shr
 *
 *                  0d - or
 *                  0e - nor
 *                  0f - xor
 *                  10 - and
 *                  11 - nand
 *                  12 - not
 *
 *                  13 - cmp
 *
 *                  14 - jmp
 *                  15 - je
 *                  16 - jg
 *                  17 - jl
 *                  18 - jge
 *                  19 - jle
 *                  1a - jgl
 *
 *          SOURCE and DESTINATION:
 *                  stack:
 *                  00 - stack
 *
 *                  registers:
 *                  01 - %e1x
 *                  02 - %e2x
 *                  03 - %e3x
 *                  04 - %e4x
 *                  05 - %e5x
 *                  06 - %e6x
 *                  07 - %e7x
 *                  08 - %e8x
 *                  09 - %e9x
 *                  0a - %e10
 *                  0b - %e11
 *                  0c - %e12
 *
 *                  0d - %e13
 *                  0d - %epc
 *
 *                  0e - %e14
 *                  0e - %esp
 *
 *                  0f - %e15
 *                  0f - %elr
 *
 *                  variable:
 *                  ff - variable
 */
Language::Language() : LanguageElement() {
    ADD_FUNCTION(0x00 , "int");

    ADD_FUNCTION(0x010000 , "mov");

    ADD_FUNCTION(0x0200 , "push");
    ADD_FUNCTION(0x0300 , "pop");

    ADD_FUNCTION(0x040000 , "inc");
    ADD_FUNCTION(0x050000 , "dec");
    ADD_FUNCTION(0x060000 , "add");
    ADD_FUNCTION(0x070000 , "sub");
    ADD_FUNCTION(0x080000 , "mul");
    ADD_FUNCTION(0x090000 , "div");
    ADD_FUNCTION(0x0a0000 , "pow");

    ADD_FUNCTION(0x0b0000 , "shl");
    ADD_FUNCTION(0x0c0000 , "shr");

    ADD_FUNCTION(0x0d0000 , "or");
    ADD_FUNCTION(0x0e0000 , "nor");
    ADD_FUNCTION(0x0f0000 , "xor");
    ADD_FUNCTION(0x100000 , "and");
    ADD_FUNCTION(0x110000 , "nand");
    ADD_FUNCTION(0x1200 , "not");

    ADD_FUNCTION(0x130000 , "cmp");

    ADD_FUNCTION(0x1400 , "jmp");
    ADD_FUNCTION(0x1500 , "je");
    ADD_FUNCTION(0x1600 , "jg");
    ADD_FUNCTION(0x1700 , "jl");
    ADD_FUNCTION(0x1800 , "jge");
    ADD_FUNCTION(0x1900 , "jle");
    ADD_FUNCTION(0x1a00 , "jgl");



    ADD_REGISTER(0x01 , "%e1x");
    ADD_REGISTER(0x02 , "%e2x");
    ADD_REGISTER(0x03 , "%e3x");
    ADD_REGISTER(0x04 , "%e4x");
    ADD_REGISTER(0x05 , "%e5x");
    ADD_REGISTER(0x06 , "%e6x");
    ADD_REGISTER(0x07 , "%e7x");
    ADD_REGISTER(0x08 , "%e8x");
    ADD_REGISTER(0x09 , "%e9x");
    ADD_REGISTER(0x0a , "%e10");
    ADD_REGISTER(0x0b , "%e11");
    ADD_REGISTER(0x0c , "%e12");

    ADD_REGISTER(0x0d , "%e13");
    ADD_REGISTER(0x0d , "%epc");

    ADD_REGISTER(0x0e , "%e14");
    ADD_REGISTER(0x0e , "%esp");

    ADD_REGISTER(0x0f , "%e15");
    ADD_REGISTER(0x0f , "%e15");
}

LanguageElement*
Language::isFunction(std::string str) {
    auto search = validFunctions.find(str);
    if(search != validFunctions.end() ) {
        LanguageElement* element = new LanguageElement;
        element->code = search->second;
        element->flag = FUNCTION_;

        return element;
    }

    return nullptr;
}

LanguageElement*
Language::isRegister(std::string str) {
    auto search = registers.find(str);
    if(search != registers.end() ) {
        LanguageElement* element = new LanguageElement;
        element->code = search->second;
        element->flag = REGISTER_   ;

        return element;
    }

    return nullptr;
}

LanguageElement*
Language::isNumber(std::string str) {
    size_t length = str.capacity();
    size_t result = 0;
    for(size_t i=0; i<length; ++i) {
        if(str[i] >= '0' && str[i] <= '9')
            result = result * 10 + str[i] - '0';
        else
            return nullptr;
    }

    LanguageElement* element = new LanguageElement;
    element->flag = NUMBER_;
    element->code = result;
    return element;
}

LanguageElement*
Language::what(std::string str) {
    LanguageElement* element = nullptr;

    element = isFunction(str);
    if(element != nullptr) return element;

    element = isRegister(str);
    if(element != nullptr) return element;

    element = isNumber(str);
    if(element != nullptr) return element;

    element = new LanguageElement(ERROR_ , 0);

    return element;
}



std::string
flagToString(_flags flag) {
    switch(flag) {
        case ERROR_ :    { return "ERROR";}    break;
        case FUNCTION_ : { return "FUNCTION";} break;
        case NUMBER_ :   { return "NUMBER";}   break;
        case REGISTER_ : { return "REGISTER";} break;
        case VARIABLE_ : { return "VARIABLE";} break;
    }
}

#include "Language.h"
