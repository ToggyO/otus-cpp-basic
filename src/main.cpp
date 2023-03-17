#include "hw_tasks/hw_tasks.h"
#include "list/list.hpp"
int main()
{
    List<int> list;
    std::next(list.begin());
    test_list();
    return 0;
}

