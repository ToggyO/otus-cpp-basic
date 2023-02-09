#pragma once

#include "operation_node.hpp"

class Add : public OperationNode
{
    public:
        Add(ASTNode *left_hand, ASTNode *right_hand);
};