#pragma once

#include "astnode.hpp"

class OperationNode : public ASTNode
{
    public:
        OperationNode(const char *op, ASTNode *left_hand, ASTNode *right_hand);

        ASTNode *left() const;
        ASTNode *right() const;

    protected:
        ASTNode *left_hand_node;
        ASTNode *right_hand_node;
};