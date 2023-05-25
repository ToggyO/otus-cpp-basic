#pragma once

#include <algorithm>
#include <atomic>
#include <fstream>
#include <future>
#include <iostream>
#include <iterator>
#include <map>
#include <mutex>
#include <string>
#include <queue>

#include "../waiting_queue/waiting_queue.h"
#include "../utils/utils.h"

class TopKWordCounter
{
    public: // TODO: правило 5
        typedef std::map<std::string, std::size_t> Counter;

        TopKWordCounter();

        TopKWordCounter(const TopKWordCounter &) = delete;
        TopKWordCounter(TopKWordCounter &&) = delete;

        TopKWordCounter &operator=(const TopKWordCounter &) = delete;
        TopKWordCounter &operator=(TopKWordCounter &&) = delete;

        void count_topk(const std::vector<std::string>&);

        std::future<Counter> get_future() { return m_result.get_future(); }

    private:
        static void m_count_words(const std::string &, TopKWordCounter &);

        static void m_process_queue(TopKWordCounter &);

        static void m_watch_for_stop_signal(TopKWordCounter &);

        WaitingQueue<std::string> m_word_queue;
        std::mutex m_wait_mutex;
        std::promise<Counter> m_result;
        std::atomic_size_t m_threads_waiting;
        std::condition_variable m_wait_cv;
};
