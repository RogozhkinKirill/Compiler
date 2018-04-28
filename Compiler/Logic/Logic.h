#ifndef COMPILER_LOGIC_H
#define COMPILER_LOGIC_H

#include "../Checker/Checker.h"

class LogicElement {
public:
    explicit LogicElement();
    explicit LogicElement(size_t ln , _flags f1 , size_t f1_v , _flags f2 , size_t f2_v , _flags f3 , size_t f3_v);

    virtual
   ~LogicElement() {}

   inline size_t getLine() {return line;}
   inline _flags getFlag(size_t i);
   inline size_t getValue(size_t i);

    void initLine(size_t line) {this->line = line;}
    void initValue(size_t i , size_t value);
    void initFlag(size_t i , _flags flag);
protected:

    size_t line;
    _flags flag1;

    size_t flag1_Value;
    _flags flag2;

    size_t flag2_Value;
    _flags flag3;

    size_t flag3_Value;
};

class Logic : public LogicElement{
public:
    //LogicElement* checkLabel(std::vector<CheckerElement> array ,
    std::vector<LogicElement> array;
    std::vector<std::pair<std::string , size_t> > error;

    Logic(void) {}

    Logic(std::vector<CheckerElement> array);

   ~Logic(void) {}

    bool checkLogic(std::vector<CheckerElement> array);
    bool printArrayToConsole(void);

    bool printArrayToFile(void);
protected:

    LogicElement* checkFunction(std::vector<CheckerElement> array ,
                                size_t* i , size_t length , size_t line);
    LogicElement* checkNonParamFunction(std::vector<CheckerElement> array ,
                                        size_t* i , size_t length , size_t line);
    LogicElement* checkOneParamFunction(std::vector<CheckerElement> array ,
                                        size_t* i , size_t length , size_t line);

    LogicElement* checkTwoParamFunction(std::vector<CheckerElement> array ,
                                        size_t* i , size_t length , size_t line);

    void initFunctionParam(LogicElement* destination , int paramPlace , CheckerElement source);
    void SkipLine(std::vector<CheckerElement> array ,
                  size_t* i , size_t length , size_t line);

};


#endif //COMPILER_LOGIC_H
