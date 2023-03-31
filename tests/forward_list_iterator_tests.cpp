#include <gtest/gtest.h>

#include "node.hpp"
#include "forward_list/iterator/forward_list_iterator.hpp"
#include "forward_list/iterator/forward_list_const_iterator.hpp"

template <class T>
void remove_recursively(const Node<T>* node)
{
    auto current = node;
    while (current != nullptr)
    {
        auto next = current->next;
        delete current;
        current = next;
    }
}

TEST(TestForwardListIterator, IteratesProperlyAndAllowToMutate) {
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
    remove_recursively(head);
}

TEST(TestForwardListConstIterator, IteratesProperlyAndAllowToMutate) {
    auto head = new Node<int>(1);
    auto current = head;

    for (int i = 2; i <= 4; i++)
    {
        current->next = new Node<int>(i);
        current = current->next;
    }

    auto start = ConstForwardIterator<int>(head);
    auto end = ConstForwardIterator<int>(nullptr);

    int i = 1;
    for (auto iter = start; iter != end; ++iter)
    {
        ASSERT_EQ(*iter, i);
        i++;
    }

    ASSERT_EQ(1, *start);
    remove_recursively(head);
}