#include "hw_tasks/hw_tasks.h"
#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<int> fl { 1, 2, 3 };
    std::forward_list<int> fl2(fl.begin(), fl.end());
    std::cout << fl.front() << std::endl;
    test_list();
    return 0;
}

