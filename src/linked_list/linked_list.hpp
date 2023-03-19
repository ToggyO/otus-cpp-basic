#pragma once

#include <initializer_list>

#include "node.hpp"
#include "../iterator/separated/forward_iterator.hpp"

template <class T>
class LinkedList
{
    typedef ForwardIterator<T> Iterator;
    typedef ForwardIterator<const T> ConstIterator;

    public:
        // Ctors
        LinkedList();

        template<class FwdIt>
        LinkedList(FwdIt begin, FwdIt end);

        LinkedList(std::initializer_list<T>);

        LinkedList(const LinkedList<T> &);

        LinkedList(LinkedList<T> &&) noexcept;

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

        T& front() { return m_head->data; }

        const T& front() { return m_head->data; } const;

        T& back() { return m_head->data; }

        const T& back() { return m_head->data; } const


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