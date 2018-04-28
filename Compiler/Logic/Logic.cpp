#include "Logic.h"


LogicElement::LogicElement() {
    line = flag1_Value = flag2_Value = flag3_Value = 0;
    flag1 = flag2 = flag3 = NOTHING_;
}

LogicElement::LogicElement(size_t ln , _flags f1 , size_t f1_v , _flags f2 , size_t f2_v , _flags f3 , size_t f3_v) :
                line(ln),
                flag1(f1), flag1_Value(f1_v),
                flag2(f2), flag2_Value(f2_v),
                flag3(f3), flag3_Value(f3_v) {}


_flags
LogicElement::getFlag(size_t i) {
    if(i == 1) return flag1;
    if(i == 2) return flag2;
    if(i == 3) return flag3;
}

size_t
LogicElement::getValue(size_t i) {
    if(i == 1) return flag1_Value;
    if(i == 2) return flag2_Value;
    if(i == 3) return flag3_Value;
}



void
LogicElement::initValue(size_t i , size_t value) {
    if(i == 1) flag1_Value = value;
    if(i == 2) flag2_Value = value;
    if(i == 3) flag3_Value = value;
}

void
LogicElement::initFlag(size_t i , _flags flag) {
    if(i == 1) flag1 = flag;
    if(i == 2) flag2 = flag;
    if(i == 3) flag3 = flag;
}


Logic::Logic(std::vector<CheckerElement> array) {
    if(!array.empty() ) {
        checkLogic(array);
    }
}

bool
Logic::checkLogic(std::vector<CheckerElement> array) {
    size_t length = array.capacity();
    for(size_t i=0; i<length; ++i) {
        size_t currentLine = array[i].getLine();

        LogicElement* element = nullptr;
        if(array[i].getFlag() == FUNCTION_) {
            element = checkFunction(array, &i, length, currentLine);

            if(element == nullptr) {
                error.push_back(std::pair<std::string , size_t> ("SOMETHING STRANGE" , array[i].getLine()));
            }
            else {
                this->array.push_back(LogicElement (element->getLine() ,
                                                element->getFlag(1) , element->getValue(1) ,
                                                element->getFlag(2) , element->getValue(2) ,
                                                element->getFlag(3) , element->getValue(3) ) );
                delete element;
            }
        }
    }

    return error.size() == 0;
}

LogicElement*
Logic::checkFunction(std::vector<CheckerElement> array ,
                     size_t* i , size_t length , size_t line) {
    if(array[*i].getName() < 0x100)
        return checkNonParamFunction(array , i , length , line);

    if(array[*i].getName() >= 0x100 && array[*i].getName() < 0x10000)
        return checkOneParamFunction(array , i , length , line);

    if(array[*i].getName() >= 0x10000)
        return checkTwoParamFunction(array , i , length , line);
}

LogicElement*
Logic::checkNonParamFunction(std::vector<CheckerElement> array ,
                                    size_t* i , size_t length , size_t line) {
    CheckerElement chrEl = array[(*i)+1];
    size_t curLine = chrEl.getLine();
    if(length < (*i)+1 || curLine == line)
        return nullptr;
    else {
        LogicElement* element = new LogicElement(line , array[*i].getFlag() , array[*i].getName() ,
                                                 NOTHING_ , 0 , NOTHING_ , 0);
        return element;
    }
}

LogicElement*
Logic::checkOneParamFunction(std::vector<CheckerElement> array ,
                                    size_t* i , size_t length , size_t line) {
    int elementInLine = 1;
    LogicElement* element = new LogicElement;
    element->initLine(line);

    while((*i < length || line == array[*i].getLine()) && elementInLine < 3) {
        _flags flag = array[(*i)].getFlag();
        if( elementInLine != 1 && (flag == FUNCTION_ || flag == LABEL_) ) {
            delete element;
            return nullptr;
        }

        initFunctionParam(element , elementInLine , array[*i]);

        elementInLine++;
        (*i)++;
    }
    (*i)--;

    if(array[(*i) + 1].getLine() == line) {
        delete element;
        return nullptr;
    }

    return element;
}

LogicElement*
Logic::checkTwoParamFunction(std::vector<CheckerElement> array ,
                                    size_t* i , size_t length , size_t line) {
    int elementInLine = 1;
    LogicElement* element = new LogicElement;
    element->initLine(line);

    while((*i < length || line == array[*i].getLine()) && elementInLine < 4) {
        _flags flag = array[(*i)].getFlag();
        if( elementInLine != 1 && (flag == FUNCTION_ || flag == LABEL_)) {
            delete element;
            return nullptr;
        }

        initFunctionParam(element , elementInLine , array[*i]);

        elementInLine++;
        (*i)++;
    }
    (*i)--;

    if(array[(*i) + 1].getLine() == line) {
        delete element;
        return nullptr;
    }

    return element;
}

void
Logic::initFunctionParam(LogicElement* destination , int paramPlace , CheckerElement source) {
    size_t factor = 1;
    for(int i=0; i<paramPlace - 2; ++i)
        factor *= 0x100;

    if(source.getFlag() == REGISTER_)
        destination->initValue(1 , destination->getValue(1) + factor * source.getName() );
    else if(source.getFlag() == NUMBER_) {
        size_t value = destination->getValue(1);
                               value += factor * 0xeeu;
        destination->initValue(1 , value);
    }
    else if(source.getFlag() == VARIABLE_)
        destination->initValue(1 , destination->getValue(1) + factor * 0xff);



    destination->initValue((size_t)paramPlace , source.getName() );
    destination->initFlag((size_t)paramPlace ,  source.getFlag() );
}

void
Logic::SkipLine(std::vector<CheckerElement> array ,
              size_t* i , size_t length , size_t line) {
    while(*i < length && array[*i].getLine() == line) (*i)++;
}

bool
Logic::printArrayToFile(void) {
    std::string file = getFile("\\Test_result.txt");
    std::ofstream fout(file ,  std::ofstream::out | std::ofstream::app);
    delete &file;

    if(fout.is_open()) {
        size_t length = array.size();
        size_t lenghtErr = error.size();

        fout << std::endl;
        fout << std::endl;
        fout << "================================================================================" << std::endl;
        fout << "                          Result of Logic                                       " << std::endl;
        fout << "TOKENS:                                                                         " << std::endl;
        fout << std::endl;

        for(int i=0; i<length; ++i) {

            for(size_t j=1; j<4; ++j) {
                char str[10];
        fout << "Name: " << i << " 0x" << itoa(array[i].getValue(j), str, 16)                       << std::endl;
        fout << "Flag: " << i << " " << flagToString(array[i].getFlag(j))                          << std::endl;
            }
            fout << "Line: " << array[i].getLine()                                                 << std::endl;
            fout << std::endl;
        }

        fout << std::endl;
        fout << "ERROR:"                                                                          << std::endl;
        fout << std::endl;
        for(int i=0; i<lenghtErr; ++i) {
            fout << "Error: " << i << " " << error[i].first                                        << std::endl;
            fout << "Line: " << error[i].second                                                    << std::endl;
        }
        fout << std::endl;

        fout << "================================================================================" << std::endl;
        fout << std::endl;
        fout << std::endl;

        fout.close();
    }
}

bool
Logic::printArrayToConsole(void) {
    size_t lenght = array.size();
    size_t lenghtErr = error.size();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "================================================================================" << std::endl;
    std::cout << "                         Result of Logic                                      " << std::endl;
    std::cout << "TOKENS:                                                                         " << std::endl;
    std::cout << std::endl;

    for(int i=0; i<lenght; ++i) {
        for(size_t j=0; j<4; ++j) {
            char str[10];
    std::cout << "Name: " << i << " " << itoa(array[i].getValue(j), str, 16) << std::endl;
    std::cout << "Flag: " << i << " " << array[i].getFlag(j) << std::endl;
        }
        std::cout << "Line: " << array[i].getLine()                                                 << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "ERROR:"                                                                          << std::endl;
    for(int i=0; i<lenghtErr; ++i) {
        std::cout << "Error: " << i << " " << error[i].first                                  << std::endl;
        std::cout << "Line: " << error[i].second                                                << std::endl;
    }
    std::cout << std::endl;

    std::cout << "================================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}