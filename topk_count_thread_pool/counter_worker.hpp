#pragma once

#include <algorithm>
#include <fstream>
#include <future>
#include <iterator>
#include <map>
#include <string>
#include <thread>
#include <vector>

#include "../counter.h"
#include "../waiting_queue/waiting_queue.h"
#include "../utils/utils.h"

class CounterWorker
{
    public:
        CounterWorker() = default;
        CounterWorker(const CounterWorker &) = delete;
        CounterWorker(CounterWorker &&) = delete;

        CounterWorker& operator=(const CounterWorker &) = delete;
        CounterWorker& operator=(CounterWorker &&) = delete;

        void run(const std::string &);

        std::future<Counter> get_future() { return m_result.get_future(); }

    private:
        static void m_read(const std::string& , CounterWorker &);

        static void m_count(CounterWorker &);

        WaitingQueue<std::string> m_read_queue;
        std::promise<Counter> m_result;
};