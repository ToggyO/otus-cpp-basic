#include "counter_worker.hpp"

void CounterWorker::run(const std::string& path)
{
    std::thread reading_thread(&CounterWorker::m_read, std::cref(path), std::ref(*this));
    std::thread counting_thread(&CounterWorker::m_count, std::ref(*this));

    reading_thread.join();
    counting_thread.join();
}

void CounterWorker::m_read(const std::string& path, CounterWorker &worker)
{
    std::ifstream input(path);
    if (!input.is_open())
    {
        throw std::runtime_error("Failed to open file " + path);
    }

    std::for_each(std::istream_iterator<std::string>(input),
                  std::istream_iterator<std::string>(),
                  [&](const std::string &s) {
                      return worker.m_read_queue.push(std::move(utils::to_lower(s)));
                  });

    worker.m_read_queue.stop(true);
}

void CounterWorker::m_count(CounterWorker &worker)
{
    Counter c;
    std::string word;
    while (worker.m_read_queue.pop(word))
    {
        ++c[word];
    }
    worker.m_result.set_value(c);
}
