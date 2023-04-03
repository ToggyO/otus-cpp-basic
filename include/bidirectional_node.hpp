#pragma once

#include "node.hpp"

template <class T>
struct BidirectionalNode : public Node<T>
{
    BidirectionalNode(T data_, Node<T>* next_ = nullptr)
        : Node<T>(data_, next_) {}

    BidirectionalNode<T>* next;
    BidirectionalNode<T>* prev;
};
