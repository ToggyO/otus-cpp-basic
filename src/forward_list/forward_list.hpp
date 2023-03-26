#pragma once

#include <initializer_list>
#include <numeric>

#include "node.hpp"
//#include "../iterator/separated/forward_iterator.hpp"

template <class T>
class ForwardList
{
    struct ForwardIterator;
    struct ConstForwardIterator;

    public:
        typedef T value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef ForwardIterator Iterator;
        typedef ConstForwardIterator ConstIterator;

        // Ctors
        ForwardList();

        template<class FwdIt, typename = std::_RequireInputIter<FwdIt>>
        ForwardList(FwdIt begin, FwdIt end);

        ForwardList(std::initializer_list<T>);

        ForwardList(const ForwardList<T>&);

        ForwardList(ForwardList<T>&&) noexcept;

        ~ForwardList()
        {
            traverse([](const Node<T>* node) {
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

        void move(ForwardList<T>&& other);
        void traverse(void(*action)(const Node<T>*));
};

#include "forward_list_ctors.ipp"
#include "forward_list_methods.ipp"
#include "forward_list_iterator.ipp"
#include "forward_list_const_iterator.ipp"
#include "forward_list_operators.ipp"
#include "forward_list_private_methods.ipp"