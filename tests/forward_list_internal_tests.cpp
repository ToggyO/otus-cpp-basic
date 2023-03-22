#include <gtest/gtest.h>
#include <iostream>

#include "test_struct.hpp"
#include "forward_list/forward_list.hpp"

TEST(TestForwardListConstructors, Success) {
    // TODO: какая то дичь
    ForwardList<A> list;
    EXPECT_ANY_THROW(list.front());
    EXPECT_EQ(list.size(), 0);
    //

    ForwardList<A> list1 { A{1, 2}, A{3, 4}, A{5, 6} };
    EXPECT_EQ(list1.size(), 3);
    // TODO: remove
    for (auto iter = list1.begin(); iter != list1.end(); ++iter)
    {
     std::cout << iter->a << " " << iter->b << std::endl;
    }
    //

    ForwardList<A> list2(list1);
    EXPECT_EQ(list2.front(), (A{1, 2}));
    EXPECT_EQ(list2.back(), (A{5, 6}));
    EXPECT_EQ(list2.size(), 3);

    ForwardList<A> list3(std::move(list2));
    EXPECT_EQ(list3.front(), (A{1, 2}));
    EXPECT_EQ(list3.back(), (A{5, 6}));
    EXPECT_EQ(list3.size(), 3);
}