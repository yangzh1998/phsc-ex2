cmake_minimum_required (VERSION 2.8)
project(phsc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-deprecated-register")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -fno-strict-aliasing")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions -fno-rtti")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPHSC_LITE")

add_executable(phsc 
    src/driver/phsc.cpp 
    #src/opt/llvm-opt.cpp
    #src/parser/parser.cpp
    #src/parser/lexer.cpp
    src/symbol/scope.cpp
    src/symbol/scope-stack.cpp
    src/visitor/build-sym.cpp
    src/visitor/print-ast.cpp
    src/visitor/type-check.cpp
)

