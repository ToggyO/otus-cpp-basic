#include <gtest/gtest.h>
#include <iostream>

#include "test_struct.hpp"
#include "linked_list/linked_list.hpp"

TEST(TestLinkedListConstructors, Success) {
    LinkedList<A> list;
//    EXPECT_EQ(list.front(), nullptr);
//    EXPECT_EQ(list.back(), nullptr);

    LinkedList<A> list1 { A{1, 2}, A{3, 4}, A{5, 6} };
    for (auto iter = list1.begin(); iter != list1.end(); ++iter)
    {
        std::cout << iter->a << " " << iter->b << std::endl;
    }

}