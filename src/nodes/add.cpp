#include "tree/add.hpp"

const static char *add_operator = "+";

Add::Add(ASTNode *left_hand, ASTNode *right_hand)
    : OperationNode(add_operator, left_hand, right_hand) {}