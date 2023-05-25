#include "topk_count_thread_pool.hpp"

void TopkCountThreadPool::run(const std::vector<std::string> &file_paths)
{
    m_threads.reserve(file_paths.size());

    std::future<void> result = std::async(std::launch::async, &TopkCountThreadPool::m_process_queue, std::ref(*this));

    for (const auto& path : file_paths)
    {
        std::thread t(&TopkCountThreadPool::m_internal_run, std::cref(path), std::ref(*this));
        m_threads.push_back(std::move(t));
    }

    for (auto& t : m_threads)
    {
        t.join();
    }

    m_results.stop(true);
    result.wait();
}

void TopkCountThreadPool::m_internal_run(const std::string &path, TopkCountThreadPool &threadPool)
{
    CounterWorker worker;
    auto future = worker.get_future();
    worker.run(path);
    threadPool.m_results.push(std::move(future));
}

void TopkCountThreadPool::m_process_queue(TopkCountThreadPool &threadPool)
{
    Counter c;
    std::future<Counter> f;
    while (threadPool.m_results.pop(f))
    {
        auto result_counter = f.get();
        TopkCountThreadPool::m_merge(c, result_counter);
    }
    threadPool.m_promise.set_value(c);
}

void TopkCountThreadPool::m_merge(Counter &left, Counter &right)
{
    for (auto &iter : right)
    {
        left[iter.first] += iter.second;
    }
}