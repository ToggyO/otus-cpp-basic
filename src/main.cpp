#include "hw_tasks/hw_tasks.h"
#include <forward_list>
#include <iostream>

#include "fl.hpp"
#include "node.hpp"

struct A
{
    int a;
    int b;
};

int main()
{
    std::forward_list<int> fl { 1, 2, 3 };
    std::forward_list<int> fl1(fl.begin(), fl.end());
    std::cout << fl1.front() << std::endl;
    std::forward_list<int> fl2;
//    auto k = fl2.front();

//    std::unique_ptr<custom::node<A>> node = std::make_unique<custom::node<A>>(nullptr, A{1, 2});
    auto node = new custom::node<A>(nullptr, A{1, 2});
    custom::linked_list_forward_iterator<A> lit(node);
    std::cout << lit->a <<std::endl;

    test_list();
    return 0;
}

