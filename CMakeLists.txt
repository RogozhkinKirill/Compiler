cmake_minimum_required(VERSION 3.9)
project(Compiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Compiler main.cpp
                debug_log.h

                errors_warning.h

                Compiler/Compiler.cpp
                Compiler/Compiler.h

                    Compiler/Tokenizator/Tokenizator.cpp
                    Compiler/Tokenizator/Tokenizator.h

                    Compiler/Checker/Checker.cpp
                    Compiler/Checker/Checker.h

                    Compiler/Logic/Logic.cpp
                    Compiler/Logic/Logic.h Compiler/Language.h errors_warning.cpp)

add_definitions(-DDEBUG)