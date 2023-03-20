#include <gtest/gtest.h>

#include "iterator/separated/forward_iterator.hpp"

TEST(TestSeparatedForwardIterator, IteratesProperlyAndAllowToMutate) {
    auto head = new Node<int>(1);
    auto current = head;
    int replace = 69;

    for (int i = 2; i <= 4; i++)
    {
        current->next = new Node<int>(i);
        current = current->next;
    }

    auto start = ForwardIterator<int>(head);
    auto end = ForwardIterator<int>(nullptr);

    int i = 1;
    for (auto iter = start; iter != end; ++iter)
    {
        ASSERT_EQ(*iter, i);
        if (i == 1)
        {
            *iter = replace;
        }
        i++;
    }

    ASSERT_EQ(replace, *start);
}