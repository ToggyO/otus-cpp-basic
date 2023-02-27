#include <gtest/gtest.h>

#include "list/list.hpp"

struct A
{
    A(int a_, int b_) : a(a_), b(b_) {}

    int a;
    double b;
};

TEST(TestConstructors, success) {
    int size = 0;
    int cap = 5;

    List<A> list(cap);
    ASSERT_EQ(cap, list.cap());

    List<A> list1(list);
    ASSERT_EQ(cap, list1.cap());
    ASSERT_EQ(cap, list.cap());
    ASSERT_EQ(size, list.size());

    List<A> list2(std::move(list1));
    ASSERT_EQ(cap, list2.cap());
    ASSERT_EQ(size, list2.size());
}

TEST(TestListResize, success) {
    int cap = 4;
    int new_cap = 10;

    List<A> list;
    ASSERT_EQ(cap, list.cap());

    list.resize(new_cap);
    ASSERT_EQ(new_cap, list.cap());
}

// TODO: несостоятельный тест
TEST(TestEmplaceBack, success) {
    List<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);

    ASSERT_EQ(3, list.size());

    A* arr = list.get_arr();
    A* start = arr;
    A* end = arr + list.size();
    for (auto i = start; i != end ; i++)
    {
        std::cout << "a = " << i->a << " " << "b = " << i->b << std::endl;
    }
}