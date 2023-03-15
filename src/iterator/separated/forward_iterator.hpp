#pragma once

#include <cstddef>
#include <exception>

#include "node.hpp"

template <class T>
class ForwardIterator
{
    typedef T& reference;
    typedef T* pointer;

    public:
        explicit ForwardIterator(Node<T>* start) : m_current(start) {}

        ForwardIterator<T>& operator++();
        ForwardIterator<T>& operator++(int);
        ForwardIterator<T> operator+(size_t);
        reference operator*();
        pointer operator->();
        bool operator==(const ForwardIterator<T>&);
        bool operator!=(const ForwardIterator<T>&);

    private:
        Node<T>* m_current;
};

#include "forward_iterator.ipp"