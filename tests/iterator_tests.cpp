#include <gtest/gtest.h>

#include "iterator/iterator.hpp"

// TODO: add descr
TEST(TestIterator, sad) {
    int a[5] { 1, 2, 3, 4, 5 };
    int* ptr = a;

    auto start = Iterator<int>(ptr);
    auto end = Iterator<int>(ptr + 5);

    for (Iterator<int> iter = start; iter != end; ++iter)
    {
        
    }
}