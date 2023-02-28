#pragma once

#include "const_iterator.hpp"

template <typename T>
class Iterator : public ConstIterator<T>
{
    public:
        Iterator(T* ptr_) : m_ptr(ptr_) {}

        Iterator<T> operator++();
        Iterator<T> operator++(int);
        T& operator*();
        T* operator->();
        friend bool operator==(const T&);
        friend bool operator!=(const T&);

    private:
        T* m_ptr;
};

#include "iterator.ipp"