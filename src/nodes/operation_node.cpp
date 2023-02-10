#include "tree/operation_node.hpp"

OperationNode::OperationNode(const char *op, const ASTNode *left_hand, const ASTNode *right_hand)
    : ASTNode(op, left_hand, right_hand) {}

const ASTNode *OperationNode::left() const { return lhs_p; }

const ASTNode *OperationNode::right() const { return rhs_p; }