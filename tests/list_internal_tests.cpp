#include <gtest/gtest.h>

#include "list/list.hpp"

struct A
{
    A() = default;

    A(int a_, int b_) : a(a_), b(b_) {}

    int a;
    double b;

    A(const A& other)
    {
        a = other.a;
        b = other.b;
    }

    A(A&& other) noexcept
    {
        a = other.a;
        b = other.b;

        other.a = 0;
        other.b = 0;
    }

    ~A() = default;

    A& operator=(const A& other)
    {
        if (*this != other)
        {
            a = other.a;
            b = other.b;
        }

        return *this;
    }

    A& operator=(A&& other) noexcept
    {
        if (*this != other)
        {
            a = other.a;
            b = other.b;

            other.a = 0;
            other.b = 0;
        }

        return *this;
    }

    bool operator==(const A& other) const
    {
        return a == other.a && b == other.b;
    }

    bool operator!=(const A& other) const
    {
        return a != other.a || b != other.b;
    }
};

TEST(TestConstructors, Success) {
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

TEST(TestListResize, Success) {
    int expected_cap = 4;
    int new_cap = 10;

    List<A> list(1);

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);
    ASSERT_EQ(expected_cap, list.cap());


    list.resize(new_cap);
    ASSERT_EQ(new_cap, list.cap());

    list.emplace_back(7, 8);
    ASSERT_EQ(4, list.size());
    ASSERT_EQ(new_cap, list.cap());
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], (A{3, 4}));
    ASSERT_EQ(list[2], (A{5, 6}));
    ASSERT_EQ(list[3], (A{7, 8}));
}

TEST(TestIndexator, Success) {
    int val = 5;
    List<int> list;

    list[0] = val;
    ASSERT_EQ(val, list[0]);
}

TEST(TestIndexator, ThrowsIndexOutOfRange) {
    int val = 5;
    List<int> list;

    EXPECT_THROW(list[4] = val, std::out_of_range);
}

TEST(TestEmplaceBack, Success) {
    List<A> list;

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

TEST(TestPushBack, Success) {
    List<A> list;

    // Move version
    list.push_back(A{1, 2});
    ASSERT_EQ(list[0], (A{1, 2}));

    // Copy version
    A a = A{3, 4};
    list.push_back(a);
    ASSERT_EQ(list[1], a);

    a.a = 10;
    std::cout << list[1].a << std::endl;
}

TEST(TestInsert, Success) {
    List<A> list;

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
}

TEST(TestErase, Success) {
    List<A> list;

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.emplace_back(5, 6);
    list.emplace_back(7, 8);
    list.emplace_back(9, 10);
    list.emplace_back(11, 12);

    list.pop_first();

    for (auto i = list.cbegin(); i != list.cend(); ++i)
    {
        std::cout << i->a << " " <<  i->b << std::endl;
    }

    list.erase(list.begin() + 1, list.end() - 3);
    std::cout << std::endl;
    for (auto i = list.cbegin(); i != list.cend(); ++i)
    {
        std::cout << i->a << " " <<  i->b << std::endl;
    }

    ASSERT_EQ(list.size(), 4);
    ASSERT_EQ(list[0], (A{1, 2}));
    ASSERT_EQ(list[1], (A{7, 18}));
    ASSERT_EQ(list[2], (A{9, 10}));
    ASSERT_EQ(list[3], (A{11, 12}));
}