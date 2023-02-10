#include "tree/mul.hpp"

const static char* mul_operator = "*";

Mul::Mul(const ASTNode *left_hand, const ASTNode *right_hand)
    : OperationNode(mul_operator, left_hand, right_hand) {}