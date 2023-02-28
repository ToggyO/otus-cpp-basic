cmake_minimum_required(VERSION 3.5)

project(06.homework.src CXX)

add_executable(containers
    main.cpp
    list/list.hpp
    iterator/iterator.hpp
    iterator/const_iterator.hpp
)

set_target_properties(containers PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
