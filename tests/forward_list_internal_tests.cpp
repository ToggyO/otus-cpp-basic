#include <gtest/gtest.h>
#include <iostream>

#include "test_struct.hpp"
#include "forward_list/forward_list.hpp"


TEST(ForwardList, Constructors) {
    ForwardList<A> list; // HW7 - cоздание контейнера
    EXPECT_EQ(list.size(), 0);

    // Initializer list and iterator ctors
    ForwardList<A> list1 { A{1, 2}, A{3, 4}, A{5, 6} };
    EXPECT_EQ(list1.size(), 3);

    // Copy ctor
    ForwardList<A> list2(list1); // HW7 - unit-тест на копирование контейнера
    EXPECT_EQ(list2.front(), (A{1, 2})); // HW7 - получение элементов из контейнера
    EXPECT_EQ(list2.back(), (A{5, 6}));
    EXPECT_EQ(list2.size(), 3);

    // Move ctor
    ForwardList<A> list3(std::move(list2)); // HW7 - unit-тест на перемещение контейнера
    EXPECT_EQ(list3.front(), (A{1, 2}));
    EXPECT_EQ(list3.back(), (A{5, 6}));
    EXPECT_EQ(list3.size(), 3);
}

// HW7 - unit-тест на удаление контейнера
TEST(ForwardList, Clear) {
    ForwardList<A> list;

    list.push_back(A{1, 2});
    list.push_back(A{3, 4});
    list.push_back(A{5, 6});

    list.clear();
    EXPECT_EQ(list.size(), 0);
}

TEST(ForwardList, Operators) {
    ForwardList<A> list { A{1, 2}, A{3, 4}, A{5, 6} };

    // Copy operator
    ForwardList<A> list1 = list;
    EXPECT_EQ(list1.size(), 3);
    EXPECT_EQ(list1.front(), (A{1, 2}));
    EXPECT_EQ(list1.back(), (A{5, 6}));

    // Move operator
    ForwardList<A> list2 = std::move(list1);
    EXPECT_EQ(list2.size(), 3);
    EXPECT_EQ(list2.front(), (A{1, 2}));
    EXPECT_EQ(list2.back(), (A{5, 6}));
}

// HW7 - вставка элементов в начало
TEST(ForwardList, PushFront) {
    ForwardList<A> list;

    A a1(1, 2);

    // Copy version
    list.push_front(a1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), a1);
    EXPECT_EQ(list.back(), a1);

    A a2 = A(3, 4);
    list.push_front(a2);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), a2);
    EXPECT_EQ(list.back(), a1);

    // Move version
    list.push_front(A{5, 6});
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), (A{5, 6}));
    EXPECT_EQ(list.back(), a1);
}

// HW7 - вставка элементов в конец
TEST(ForwardList, PushBack) {
    ForwardList<A> list;

    A a1(1, 2);

    // Copy version
    list.push_back(a1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), a1);
    EXPECT_EQ(list.back(), a1);

    A a2 = A(3, 4);
    list.push_back(a2);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), a1);
    EXPECT_EQ(list.back(), a2);

    // Move version
    list.push_back(A{5, 6});
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), a1);
    EXPECT_EQ(list.back(), (A{5, 6}));
}

// HW7 - удаление элементов из начала
TEST(ForwardList, PopFront) {
    ForwardList<A> list;

    list.push_back(A{1, 2});
    list.push_back(A{3, 4});
    list.push_back(A{5, 6});
    EXPECT_EQ(list.size(), 3);

    list.pop_front();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), (A{3, 4}));

    list.pop_front();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), (A{5, 6}));
}

TEST(ForwardList, EmplaceAfter) {
    ForwardList<A> list;

    // Iterator
    list.emplace_after(list.begin(), 1, 2); // HW7 - вставка элементов в середину
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{1, 2}));

    list.emplace_after(list.begin(), 3, 4);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{3, 4}));

    // Const iterator
    list.emplace_after(list.cbegin(), 5, 6);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{3, 4}));

    list.emplace_after(list.before_begin(), 111, 222); // HW7 - вставка элементов в начало
    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(list.front(), (A{111, 222}));
    EXPECT_EQ(list.back(), (A{3, 4}));
}

TEST(TestForwardListInsertAfter, Success) {
    ForwardList<A> list;

    // Copy version + Const iterator
    A a(1, 2);
    list.insert_after(list.cbegin(), a); // HW7 - вставка элементов в начало
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{1, 2}));

    // Move version + Const iterator
    list.insert_after(list.cbegin(), A{3, 4});
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{3, 4}));

    // Copy version + Iterator
    a = A{5, 6};
    list.insert_after(list.begin(), a);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{3, 4}));

    // Mopy version + Iterator
    list.insert_after(list.end(), A{7, 8}); // HW7 - вставка элементов в конец
    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{7, 8}));
}

// HW7 - вставка элементов в начало
TEST(ForwardList, EmplaceFront) {
    ForwardList<A> list;

    list.emplace_front(1, 2);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{1, 2}));

    list.emplace_front(3, 4);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), (A{3, 4}));
    EXPECT_EQ(list.back(), (A{1, 2}));
}

// HW7 - вставка элементов в конец
TEST(ForwardList, EmplaceBack) {
    ForwardList<A> list;

    list.emplace_back(1, 2);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{1, 2}));

    list.emplace_back(3, 4);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{3, 4}));
}

TEST(ForwardList, Resize) {
    ForwardList<A> list;

    list.push_back(A{1, 2});
    list.push_back(A{3, 4});
    list.push_back(A{5, 6});
    list.push_back(A{7, 8});
    EXPECT_EQ(list.size(), 4);

    // Fill by default values
    size_t resize_count = 6;
    list.resize(resize_count);
    EXPECT_EQ(list.size(), resize_count);

    // Reduce list
    resize_count = 4;
    list.resize(resize_count);
    EXPECT_EQ(list.size(), resize_count);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{7, 8}));
}

TEST(ForwardList, EraseAfter) {
    ForwardList<A> list;

    list.push_back(A{1, 2});
    list.push_back(A{3, 4});
    list.push_back(A{5, 6});
    list.push_back(A{7, 8});

    // Range + Const iterator
    auto list1 = list;
    list1.erase_after(list1.cbegin(), list1.cbegin() + 3);
    EXPECT_EQ(list1.size(), 2);
    EXPECT_EQ(list1.front(), (A{1, 2}));
    EXPECT_EQ(list1.back(), (A{7, 8}));

    // Single position + Const iterator
    auto list2 = list;
    list2.erase_after(list2.cbegin() + 1); // HW7 - удаление элементов из середины
    EXPECT_EQ(list2.size(), 3);
    EXPECT_EQ(list2.front(), (A{1, 2}));
    EXPECT_EQ(list2.back(), (A{7, 8}));

    // Range + Iterator
    auto list3 = list;
    list3.erase_after(list3.before_begin(), list3.end());
    EXPECT_EQ(list3.size(), 0);

    // Single position + Iterator
    auto list4 = list;
    list4.erase_after(list4.before_begin());
    EXPECT_EQ(list4.size(), 3);
    EXPECT_EQ(list4.front(), (A{3, 4}));
    EXPECT_EQ(list4.back(), (A{7, 8}));
}