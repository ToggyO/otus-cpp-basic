#include <assert.h>
#include <iostream>

#include "hw_tasks.h"
#include "../vector/vector.hpp"

int test_vector()
{
    int exit_code = 0;

    std::cout << "Vector:" << std::endl;
    try
    {
        // 1. создание объекта контейнера для хранения объектов типа int
        // 2. добавление в контейнер десяти элементов (0, 1 … 9)
        Vector<int> vector { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        // 3. вывод содержимого контейнера на экран
        // ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        int expected_num = 0;
        for (auto iter = vector.cbegin(); iter != vector.cend(); ++iter)
        {
            assert(*iter == expected_num);
            std::cout << *iter << " ";
            expected_num++;
        }
        std::cout << std::endl;

        // 4. вывод размера контейнера на экран
        // ожидаемый результат: 10
        size_t size = vector.size();
        assert(size == 10);
        std::cout << size << std::endl;

        // 5. удаление третьего (по счёту), пятого и седьмого элементов
        vector.erase(vector.begin() + 2);
        vector.erase(vector.begin() + 3);
        vector.erase(vector.begin() + 4);

        // 6. вывод содержимого контейнера на экран
        // ожидаемый результат: 0, 1, 3, 5, 7, 8, 9
        int expected_arr_6[] = { 0, 1, 3, 5, 7, 8, 9 };
        assert_and_print(vector.begin(), vector.end(), expected_arr_6);

        // 7. добавление элемента 10 в начало контейнера
        // 8. вывод содержимого контейнера на экран
        // ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9
        vector.emplace(vector.cbegin(), 10);
        int expected_arr_7_8[] = { 10, 0, 1, 3, 5, 7, 8, 9 };
        assert_and_print(vector.begin(), vector.end(), expected_arr_7_8);

        // 9. добавление элемента 20 в середину контейнера
        // 10. вывод содержимого контейнера на экран
        // ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9
        vector.insert(vector.cbegin() + 4, 20);
        int expected_arr_9_10[] = { 10, 0, 1, 3, 20, 5, 7, 8, 9 };
        assert_and_print(vector.begin(), vector.end(), expected_arr_9_10);

        // 11. добавление элемента 30 в конец контейнера
        // 12. вывод содержимого контейнера на экран
        // ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30
        vector.push_back(30);
        int expected_arr_11_12[] = { 10, 0, 1, 3, 20, 5, 7, 8, 9, 30 };
        assert_and_print(vector.begin(), vector.end(), expected_arr_11_12);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit_code = -1;
    }
    
    std::cout << std::endl;
    return exit_code;
}