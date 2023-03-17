#pragma once

#include <iterator>

template <typename T>
class IteratorBase : public std::iterator<std::input_iterator_tag, T>
{
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;

    public:
        explicit IteratorBase(pointer ptr_) : m_ptr(ptr_) {}
        IteratorBase(const IteratorBase<value_type>& it) {}

        IteratorBase<value_type>& operator++();
        IteratorBase<value_type>& operator++(int);
        IteratorBase<value_type>& operator--();
        IteratorBase<value_type>& operator--(int);
        IteratorBase<value_type> operator+(size_t);
        IteratorBase<value_type> operator-(size_t);
        size_t operator-(const IteratorBase<value_type>&);
        reference operator*() const;
        pointer operator->() const;
        bool operator==(const IteratorBase<value_type>&) const;
        bool operator!=(const IteratorBase<value_type>&) const;

    private:
        value_type* m_ptr;
};

#include "iterator_base.ipp"