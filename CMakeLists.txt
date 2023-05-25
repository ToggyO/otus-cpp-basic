cmake_minimum_required(VERSION 3.5)

project(07.homework CXX)

find_package(Threads REQUIRED)

add_executable(top_words_sync
    topk_words_sync.cpp
    utils/utils.cpp
    utils/utils.h
)

add_executable(top_words_async
    topk_words_async.cpp
    word_counter/topk_word_counter.cpp
    word_counter/topk_word_counter.hpp
    waiting_queue/waiting_queue.h
    utils/utils.cpp
    utils/utils.h
)

add_executable(top_words_async2
    topk_words_async2.cpp
    counter.h
    utils/utils.cpp
    utils/utils.h
    topk_count_thread_pool/topk_count_thread_pool.hpp
    topk_count_thread_pool/topk_count_thread_pool.cpp
    topk_count_thread_pool/counter_worker.hpp
    topk_count_thread_pool/counter_worker.cpp
    waiting_queue/waiting_queue.h
)

target_link_libraries(top_words_async PUBLIC Threads::Threads)
target_link_libraries(top_words_async2 PUBLIC Threads::Threads)