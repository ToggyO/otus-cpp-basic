#pragma once

template <typename T>
class IteratorBase
{
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;

    public:
        explicit IteratorBase(pointer ptr_) : m_ptr(ptr_) {}

        IteratorBase<value_type>& operator++();
        IteratorBase<value_type>& operator++(int);
        IteratorBase<value_type>& operator--();
        IteratorBase<value_type>& operator--(int);
        IteratorBase<value_type> operator+(size_t);
        IteratorBase<value_type> operator-(size_t);
        size_t operator-(const IteratorBase<value_type>&);
        reference operator*();
        pointer operator->();
        bool operator==(const IteratorBase<value_type>&);
        bool operator!=(const IteratorBase<value_type>&);

    private:
        value_type* m_ptr;
};

#include "iterator_base.ipp"