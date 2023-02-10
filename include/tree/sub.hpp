#pragma once

#include "operation_node.hpp"

class Sub : public OperationNode
{
    public:
        Sub(const ASTNode *left_hand, const ASTNode *right_hand);
};