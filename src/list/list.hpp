#pragma once

#include <cstddef>

#include "iterator/sequential/iterator_base.hpp"

template <typename T>
class List
{
    typedef IteratorBase<T> Iterator;
    typedef IteratorBase<const T> ConstIterator;

public:
    // Ctors
    List();

    List(const List<T> &);

    List(List<T> &&) noexcept;

    // Destructor
    virtual ~List()
    {
        // TODO: remove
        std::cout << "~List()" << std::endl;
        //
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

    void insert(ConstIterator, const T&); // TODO:

    void insert(ConstIterator, T&&); // TODO:

    template<class... Args>
    void emplace(Iterator, Args&&...); // TODO:

    template<class... Args>
    void emplace(ConstIterator, Args&&...); // TODO:

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

    size_t size() const { return m_size; }

    size_t cap() const { return m_cap; }

    // Iterator
    Iterator begin();

    Iterator end();

    ConstIterator cbegin();

    ConstIterator cend();

    // Operators
    List<T>& operator=(const List<T>&);

    List<T>& operator=(List<T>&&) noexcept;

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
    void m_erase(IteratorBase<T>, IteratorBase<T>);
};

#include "list_ctors.ipp"
#include "list_operators.ipp"
#include "list_private_methods.ipp"
#include "list_methods.ipp"
#include "list_iterator.ipp"



// TODO: remove
//#pragma once
//
//#include <cstddef>
//
////#include "iterator/sequential/iterator.hpp"
////#include "iterator/sequential/const_iterator.hpp"
//#include "iterator/sequential/iterator_base.hpp"
//
//template <typename T>
//class List
//{
//    typedef IteratorBase<T> Iterator;
//    typedef IteratorBase<const T> ConstIterator;
//
//    public:
//        // Ctors
//        List();
//
//        List(const List<T> &);
//
//        List(List<T> &&) noexcept;
//
//        // Destructor
//        virtual ~List()
//        {
//            // TODO: remove
//            std::cout << "~List()" << std::endl;
//            //
//            try
//            {
//                ::operator delete(m_arr);
//            }
//            catch (const std::exception& e)
//            {
//                std::cerr << "ERR: " << e.what() << std::endl;
//            }
//        }
//
//        // Methods
//        void insert(Iterator<T>, const T&);
//
//        void insert(Iterator<T>, T&&);
//
//        void insert(ConstIterator<T>, const T&); // TODO:
//
//        void insert(ConstIterator<T>, T&&); // TODO:
//
//        template<class... Args>
//        void emplace(Iterator<T>, Args&&...); // TODO:
//
//        template<class... Args>
//        void emplace(ConstIterator<T>, Args&&...); // TODO:
//
//        void push_back(const T &);
//
//        void push_back(T &&);
//
//        template<class... Args>
//        void emplace_back(Args&&...);
//
//        void erase(Iterator<T> pos);
//
//        void erase(ConstIterator<T> pos);
//
//        void erase(Iterator<T> first, Iterator<T> last);
//
//        void erase(ConstIterator<T> first, ConstIterator<T> last);
//
//        void reserve(size_t new_cap);
//
//        void clear();
//
//        size_t size() const { return m_size; }
//
//        size_t cap() const { return m_cap; }
//
//        // Iterator
//        Iterator<T> begin();
//
//        Iterator<T> end();
//
//        ConstIterator<T> cbegin();
//
//        ConstIterator<T> cend();
//
//        // Operators
//        List<T>& operator=(const List<T>&);
//
//        List<T>& operator=(List<T>&&) noexcept;
//
//        T& operator[](size_t index);
//
//        const T& operator[](size_t index) const;
//
//    protected:
//        size_t m_size;
//        size_t m_cap;
//        T* m_arr;
//
//        const static size_t m_default_cap = 4;
//
//        struct GrowthCoefficients
//        {
//            constexpr static float tiny = 2;
//            constexpr static float small = 1.8;
//            constexpr static float medium = 1.6;
//            constexpr static float large = 1.5;
//        };
//
//        struct LimitValues
//        {
//            constexpr static unsigned short tiny = 64;
//            constexpr static unsigned short small = 512;
//            constexpr static unsigned short medium = 2048;
//            constexpr static unsigned short large = 4096;
//        };
//
//        void m_resize(size_t);
//        size_t m_calc_capacity() const;
//        void m_resize_and_restore_iterator(Iterator<T>&);
//        void m_replace_before_insert(Iterator<T>);
//};
//
//#include "list_ctors.ipp"
//#include "list_operators.ipp"
//#include "list_private_methods.ipp"
//#include "list_methods.ipp"
//#include "list_iterator.ipp"
