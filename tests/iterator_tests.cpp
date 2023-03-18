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

TEST(TestIteratorOpeartors, Success) {
    int a[5] { 1, 2, 3, 4, 5 };
    int* ptr = a;

    auto it = IteratorBase<int>(ptr);

    ++it;
    ASSERT_EQ(*it, a[1]);

    it++;
    ASSERT_EQ(*it, a[2]);

    --it;
    ASSERT_EQ(*it, a[1]);

    it--;
    ASSERT_EQ(*it, a[0]);

    it = it + 1;
    ASSERT_EQ(*it, a[1]);

    it = it - 1;
    ASSERT_EQ(*it, a[0]);

    auto it2 = IteratorBase<int>(ptr + 4);
    ASSERT_EQ(it2 - it, 4);

    it += 2;
    ASSERT_EQ(*it, a[2]);

    it -= 2;
    ASSERT_EQ(*it, a[0]);

    ASSERT_TRUE(it != it2);

    auto it_copy = IteratorBase<int>(ptr);
    ASSERT_TRUE(it == it_copy);
}