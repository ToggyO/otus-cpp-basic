#pragma once

#include "operation_node.hpp"

class Div : public OperationNode
{
    public:
        Div(const ASTNode *left_hand, const ASTNode *right_hand);
};