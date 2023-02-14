
cmake_minimum_required(VERSION 3.5)

project(05.homework.src)

add_executable(stat
    main.cpp
    min.cpp
    max.cpp
    mean.cpp
    standard_deviation.cpp
)

target_include_directories(stat PRIVATE ../include)

