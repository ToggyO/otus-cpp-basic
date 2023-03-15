#include <gtest/gtest.h>

#include "iterator/sequential/iterator_base.hpp"
#include "iterator/separated/forward_iterator.hpp"
#include "node.hpp"

TEST(TestSequentialIterator, IteratesProperlyAndAllowToMutate) {
    int replace = 17;
    int a[5] { 1, 2, 3, 4, 5 };
    int* ptr = a;

    auto start = IteratorBase<int>(ptr);
    auto end = IteratorBase<int>(ptr + 5);
    int i = 0;
    for (auto iter = start ; iter != end; ++iter, ++i)
    {
        ASSERT_EQ(a[i], *iter);
        if (i == 2)
        {
            *iter = replace;
        }
    }

    ASSERT_EQ(replace, a[2]);
}

TEST(TestSeparatedForwardIterator, IteratesProperlyAndAllowToMutate) {
    Node<int>* head = new Node<int>(1);
    Node<int>* current = head;

    for (int i = 2; i <= 4; i++)
    {
        current->next = new Node<int>(i);
        current = current->next;
    }

    auto start = ForwardIterator<int>(head);
    auto end = ForwardIterator<int>(nullptr);

    for (auto iter = start; iter != end; ++iter)
    {
        std::cout << *iter << std::endl;
        std::cout << iter-> << std::endl;
    }
}