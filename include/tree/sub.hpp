#pragma once

#include "astnode.hpp"

class Sub : public ASTNode
{
    public:
        Sub(ASTNode *left_hand, ASTNode *right_hand);
};