#include "tree/mul.hpp"

const static char* mul_operator = "*";

Mul::Mul(ASTNode *left_hand, ASTNode *right_hand)
    : ASTNode(mul_operator, left_hand, right_hand) {}