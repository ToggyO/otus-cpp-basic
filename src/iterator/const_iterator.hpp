#pragma once

template <typename T>
class ConstIterator
{
    public:
        ConstIterator(T* ptr_) : m_ptr(ptr_) {}

        ConstIterator<T> operator++();
        ConstIterator<T> operator++(int);
        const T& operator*();
        const T* operator->();
        friend bool operator==(const T&);
        friend bool operator!=(const T&);

    private:
        T* m_ptr;
};

#include "const_iterator.ipp"