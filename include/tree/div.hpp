#pragma once

#include "operation_node.hpp"

class Div : public OperationNode
{
    public:
        Div(ASTNode *left_hand, ASTNode *right_hand);
};