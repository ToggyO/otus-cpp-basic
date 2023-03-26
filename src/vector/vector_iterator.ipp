template <typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return Iterator(m_arr);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return Iterator(m_arr + m_size);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::begin() const
{
    return ConstIterator(m_arr);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::end() const
{
    return ConstIterator(m_arr + m_size);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::cbegin() const
{
    return ConstIterator(m_arr);
}

template <typename T>
typename Vector<T>::ConstIterator Vector<T>::cend() const
{
    return ConstIterator(m_arr + m_size);
}

#pragma once

struct NodeBase
{
    NodeBase* next;

    NodeBase() : next(nullptr) {}

protected:
    explicit NodeBase(NodeBase* next_) : next(next_) {}
};

// Вопрос: при указании компилятору использовать дефольный деструктор, стоит ли определять остальные члены по правилу пяти?
template <class T>
struct Node : public NodeBase
{
    explicit Node(T data_, Node<T>* next_ = nullptr)
            : data(std::move(data_)), NodeBase(next_) {}

    Node(const Node<T>& other)
    {
        data = other.data;
        next = other.next;
    }

    Node(Node<T>&& other) noexcept
    {
        move(std::forward<Node<T>>(other));
    }

    ~Node() = default;

    Node<T>& operator=(const Node<T>& other) noexcept
    {
        if (this != &other)
        {
            data = other.data;
            next = other.next;
        }

        return *this;
    }

    Node<T>& operator=(Node<T>&& other) noexcept
    {
        if (this != &other)
        {
            move(std::forward<Node<T>>(other));
        }

        return *this;
    }

    T data;

private:
    void move(Node<T>&& other)
    {
        data = std::move(other.data);
        next = other.next;

        other.data = {}; // TODO: check
        other.next = nullptr;
    }
};