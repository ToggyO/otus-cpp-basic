#include "tree/sub.hpp"

const static char* sub_operator = "-";

Sub::Sub(const ASTNode *left_hand, const ASTNode *right_hand)
    : ASTNode(sub_operator, left_hand, right_hand) {}