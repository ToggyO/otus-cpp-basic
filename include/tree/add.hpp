#pragma once

#include "operation_node.hpp"

class Add : public OperationNode
{
    public:
        Add(const ASTNode *const left_hand, const ASTNode *const right_hand);
};