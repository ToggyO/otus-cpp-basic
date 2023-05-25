// Read files and prints top k word by frequency

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <chrono>

#include "word_counter/topk_word_counter.hpp"
#include "utils/utils.h"

const size_t TOPK = 10;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: topk_words [FILES...]\n";
        return EXIT_FAILURE;
    }

    std::vector<std::string> v;
    v.reserve(argc);
    for (int i = 1; i < argc; ++i)
    {
       v.push_back(std::move(std::string(argv[i])));
    }

    auto start = std::chrono::high_resolution_clock::now();

    TopKWordCounter counter;
    auto future = counter.get_future();

    counter.count_topk(v);
    utils::print_topk(std::cout, future.get(), TOPK);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
}