#include <gtest/gtest.h>

#include "iterator/separated/forward_iterator.hpp"

TEST(TestSeparatedForwardIterator, IteratesProperlyAndAllowToMutate) {
    // TODO: check test
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
        ASSERT_EQ(*iter, i++);
        if (i == 2)
        {
            *iter = replace;
        }

        ASSERT_EQ(replace, a[2]);
    }
}