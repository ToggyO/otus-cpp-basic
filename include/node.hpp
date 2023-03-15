#pragma once

template <class T>
struct Node
{
    Node(T data_, Node<T>* next_ = nullptr)
        : data(data_), next(next_) {}

    T data;
    Node<T>* next; 
};