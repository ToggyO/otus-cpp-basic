#pragma once

#include <initializer_list>
#include <numeric>

#include "node.hpp"
#include "../iterator/separated/forward_iterator.hpp"

template <class T>
class LinkedList
{
    public:
        typedef T value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef ForwardIterator<T> Iterator;
        typedef ForwardIterator<const T> ConstIterator;

        // Ctors
        LinkedList();

        template<class FwdIt, typename = std::_RequireInputIter<FwdIt>>
        LinkedList(FwdIt begin, FwdIt end);

        LinkedList(std::initializer_list<T>);

        LinkedList(const LinkedList<T>&);

        LinkedList(LinkedList<T>&&) noexcept;

        ~LinkedList()
        {
            // TODO: check
            delete m_head;
        }

        // Methods
        void insert_after(ConstIterator, const T&);

        void insert_after(ConstIterator, const T&&);

        template<class... Args>
        void emplace_after(ConstIterator, Args&&...);

        void push_front(const T&);

        void push_front(const T&&);

        void push_back(const T&);

        void push_back(const T&&);

        template<class... Args>
        void emplace_front(Args&&...);

        template<class... Args>
        void emplace_back(Args&&...);

        void pop_front();

        void pop_back();

        void resize(size_t);

        void erase(Iterator);

        void erase(ConstIterator);

        void erase(Iterator, Iterator);

        void erase(ConstIterator, ConstIterator);

        void clear();

        // Accessors
        size_t size() const { return m_size; }

        bool empty() { return m_size == 0; }

        reference front() { return m_head->data; }

        const_reference front() const { return m_head->data; }

        reference back() { return m_head->data; }

        const_reference back() const { return m_head->data; }

        // Iterators
        Iterator begin();
    
        Iterator end();

        ConstIterator begin() const;
    
        ConstIterator end() const;
    
        ConstIterator cbegin() const;
    
        ConstIterator cend() const;

        // Operators
        LinkedList<T>& operator=(const LinkedList<T>&);

        LinkedList<T>& operator=(LinkedList<T>&&) noexcept;

    private:
        Node<T>* m_head;
        Node<T>* m_tail;
        size_t m_size;
};

#include "linked_list_ctors.ipp"
#include "linked_list_iterator.ipp"