#pragma once

#include <initializer_list>
#include <numeric>

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
            m_traverse([](const Node<T>* node) {
                delete node;
            });

            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;
        }

        // Methods
        void insert_after(ConstIterator, const T&);

        void insert_after(ConstIterator, const T&&);

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

        void erase(Iterator);

        void erase(ConstIterator);

        void erase(Iterator, Iterator);

        void erase(ConstIterator, ConstIterator);

        void clear() { delete m_head; }

        // Accessors
        size_t size() const { return m_size; }

        bool empty() const { return m_size == 0; }

        reference front() { return m_head->data; }

        const_reference front() const { return m_head->data; }

        reference back() { return m_tail->data; }

        const_reference back() const { return m_tail->data; }

        // Iterators
        Iterator begin() { return Iterator(m_head); };
    
        Iterator end() { return Iterator(nullptr); };

        ConstIterator begin() const { return ConstIterator(m_head); };
    
        ConstIterator end() const { return ConstIterator(nullptr); };
    
        ConstIterator cbegin() const { return ConstIterator(m_head); };
    
        ConstIterator cend() const { return ConstIterator(nullptr); };

        // Operators
        ForwardList<T>& operator=(const ForwardList<T>&);

        ForwardList<T>& operator=(ForwardList<T>&&) noexcept;

    private:
        Node<T>* m_head;
        Node<T>* m_tail;
        size_t m_size;

        void m_move(ForwardList<T>&&);
        void m_traverse(void(*action)(const Node<T>*));
        void m_insert(Node<T>* pivot_node, Node<T>* new_node);
};

#include "forward_list_ctors.ipp"
#include "forward_list_methods.ipp"
#include "forward_list_operators.ipp"
#include "forward_list_private_methods.ipp"