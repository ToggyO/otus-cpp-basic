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
    ../src/iterator/sequential/iterator_base.hpp
)

add_executable(tests
    test_struct.hpp
    list_internal_tests.cpp
    iterator_tests.cpp
    ${COMMON_SRCS}
)
target_include_directories(tests PUBLIC
        ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(tests PUBLIC gtest gtest_main)