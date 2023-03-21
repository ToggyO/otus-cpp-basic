#pragma once

template <class T>
struct Node
{
    explicit Node(T data_, Node<T>* next_ = nullptr)
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

    Node<T>& operator=(const Node<T>& other)
    {
        if (*this != other)
        {
            data = other.data;
            next = other.next;
        }

    }

    Node<T>& operator=(Node<T>&& other)
    {
        if (*this != other)
        {
            data = std::move(other.data);
            next = other.next;

            other.data = {}; // TODO: check
            other.next = nullptr;
        }
    }

    T data;
    Node<T>* next;
};