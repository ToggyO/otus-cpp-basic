cmake_minimum_required(VERSION 3.5)

project(scores_manager)

add_library(scores_manager STATIC
    scores_manager.h
    scores_manager.cpp
    score.cpp
)