cmake_minimum_required(VERSION 3.5)

project(randomizer)

add_library(randomizer STATIC
    randomizer.h
    random_value.cpp
)

target_include_directories(
    randomizer
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
)
