#pragma once

#include "astnode.hpp"

class Div : public ASTNode
{
    public:
        Div(ASTNode *left_hand, ASTNode *right_hand);
};