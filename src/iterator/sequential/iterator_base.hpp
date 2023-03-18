#pragma once

#include <iterator>

template <typename T>
class IteratorBase
{
    public:
        typedef IteratorBase<T> itr_type;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef std::random_access_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;

        explicit IteratorBase(pointer ptr_) : m_ptr(ptr_) {}

        itr_type& operator++();
        itr_type operator++(int);
        itr_type& operator--();
        itr_type operator--(int);
        itr_type operator+(difference_type);
        itr_type operator-(difference_type);
        difference_type operator-(const itr_type&);
        itr_type& operator+=(difference_type);
        itr_type& operator-=(difference_type);
        reference operator*() const;
        pointer operator->() const;
        bool operator==(const itr_type&) const;
        bool operator!=(const itr_type&) const;

    private:
        pointer m_ptr;
};


#include "iterator_base.ipp"