cmake_minimum_required (VERSION 2.8)
project(phsc)

find_package(BISON 2 EXACT REQUIRED)
set(BisonOutput 
    ${CMAKE_SOURCE_DIR}/src/parser/parser.cpp
    ${CMAKE_SOURCE_DIR}/src/parser/parser.hpp
    ${CMAKE_SOURCE_DIR}/src/parser/position.hh
    ${CMAKE_SOURCE_DIR}/src/parser/stack.hh
    ${CMAKE_SOURCE_DIR}/src/parser/location.hh
)
add_custom_command(
    OUTPUT ${BisonOutput}
    COMMAND ${BISON_EXECUTABLE} 
        -o ${CMAKE_SOURCE_DIR}/src/parser/parser.cpp
        ${CMAKE_SOURCE_DIR}/src/parser/parser.yy
)

find_package(FLEX REQUIRED)
set(FlexOutput ${CMAKE_SOURCE_DIR}/src/parser/lexer.cpp)
add_custom_command(
    OUTPUT ${FlexOutput}
    COMMAND ${FLEX_EXECUTABLE} -o ${FlexOutput}
        ${CMAKE_SOURCE_DIR}/src/parser/lexer.l
)

find_package(LLVM 11 REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
link_directories("${LLVM_DIR}/../..")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-deprecated-register")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -fno-strict-aliasing")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions -fno-rtti")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPHSC_LITE")

add_executable(phsc 
    src/driver/phsc.cpp 
    src/opt/llvm-opt.cpp
    src/parser/parser.cpp
    src/parser/lexer.cpp
    src/symbol/scope.cpp
    src/symbol/scope-stack.cpp
    src/visitor/build-sym.cpp
    src/visitor/print-ast.cpp
    src/visitor/type-check.cpp
)

target_link_libraries(phsc 
    -lLLVM
)
