#include "Language.h"


/***
 * Encoding is
 *          first two numbers in a function code is
 *                                          code of FUNCTION
 *          second two numbers in a function code is
 *                                          code of SOURCE
 *          third two numbers in a function code is
 *                                          code os DESTINATION
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
 */
Language::Language() {
    ADD_FUNCTION(0x00 , "int");

    ADD_FUNCTION(0x01 , "mov");

    ADD_FUNCTION(0x020000 , "push");
    ADD_FUNCTION(0x030000 , "pop");

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
    ADD_FUNCTION(0x120000 , "not");


    validFunctions.insert(std::pair<std::string , int> ("mov" , 0x1) );

    validFunctions.insert(std::pair<std::string , int> ("push" , 0xccff01) );
    validFunctions.insert(std::pair<std::string , int> ("pop" , 0xccff02) );


    registers.insert(std::pair<std::string , int> ("%eax" , 0x1));
    registers.insert(std::pair<std::string , int> ("%ebx" , 0x2));
    registers.insert(std::pair<std::string , int> ("%ecx" , 0x3));
    registers.insert(std::pair<std::string , int> ("%edx" , 0x4));

}