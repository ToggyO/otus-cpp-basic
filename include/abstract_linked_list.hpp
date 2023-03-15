#pragma once

#include "node.hpp"

template <class T, class TNode>
class AbstractLinkedList
{
    public:
        // Methods
        void clear() = 0;

    protected:
        TNode* head_;
        TNode* tail_;
        size_t count_;
};