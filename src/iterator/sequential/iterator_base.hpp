#pragma once

template <typename T>
class IteratorBase
{
    typedef T& reference;
    typedef T* pointer;

    public:
        explicit IteratorBase(pointer ptr_) : m_ptr(ptr_) {}

        IteratorBase<T>& operator++();
        IteratorBase<T>& operator++(int);
        IteratorBase<T>& operator--();
        IteratorBase<T>& operator--(int);
        IteratorBase<T> operator+(size_t);
        IteratorBase<T> operator-(size_t);
        size_t operator-(const IteratorBase<T>&);
        reference operator*();
        pointer operator->();
        bool operator==(const IteratorBase<T>&);
        bool operator!=(const IteratorBase<T>&);

    private:
        T* m_ptr;
};

#include "iterator_base.ipp"