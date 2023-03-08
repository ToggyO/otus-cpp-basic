#pragma once

#include "const_iterator.hpp"

template <typename T>
class Iterator
{
    public:
        explicit Iterator(T* ptr_) : m_ptr(ptr_) {}

        Iterator<T>& operator++();
        Iterator<T>& operator++(int);
        Iterator<T>& operator--();
        Iterator<T>& operator--(int);
        Iterator<T> operator+(size_t);
        Iterator<T> operator-(size_t);
        size_t operator-(const Iterator<T>&);
        T& operator*();
        T* operator->();
        bool operator==(const Iterator<T>&);
        bool operator!=(const Iterator<T>&);

    private:
        T* m_ptr;
};

#include "iterator.ipp"