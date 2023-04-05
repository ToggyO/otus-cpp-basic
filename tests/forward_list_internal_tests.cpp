#include <gtest/gtest.h>
#include <iostream>

#include "test_struct.hpp"
#include "forward_list/forward_list.hpp"

TEST(TestForwardListConstructors, Success) {
    ForwardList<A> list;
    EXPECT_EQ(list.size(), 0);

    // Initializer list and iterator ctors
    ForwardList<A> list1 { A{1, 2}, A{3, 4}, A{5, 6} };
    EXPECT_EQ(list1.size(), 3);

    // Copy ctor
    ForwardList<A> list2(list1);
    EXPECT_EQ(list2.front(), (A{1, 2}));
    EXPECT_EQ(list2.back(), (A{5, 6}));
    EXPECT_EQ(list2.size(), 3);

    // Move ctor
    ForwardList<A> list3(std::move(list2));
    EXPECT_EQ(list3.front(), (A{1, 2}));
    EXPECT_EQ(list3.back(), (A{5, 6}));
    EXPECT_EQ(list3.size(), 3);
}

TEST(ForwardList, RangeCtorMakesCopy) {
    ForwardList<A> fw { A{1, 2}, A{3, 4}, A{5, 6} };

    ForwardList<A> fw1(fw.begin(), fw.end());

    ASSERT_EQ(fw.size(), 3);
    ASSERT_EQ(fw.front(), (A{1, 2}));
    ASSERT_EQ(fw.back(), (A{5, 6}));
}

TEST(TestForwardListClear, Success) {
    ForwardList<A> list;

    list.push_back(A{1, 2});
    list.push_back(A{3, 4});
    list.push_back(A{5, 6});

    list.clear();
    EXPECT_EQ(list.size(), 0);
}

TEST(TestForwardListOperators, Success) {
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

TEST(TestForwardListPushFront, Success) {
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

TEST(TestForwardListPushBack, Success) {
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

TEST(TestForwardListPopFront, Success) {
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

TEST(TestForwardListEmplaceAfter, Success) {
    ForwardList<A> list;

    // Iterator
    list.emplace_after(list.begin(), 1, 2);
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
}

TEST(TestForwardListInsertAfter, Success) {
    ForwardList<A> list;

    // Copy version + Const iterator
    A a(1, 2);
    list.insert_after(list.cbegin(), a);
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
    list.insert_after(list.end(), A{7, 8});
    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(list.front(), (A{1, 2}));
    EXPECT_EQ(list.back(), (A{7, 8}));
}

TEST(TestForwardListEmplaceFront, Success) {
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

TEST(TestForwardListEmplaceBack, Success) {
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

TEST(TestForwardListResize, Success) {
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

TEST(TestForwardListEraseAfter, Success) {
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
    list2.erase_after(list2.cbegin() + 1);
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