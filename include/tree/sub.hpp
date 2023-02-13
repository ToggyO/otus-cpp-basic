#pragma once

#include "astnode.hpp"

class Sub : public ASTNode
{
    public:
        Sub(const ASTNode *left_hand, const ASTNode *right_hand);
};