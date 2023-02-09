#include "tree/operation_node.hpp"

OperationNode::OperationNode(const char *op, ASTNode *left_hand, ASTNode *right_hand)
    :ASTNode(op, left_hand, right_hand)
    , left_hand_node(left_hand), right_hand_node(right_hand) {}

ASTNode *OperationNode::left() const { return left_hand_node; }

ASTNode *OperationNode::right() const { return right_hand_node; }