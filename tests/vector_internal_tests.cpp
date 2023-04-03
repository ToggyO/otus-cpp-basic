#include <gtest/gtest.h>

#include "test_struct.hpp"
#include "vector/vector.hpp"


TEST(Vector, Constructors) {
    int size = 3;
    int cap = 5;

    // Parameterless ctor
    Vector<int> list; // HW7 - cоздание контейнера
    list.reserve(cap);
    ASSERT_EQ(cap, list.cap());

    // Initializer list ctor
    Vector<int> list1 { 1, 2, 3 };
    ASSERT_EQ(list1.cap(), 3);
    ASSERT_EQ(list1.size(), 3);
    ASSERT_EQ(list1[0], 1); // HW7 - получение элементов из контейнера
    ASSERT_EQ(list1[1], 2);
    ASSERT_EQ(list1[2], 3);

    // Copy ctor
    Vector<int> list2(list1); // HW7 - unit-тест на копирование контейнера
    ASSERT_EQ(size, list2.cap());
    ASSERT_EQ(size, list2.size());
    ASSERT_EQ(list2[0], list1[0]);
    ASSERT_EQ(list2[1], list1[1]);
    ASSERT_EQ(list2[2], list1[2]);

    // Move ctor
    Vector<int> list3(std::move(list2)); // HW7 - unit-тест на перемещение контейнера
    ASSERT_EQ(size, list3.cap());
    ASSERT_EQ(size, list3.size());
    ASSERT_EQ(list3[0], list1[0]);
    ASSERT_EQ(list3[1], list1[1]);
    ASSERT_EQ(list3[2], list1[2]);

    // Iterator range ctor
    Vector<int> list4(list3.begin(), list3.end());
    ASSERT_EQ(list4.cap(), size);
    ASSERT_EQ(list4.size(), size);
    ASSERT_EQ(list4[0], list1[0]);
    ASSERT_EQ(list4[1], list1[1]);
    ASSERT_EQ(list4[2], list1[2]);
}

TEST(Vector, Resize) {
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

// HW7 - получение элементов из контейнера
TEST(Vector, Indexator) {
    int val = 5;
    Vector<int> list;
    list.reserve(1);

    list[0] = val;
    ASSERT_EQ(val, list[0]);
}

TEST(Vector, IndexatorThrowsIndexOutOfRange) {
    int val = 5;
    Vector<int> list;

    EXPECT_THROW(list[4] = val, std::out_of_range);
}

// HW7 - вставка элементов в конец
TEST(Vector, EmplaceBack) {
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

// HW7 - вставка элементов в конец
TEST(Vector, PushBack) {
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

TEST(Vector, Insert) {
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
    list.insert(list.begin() + 1, a); // HW7 - вставка элементов в середину
    ASSERT_EQ(list.size(), 5);
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], a);
    ASSERT_EQ(list[2], (A{7, 8}));
    ASSERT_EQ(list[3], (A{3, 4}));
    ASSERT_EQ(list[4], (A{5, 6}));

    // if pos == end()
    list.insert(list.end(), A{33, 44}); // HW7 - вставка элементов в конец
    ASSERT_EQ(list.size(), 6);
    ASSERT_EQ(list[5], (A{33, 44}));

    // Const iterator move version
    list.insert(list.cbegin(), A{111, 222}); // HW7 - вставка элементов в начало
    ASSERT_EQ(list.size(), 7);
    ASSERT_EQ(list[0], (A{111, 222}));

    // Const iterator copy version
    a = A{123, 456};
    list.insert(list.cbegin(), a);
    ASSERT_EQ(list.size(), 8);
    ASSERT_EQ(list[0], (A{123, 456}));
}


TEST(Vector, Emplace) {
    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);
    list.emplace_back(11, 15);

    list.emplace(list.begin() + 1, 7, 8); // HW7 - вставка элементов в середину
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
    list.emplace(list.end(), 33, 44); // HW7 - вставка элементов в конец
    ASSERT_EQ(list.size(), 7);
    ASSERT_EQ(list[6], (A{33, 44}));

    // Const iterator
    list.emplace(list.cbegin(), 123, 456); // HW7 - вставка элементов в начало
    ASSERT_EQ(list.size(), 8);
    ASSERT_EQ(list[0], (A{123, 456}));
}

TEST(Vector, Erase) {
    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);
    list.emplace_back(7, 8);
    list.emplace_back(9, 10);
    list.emplace_back(11, 12);

    auto list1 = list;

    list1.erase(list1.begin() + 1, list1.end() - 3);

    ASSERT_EQ(list1.size(), 4);
    ASSERT_EQ(list1[0], (A{1, 2}));
    ASSERT_EQ(list1[1], (A{7, 8}));
    ASSERT_EQ(list1[2], (A{9, 10}));
    ASSERT_EQ(list1[3], (A{11, 12}));

    // Const iterator
    list1.erase(list1.cbegin() + 1, list1.cend() - 1); // HW7 - удаление элементов из середины
    ASSERT_EQ(list1.size(), 2);
    ASSERT_EQ(list1[0], (A{1, 2}));
    ASSERT_EQ(list1[1], (A{11, 12}));

    auto list2 = list;
    list2.erase(list2.begin()); // HW7 - удаление элементов из начала
    ASSERT_EQ(list2.size(), 5);
    ASSERT_EQ(list2[0], (A{3, 4}));

    list2.erase(list2.end() - 1); // HW7 - удаление элементов из конца
    ASSERT_EQ(list2.size(), 4);
    ASSERT_EQ(list2[3], (A{9, 10}));
}

// HW7 - unit-тест на удаление контейнера.
TEST(Vector, Clear) {
    Vector<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);

    list.clear();
    ASSERT_EQ(list.size(), 0);
    ASSERT_EQ(list.cap(), 0);
    ASSERT_EQ(list.begin(), list.end());
}