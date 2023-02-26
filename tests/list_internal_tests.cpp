#include <gtest/gtest.h>

#include "list/list.hpp"

struct A
{
    int a;
    double b;
};

// TODO:
TEST(TestConstructors, success) {
    int size = 5;

    List<A> list(size);

    List<A> list1(list);

    ASSERT_EQ(size, list1.size());

    List<A> list2(std::move(list1));

    ASSERT_EQ(size, list2.size());
}