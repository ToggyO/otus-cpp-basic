#pragma once

#include "astnode.hpp"

class Div : public ASTNode
{
    public:
        Div(const ASTNode *left_hand, const ASTNode *right_hand);
};