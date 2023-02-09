#include "tree/div.hpp"

const static char* div_operator = "/";

Div::Div(ASTNode *left_hand, ASTNode *right_hand)
    : OperationNode(div_operator, left_hand, right_hand) {}