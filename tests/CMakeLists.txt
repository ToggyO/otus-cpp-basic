include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(COMMON_SRCS
    ../src/vector/vector.hpp
    ../src/forward_list/forward_list.hpp
    ../src/iterator/sequential/iterator_base.hpp
)

add_executable(tests
    test_struct.hpp
    vector_internal_tests.cpp
    forward_list_internal_tests.cpp
    forward_list_iterator_tests.cpp
    iterator_tests.cpp
    ${COMMON_SRCS}
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(tests PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
        -fsanitize=address
        -fsanitize=leak
    )
    target_link_options(tests PRIVATE 
        -fsanitize=address
        -fsanitize=leak
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(tests PRIVATE
        /W4
        /WX
        /fsanitize=address
    )
    target_link_options(${target} PRIVATE 
        /fsanitize=address
    )
endif()

target_include_directories(tests PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(tests PUBLIC gtest gtest_main)