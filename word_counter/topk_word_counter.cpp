#include "topk_word_counter.hpp"

TopKWordCounter::TopKWordCounter() : m_threads_waiting(0)
{}

void TopKWordCounter::count_topk(const std::vector<std::string>& file_paths) // TODO: check arg
{
    std::thread t2(&TopKWordCounter::m_watch_for_stop_signal, std::ref(*this));
    t2.detach();

    for (const auto& path : file_paths)
    {
        m_threads_waiting++;
        std::thread t(&TopKWordCounter::m_count_words, std::cref(path), std::ref(*this));
        t.detach();
    }

    std::thread consumer_thread(&TopKWordCounter::m_process_queue, std::ref(*this));
    consumer_thread.join();
}

void TopKWordCounter::m_watch_for_stop_signal(TopKWordCounter &counter)
{
    std::unique_lock<std::mutex> ulk(counter.m_wait_mutex);
    counter.m_wait_cv.wait(ulk, [&]() { return counter.m_threads_waiting.load() == 0; });

    while (!counter.m_word_queue.empty())
    {}

    counter.m_word_queue.stop();
}

void TopKWordCounter::m_count_words(const std::string& path, TopKWordCounter& counter)
{
    std::ifstream input(path);
    if (!input.is_open())
    {
        throw std::runtime_error("Failed to open file " + path);
    }

    std::for_each(std::istream_iterator<std::string>(input),
                  std::istream_iterator<std::string>(),
                  [&](const std::string &s) { return counter.m_word_queue.push(std::move(utils::to_lower(s))); });

    counter.m_threads_waiting--;
    counter.m_wait_cv.notify_one();
}

void TopKWordCounter::m_process_queue(TopKWordCounter &wordCounter)
{
    Counter c;
    std::string word;

    while (wordCounter.m_word_queue.pop(word))
    {
        ++c[word];
    }

    wordCounter.m_result.set_value(c);
}