#include "tree/div.hpp"

const static char* div_operator = "/";

Div::Div(const ASTNode *left_hand, const ASTNode *right_hand)
    : ASTNode(div_operator, left_hand, right_hand) {}