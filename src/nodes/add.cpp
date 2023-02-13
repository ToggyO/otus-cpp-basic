#include "tree/add.hpp"

const static char *add_operator = "+";

Add::Add(const ASTNode *left_hand, const ASTNode *right_hand)
    : ASTNode(add_operator, left_hand, right_hand) {
}