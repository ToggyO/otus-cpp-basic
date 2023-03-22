#include "hw_tasks/hw_tasks.h"
#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<int> fl { 1, 2, 3 };
    std::forward_list<int> fl1(fl.begin(), fl.end());
    std::cout << fl1.front() << std::endl;
    std::forward_list<int> fl2;
    auto k = fl2.front();

    test_list();
    return 0;
}

