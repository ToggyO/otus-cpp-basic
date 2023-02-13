cmake_minimum_required(VERSION 3.5)

project(value_checker)

add_library(value_checker STATIC
    check_value.h
    check_value.cpp
)

target_include_directories(
        value_checker
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
)