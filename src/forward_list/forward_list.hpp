#pragma once

#include <initializer_list>
#include <numeric>
#include <cstddef>

#include "node.hpp"
#include "./iterator/forward_list_iterator.hpp"
#include "./iterator/forward_list_const_iterator.hpp"

template <class T>
class ForwardList
{
    public:
        typedef T value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef ForwardIterator<T> Iterator;
        typedef ConstForwardIterator<T> ConstIterator;

        // Ctors
        ForwardList();

        template<class FwdIt, typename = std::_RequireInputIter<FwdIt>>
        ForwardList(FwdIt begin, FwdIt end);

        ForwardList(std::initializer_list<T>);

        ForwardList(const ForwardList<T>&);

        ForwardList(ForwardList<T>&&) noexcept;

        ~ForwardList()
        {
            clear();
            delete m_before_head;
        }

        // Methods
        void insert_after(Iterator, const T&);

        void insert_after(Iterator, T&&);

        void insert_after(ConstIterator, const T&);

        void insert_after(ConstIterator, T&&);

        template<class... Args>
        void emplace_after(Iterator, Args&&...);

        template<class... Args>
        void emplace_after(ConstIterator, Args&&...);

        void push_front(const T&);

        void push_front(T&&);

        void push_back(const T&);

        void push_back(T&&);

        template<class... Args>
        void emplace_front(Args&&...);

        template<class... Args>
        void emplace_back(Args&&...);

        void pop_front();

        void resize(size_t);

        void erase_after(Iterator);

        void erase_after(Iterator, Iterator);

        void erase_after(ConstIterator);

        void erase_after(ConstIterator, ConstIterator);

        void clear();

        // Accessors
        size_t size() const { return m_size; }

        bool empty() const { return m_size == 0; }

        reference front() { return m_head->data; }

        const_reference front() const { return m_head->data; }

        reference back() { return m_tail->data; }

        const_reference back() const { return m_tail->data; }

        // Iterators
        Iterator before_begin() { return Iterator(m_before_head); }

        ConstIterator before_begin() const { return ConstIterator(m_before_head); }

        ConstIterator cbefore_begin() const { return ConstIterator(m_before_head); }

        Iterator begin() { return Iterator(m_head); };
    
        Iterator end() { return Iterator(nullptr); };

        ConstIterator begin() const { return ConstIterator(m_head); };
    
        ConstIterator end() const { return ConstIterator(nullptr); };
    
        ConstIterator cbegin() { return ConstIterator(m_head); };
    
        ConstIterator cend() const { return ConstIterator(nullptr); };

        // Operators
        ForwardList<T>& operator=(const ForwardList<T>&);

        ForwardList<T>& operator=(ForwardList<T>&&) noexcept;

    private:
        Node<T>* m_before_head = new Node<T>(T());
        Node<T>* m_head;
        Node<T>* m_tail;
        size_t m_size;

        void m_move(ForwardList<T>&&);

        template <class Action>
        void m_traverse(Iterator, Iterator, Action action);
 
        void m_insert(Node<T>* pivot_node, T obj);

        void m_erase_after(Iterator, Iterator);

        void m_clear_internal();
};

#include "forward_list_ctors.ipp"
#include "forward_list_methods.ipp"
#include "forward_list_operators.ipp"
#include "forward_list_private_methods.ipp"