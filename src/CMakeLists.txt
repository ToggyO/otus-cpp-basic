cmake_minimum_required(VERSION 3.5)

project(06.homework.src CXX)

add_executable(containers
    main.cpp
    vector/vector.hpp
    iterator/sequential/iterator_base.hpp
    iterator/separated/forward_iterator.hpp
    forward_list/forward_list.hpp
    hw_tasks/hw_tasks.h
    hw_tasks/test_list.cpp
    fl.hpp
)

set_target_properties(containers PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(containers PRIVATE
   ../include
)