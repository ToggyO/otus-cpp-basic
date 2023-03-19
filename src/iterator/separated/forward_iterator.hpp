#pragma once

#include <cstddef>
#include <exception>

#include "node.hpp"

template <class T>
class ForwardIterator
{
    public:
        typedef ForwardIterator<T> itr_type;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;

        explicit ForwardIterator(Node<T>* start) : m_current(start) {}

        itr_type& operator++();
        itr_type operator++(int);
        itr_type operator+(difference_type);
        reference operator*() const;
        pointer operator->() const;
        bool operator==(const itr_type&) const;
        bool operator!=(const itr_type&) const;

    private:
        Node<T>* m_current;
};

#include "forward_iterator.ipp"