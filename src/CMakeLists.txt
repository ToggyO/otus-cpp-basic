cmake_minimum_required(VERSION 3.5)

project(06.homework.src CXX)

add_executable(containers
    main.cpp
    vector/vector.hpp
    iterator/sequential/iterator_base.hpp
    forward_list/forward_list.hpp
    hw_tasks/hw_tasks.h
    hw_tasks/test_list.cpp
)

set_target_properties(containers PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(containers PRIVATE 
    -g
    -Wall
    -Wextra
    -Werror
    -pedantic
    -fsanitize=address
    -fsanitize=leak
)
target_link_options(containers PRIVATE 
    -fsanitize=address
    -fsanitize=leak
)

target_include_directories(containers PRIVATE
   ../include
)