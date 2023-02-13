#pragma once

#include "astnode.hpp"

class Mul : public ASTNode
{
    public:
        Mul(const ASTNode *left_hand, const ASTNode *right_hand);
};