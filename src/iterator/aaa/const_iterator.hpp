#pragma once

template <typename T>
class ConstIterator
{
    public:
        explicit ConstIterator(T* ptr_) : m_ptr(ptr_) {}

        ConstIterator<T>& operator++();
        ConstIterator<T>& operator++(int);
        ConstIterator<T>& operator--();
        ConstIterator<T>& operator--(int);
        ConstIterator<T> operator+(size_t);
        ConstIterator<T> operator-(size_t);
        size_t operator-(const ConstIterator<T>&);
        const T& operator*();
        const T* operator->();
        bool operator==(const ConstIterator<T>&);
        bool operator!=(const ConstIterator<T>&);

    private:
        T* m_ptr;

        // TODO: remove
        template<class U>
        friend U* m_get_ptr(const ConstIterator<U>&);
};

#include "const_iterator.ipp"