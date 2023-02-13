#include "tree/add.hpp"

const static char *add_operator = "+";

Add::Add(ASTNode *left_hand, ASTNode *right_hand)
    : ASTNode(add_operator, left_hand, right_hand) {}

Add::~Add()
{
    std::cout << "~Add()" << std::endl;
}