cmake_minimum_required(VERSION 3.5)

project(06.homework.src CXX)

add_executable(containers
    main.cpp
    iterator/sequential/iterator_base.hpp
    hw_tasks/hw_tasks.h
    hw_tasks/test_list.cpp
    list/list.hpp
)

set_target_properties(containers PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
