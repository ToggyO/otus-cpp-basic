cmake_minimum_required(VERSION 3.10)

project(calc CXX)

add_executable(calc
    src/lexer.cpp
    src/parser.cpp
    src/main.cpp
    src/nodes/add.cpp
    src/nodes/astnode.cpp
    src/nodes/div.cpp
    src/nodes/mul.cpp
    src/nodes/number.cpp
    src/nodes/operation_node.cpp
    src/nodes/sub.cpp
    src/nodes/variable.cpp
)

target_include_directories(calc PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(calc PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(calc PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(calc PUBLIC cxx_std_17)
