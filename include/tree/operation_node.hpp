#pragma once

#include "astnode.hpp"

class OperationNode : public ASTNode
{
    public:
        OperationNode(const char *op, const ASTNode *left_hand, const ASTNode *right_hand);

        const ASTNode *left() const;
        const ASTNode *right() const;
};