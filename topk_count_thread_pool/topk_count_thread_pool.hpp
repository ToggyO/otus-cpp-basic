#pragma once

#include <algorithm>
#include <fstream>
#include <future>
#include <iterator>
#include <map>
#include <string>
#include <vector>

#include "../counter.h"
#include "counter_worker.hpp"

class TopkCountThreadPool
{
    public:
        TopkCountThreadPool() = default;
        TopkCountThreadPool(const TopkCountThreadPool &) = delete;
        TopkCountThreadPool(TopkCountThreadPool &&) = delete;

        TopkCountThreadPool& operator=(const TopkCountThreadPool &) = delete;
        TopkCountThreadPool& operator=(TopkCountThreadPool &&) = delete;

        void run(const std::vector<std::string> &file_paths);

        std::future<Counter> get_future() { return m_promise.get_future(); }

    private:
        static void m_internal_run(const std::string &, TopkCountThreadPool &);

        static void m_process_queue(TopkCountThreadPool &);

        static void m_merge(Counter &, Counter &);

        std::vector<std::thread> m_threads;
        WaitingQueue<std::future<Counter>> m_results;
        std::promise<Counter> m_promise;
        std::condition_variable m_wait_cv;
};