#pragma once

#include "astnode.hpp"

class Mul : public ASTNode
{
    public:
        Mul(ASTNode *left_hand, ASTNode *right_hand);
};