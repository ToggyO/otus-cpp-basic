#pragma once

template <class T>
struct Node
{
    explicit Node(T data_, Node<T>* next_ = nullptr)
        : data(data_), next(next_) {}

    ~Node() { delete next; }

    T data;
    Node<T>* next;
};