#pragma once

#include "operation_node.hpp"


class Mul : public OperationNode
{
    public:
        Mul(ASTNode *left_hand, ASTNode *right_hand);
};