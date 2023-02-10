#pragma once

#include "operation_node.hpp"

class Add : public OperationNode
{
    public:
        Add(const ASTNode *left_hand, const ASTNode *right_hand);
};