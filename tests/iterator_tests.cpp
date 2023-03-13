#include <gtest/gtest.h>

#include "iterator/aaa/iterator.hpp"
#include "iterator/aaa/const_iterator.hpp"

TEST(TestIterator, IteratesProperlyAndAllowToMutate) {
    int replace = 17;
    int a[5] { 1, 2, 3, 4, 5 };
    int* ptr = a;

    auto start = Iterator<int>(ptr);
    auto end = Iterator<int>(ptr + 5);
    int i = 0;
    for (Iterator<int> iter = start ; iter != end; ++iter, ++i)
    {
        ASSERT_EQ(a[i], *iter);
        if (i == 2)
        {
            *iter = replace;
        }
    }

    ASSERT_EQ(replace, a[2]);
}

TEST(TestConstIterator, IteratesProperly) {
    int a[5] { 1, 2, 3, 4, 5 };
    int* ptr = a;

    auto start = ConstIterator<int>(ptr);
    auto end = ConstIterator<int>(ptr + 5);
    int i = 0;
    for (ConstIterator<int> iter = start ; iter != end; ++iter, ++i)
    {
        ASSERT_EQ(a[i], *iter);
    }
}