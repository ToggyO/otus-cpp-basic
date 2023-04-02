cmake_minimum_required(VERSION 3.5)

project(06.homework.src CXX)

add_executable(containers
    main.cpp
    vector/vector.hpp
    iterator/sequential/iterator_base.hpp
    forward_list/forward_list.hpp
    hw_tasks/hw_tasks.h
    hw_tasks/test_vector.cpp
    hw_tasks/test_forward_list.cpp
)

set_target_properties(containers PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
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
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(containers PRIVATE
        /W4
        /WX
        /fsanitize=address
    )
    target_link_options(${target} PRIVATE 
        /fsanitize=address
    )
endif()

target_include_directories(containers PRIVATE
   ../include
)