#pragma once

#include "operation_node.hpp"

class Sub : public OperationNode
{
    public:
        Sub(ASTNode *left_hand, ASTNode *right_hand);
};