#pragma once

#include "const_iterator.hpp"

template <typename T>
class Iterator
{
    public:
        explicit Iterator(T* ptr_) : m_ptr(ptr_) {}

        Iterator<T>& operator++();
        Iterator<T>& operator++(int);
        T& operator*();
        T* operator->();
        bool operator==(const Iterator<T>&);
        bool operator!=(const Iterator<T>&);

    private:
        T* m_ptr;
};

#include "iterator.ipp"