#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>

#include "../iterator/sequential/iterator_base.hpp"

template <typename T>
class Vector
{
    typedef IteratorBase<T> Iterator;
    typedef IteratorBase<const T> ConstIterator;

public:
    using value_type = T; // для back_inserter

    // Ctors
    Vector();

    template<class RacIt>
    Vector(RacIt begin, RacIt end);

    Vector(std::initializer_list<T>);

    Vector(const Vector<T> &);

    Vector(Vector<T> &&) noexcept;

    // Destructor
    ~Vector()
    {
        try
        {
            ::operator delete(m_arr);
        }
        catch (const std::exception& e)
        {
            std::cerr << "ERR: " << e.what() << std::endl;
        }
    }

    // Methods
    void insert(Iterator, const T&);

    void insert(Iterator, T&&);

    void insert(ConstIterator, const T&);

    void insert(ConstIterator, T&&);

    template<class... Args>
    void emplace(Iterator, Args&&...);

    template<class... Args>
    void emplace(ConstIterator, Args&&...);

    void push_back(const T &);

    void push_back(T &&);

    template<class... Args>
    void emplace_back(Args&&...);

    void erase(Iterator pos);

    void erase(ConstIterator pos);

    void erase(Iterator first, Iterator last);

    void erase(ConstIterator first, ConstIterator last);

    void reserve(size_t new_cap);

    void clear();

    // Accessors
    size_t size() const { return m_size; }

    size_t cap() const { return m_cap; }

    bool empty() { return m_size == 0; }

    // Iterators
    Iterator begin();

    Iterator end();

    ConstIterator begin() const;

    ConstIterator end() const;

    ConstIterator cbegin() const;

    ConstIterator cend() const;

    // Operators
    Vector<T>& operator=(const Vector<T>&);

    Vector<T>& operator=(Vector<T>&&) noexcept;

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

protected:
    size_t m_size;
    size_t m_cap;
    T* m_arr;

    const static size_t m_default_cap = 4;

    struct GrowthCoefficients
    {
        constexpr static float tiny = 2;
        constexpr static float small = 1.8;
        constexpr static float medium = 1.6;
        constexpr static float large = 1.5;
    };

    struct LimitValues
    {
        constexpr static unsigned short tiny = 64;
        constexpr static unsigned short small = 512;
        constexpr static unsigned short medium = 2048;
        constexpr static unsigned short large = 4096;
    };

    void m_resize(size_t);
    size_t m_calc_capacity() const;
    void m_resize_and_restore_iterator(Iterator&);
    void m_replace_before_insert(Iterator);
};

#include "vector_ctors.ipp"
#include "vector_operators.ipp"
#include "vector_private_methods.ipp"
#include "vector_methods.ipp"
#include "vector_iterator.ipp"