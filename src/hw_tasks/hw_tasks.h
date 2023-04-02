#pragma once

#include <assert.h>

template<class InputIterator>
void assert_and_print(InputIterator first, InputIterator last, const int expected[])
{
    int i = 0;
    for (auto iter = first; iter != last; ++iter, i++)
    {
        int num = *iter;
        assert(num == expected[i]);
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int test_vector();

int test_forward_list();