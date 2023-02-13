#pragma once

#include "astnode.hpp"

class Add : public ASTNode
{
    public:
        Add(const ASTNode *left_hand, const ASTNode *right_hand);
};