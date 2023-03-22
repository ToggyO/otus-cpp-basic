#pragma once

template <class T>
struct Node
{
    explicit Node(const T& data_, Node<T>* next_ = nullptr)
        : data(std::move(data_)), next(next_) {}

    Node(const Node<T>& other)
    {
        data = other.data;
        next = other.next;
    }

    Node(Node<T>&& other)
    {
        data = std::move(other.data);
        next = other.next;

        other.data = {}; // TODO: check
        other.next = nullptr;
    }

    ~Node() { delete next; }

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
            data = std::move(other.data);
            next = other.next;

            other.data = {}; // TODO: check
            other.next = nullptr;
        }

        return *this;
    }

    T data;
    Node<T>* next;
};