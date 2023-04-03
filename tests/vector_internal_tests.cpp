#include <gtest/gtest.h>

#include "test_struct.hpp"
#include "vector/vector.hpp"

TEST(TestVectorConstructors, Success) {
    int size = 0;
    int cap = 5;

     // Parameterless ctor
    Vector<A> list;
    list.reserve(cap);
    ASSERT_EQ(cap, list.cap());

    // Copy ctor
    Vector<A> list1(list);
    ASSERT_EQ(cap, list1.cap());
    ASSERT_EQ(cap, list.cap());
    ASSERT_EQ(size, list.size());

    // Move ctor
    Vector<A> list2(std::move(list1));
    ASSERT_EQ(cap, list2.cap());
    ASSERT_EQ(size, list2.size());

    // Initializer list ctor
    Vector<int> list3 { 1, 2, 3 };
    ASSERT_EQ(list3.cap(), 3);
    ASSERT_EQ(list3.size(), 3);
    ASSERT_EQ(list3[0], 1);
    ASSERT_EQ(list3[1], 2);
    ASSERT_EQ(list3[2], 3);

    // Iterator range ctor
    Vector<int> list4(list3.begin(), list3.end());
    ASSERT_EQ(list3.cap(), 3);
    ASSERT_EQ(list3.size(), 3);
    ASSERT_EQ(list3[0], 1);
    ASSERT_EQ(list3[1], 2);
    ASSERT_EQ(list3[2], 3);
}

TEST(TestVectorResize, Success) {
    int expected_cap = 4;
    int new_cap = 10;

    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);
    ASSERT_EQ(expected_cap, list.cap());

    list.reserve(new_cap);
    ASSERT_EQ(new_cap, list.cap());

    list.emplace_back(7, 8);
    ASSERT_EQ(4, list.size());
    ASSERT_EQ(new_cap, list.cap());
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], (A{3, 4}));
    ASSERT_EQ(list[2], (A{5, 6}));
    ASSERT_EQ(list[3], (A{7, 8}));
}

TEST(TestVectorIndexator, Success) {
    int val = 5;
    Vector<int> list;
    list.reserve(1);

    list[0] = val;
    ASSERT_EQ(val, list[0]);
}

TEST(TestVectorIndexator, ThrowsIndexOutOfRange) {
    int val = 5;
    Vector<int> list;

    EXPECT_THROW(list[4] = val, std::out_of_range);
}

TEST(TestVectorEmplaceBack, Success) {
    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);

    ASSERT_EQ(3, list.size());

    A a = A{1, 2};
    ASSERT_EQ(a, list[0]);
    
    a = A{3, 4};
    ASSERT_EQ(a, list[1]);

    a = A{5, 6};
    ASSERT_EQ(a, list[2]);
}

TEST(TestVectorPushBack, Success) {
    Vector<A> list;

    // Move version
    list.push_back(A{1, 2});
    ASSERT_EQ(list[0], (A{1, 2}));

    // Copy version
    A a = A{3, 4};
    list.push_back(a);
    ASSERT_EQ(list[1], a);

    a.a = 10;
}

TEST(TestVectorInsert, Success) {
    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);

    // Move version
    list.insert(list.begin() + 1, A{7, 8});
    ASSERT_EQ(list.size(), 4);
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], (A{7, 8}));
    ASSERT_EQ(list[2], (A{3, 4}));
    ASSERT_EQ(list[3], (A{5, 6}));

    // Copy version
    A a = A{11, 12};
    list.insert(list.begin() + 1, a);
    ASSERT_EQ(list.size(), 5);
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], a);
    ASSERT_EQ(list[2], (A{7, 8}));
    ASSERT_EQ(list[3], (A{3, 4}));
    ASSERT_EQ(list[4], (A{5, 6}));

    // if pos == end()
    list.insert(list.end(), A{33, 44});
    ASSERT_EQ(list.size(), 6);
    ASSERT_EQ(list[5], (A{33, 44}));

    // Const iterator move version
    list.insert(list.cbegin(), A{111, 222});
    ASSERT_EQ(list.size(), 7);
    ASSERT_EQ(list[0], (A{111, 222}));

    // Const iterator copy version
    a = A{123, 456};
    list.insert(list.cbegin(), a);
    ASSERT_EQ(list.size(), 8);
    ASSERT_EQ(list[0], (A{123, 456}));
}

TEST(TestVectorEmplace, Success) {
    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);
    list.emplace_back(11, 15);

    list.emplace(list.begin() + 1, 7, 8);
    ASSERT_EQ(list.size(), 5);
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], (A{7, 8}));
    ASSERT_EQ(list[2], (A{3, 4}));
    ASSERT_EQ(list[3], (A{5, 6}));
    ASSERT_EQ(list[4], (A{11, 15}));

    // if pos == end() - 1
    list.emplace(list.end() - 1, 111, 222);
    ASSERT_EQ(list.size(), 6);
    ASSERT_EQ(list[4], (A{111, 222}));
    ASSERT_EQ(list[5], (A{11, 15}));

    // if pos == end()
    list.emplace(list.end(), 33, 44);
    ASSERT_EQ(list.size(), 7);
    ASSERT_EQ(list[6], (A{33, 44}));

    // Const iterator
    list.emplace(list.cbegin(), 123, 456);
    ASSERT_EQ(list.size(), 8);
    ASSERT_EQ(list[0], (A{123, 456}));
}

TEST(TestVectorErase, Success) {
    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);
    list.emplace_back(7, 8);
    list.emplace_back(9, 10);
    list.emplace_back(11, 12);

    list.erase(list.begin() + 1, list.end() - 3);

    ASSERT_EQ(list.size(), 4);
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], (A{7, 8}));
    ASSERT_EQ(list[2], (A{9, 10}));
    ASSERT_EQ(list[3], (A{11, 12}));

    // Const iterator
    list.erase(list.cbegin() + 1, list.cend() - 1);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], (A{11, 12}));

    auto iter = list.begin();
    iter = list.begin();

    auto citer = list.cbegin();
    citer = list.cend();
    citer = list.cbegin();
}

TEST(TestVectorClear, Success) {
    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);

    list.clear();
    ASSERT_EQ(list.size(), 0);
    ASSERT_EQ(list.cap(), 0);
    ASSERT_EQ(list.begin(), list.end());
}