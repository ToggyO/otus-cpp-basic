#pragma once

#include "astnode.hpp"

class Add : public ASTNode
{
    public:
        Add(ASTNode *left_hand, ASTNode *right_hand);
        ~Add();
};