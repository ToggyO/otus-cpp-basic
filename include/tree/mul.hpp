#pragma once

#include "operation_node.hpp"


class Mul : public OperationNode
{
    public:
        Mul(const ASTNode *left_hand, const ASTNode *right_hand);
};