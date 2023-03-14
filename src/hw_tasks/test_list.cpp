#include <assert.h>
#include <iostream>

#include "hw_tasks.h"
#include "../list/list.hpp"

template<typename T>
void assert_and_print_list(List<T>& l, const int expected[])
{
    int i = 0;
    for (auto iter = l.cbegin(); iter != l.cend(); ++iter, i++)
    {
        int num = *iter;
        assert(num == expected[i]);
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int test_list()
{
    int exit_code = 0;

    try
    {
        // 1. создание объекта контейнера для хранения объектов типа int
        // 2. добавление в контейнер десяти элементов (0, 1 … 9)
        List<int> list { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        // 3. вывод содержимого контейнера на экран
        // ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        int expected_num = 0;
        for (auto iter = list.cbegin(); iter != list.cend(); ++iter)
        {
            assert(*iter == expected_num);
            expected_num++;
        }

        // 4. вывод размера контейнера на экран
        // ожидаемый результат: 10
        size_t size = list.size();
        assert(size == 10);
        std::cout << size << std::endl;

        // 5. удаление третьего (по счёту), пятого и седьмого элементов
        list.erase(list.begin() + 2);
        list.erase(list.begin() + 3);
        list.erase(list.begin() + 4);

        // 6. вывод содержимого контейнера на экран
        // ожидаемый результат: 0, 1, 3, 5, 7, 8, 9
        int expected_arr_6[] = { 0, 1, 3, 5, 7, 8, 9 };
        assert_and_print_list(list, expected_arr_6);

        // 7. добавление элемента 10 в начало контейнера
        // 8. вывод содержимого контейнера на экран
        // ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9
        list.emplace(list.cbegin(), 10);
        int expected_arr_7_8[] = { 10, 0, 1, 3, 5, 7, 8, 9 };
        assert_and_print_list(list, expected_arr_7_8);

        // 9. добавление элемента 20 в середину контейнера
        // 10. вывод содержимого контейнера на экран
        // ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9
        list.insert(list.cbegin() + 4, 20);
        int expected_arr_9_10[] = { 10, 0, 1, 3, 20, 5, 7, 8, 9 };
        assert_and_print_list(list, expected_arr_9_10);

        // 11. добавление элемента 30 в конец контейнера
        // 12. вывод содержимого контейнера на экран
        // ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30
        list.push_back(30);
        int expected_arr_11_12[] = { 10, 0, 1, 3, 20, 5, 7, 8, 9, 30 };
        assert_and_print_list(list, expected_arr_11_12);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit_code = -1;
    }
    
    return exit_code;
}