#include <iostream>

#include "list/list.hpp"

struct A
{
    int a;
    double b;
};

int main()
{
    int size = 5;

    std::cout << size << std::endl;
    List<A> list(size);

    List<A> list1(list);

    std::cout << std::boolalpha << (list1.size() == list.size()) << std::endl;

    return 0;
}