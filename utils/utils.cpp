#include <algorithm>
#include <vector>
#include <iomanip>

#include "utils.h"

void utils::print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
            std::begin(words), std::begin(words) + k, std::end(words),
            [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
            std::begin(words), std::begin(words) + k,
            [&stream](const Counter::const_iterator &pair) {
                stream << std::setw(4) << pair->second << " " << pair->first
                       << '\n';
            });
}

std::string utils::to_lower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
};