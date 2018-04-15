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


#include "Language.h"
