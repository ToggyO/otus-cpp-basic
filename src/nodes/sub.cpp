#include "tree/sub.hpp"

const static char* sub_operator = "-";

Sub::Sub(ASTNode *left_hand, ASTNode *right_hand)
    : ASTNode(sub_operator, left_hand, right_hand) {}