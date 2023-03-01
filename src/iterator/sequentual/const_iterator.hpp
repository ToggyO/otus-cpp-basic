#pragma once

template <typename T>
class ConstIterator
{
    public:
        explicit ConstIterator(T* ptr_) : m_ptr(ptr_) {}

        ConstIterator<T>& operator++();
        ConstIterator<T>& operator++(int);
        const T& operator*();
        const T* operator->();
        bool operator==(const ConstIterator<T>&);
        bool operator!=(const ConstIterator<T>&);

    private:
        T* m_ptr;
};

#include "const_iterator.ipp"