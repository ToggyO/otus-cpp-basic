#include <gtest/gtest.h>

#include "iterator/sequential/iterator_base.hpp"

TEST(TestIterator, IteratesProperlyAndAllowToMutate) {
    int replace = 17;
    int a[5] { 1, 2, 3, 4, 5 };
    int* ptr = a;

    auto start = IteratorBase<int>(ptr);
    auto end = IteratorBase<int>(ptr + 5);
    int i = 0;
    for (auto iter = start ; iter != end; ++iter, ++i)
    {
        ASSERT_EQ(a[i], *iter);
        if (i == 2)
        {
            *iter = replace;
        }
    }

    ASSERT_EQ(replace, a[2]);
}