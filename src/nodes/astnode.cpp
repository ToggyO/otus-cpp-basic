#include "tree/astnode.hpp"

ASTNode::ASTNode(const std::string &repr)
    : repr_val(repr)
    , lhs_p{nullptr}
    , rhs_p{nullptr} {}

ASTNode::ASTNode(const std::string &repr, const ASTNode *lhs, const ASTNode *rhs)
    : repr_val(repr)
    , lhs_p{lhs}
    , rhs_p{rhs} {}

ASTNode::~ASTNode() {
    delete lhs_p;
    delete rhs_p;
}

void ASTNode::print(std::ostream &out) const { inner_print(out, 0); }

void ASTNode::inner_print(std::ostream &out, size_t indent) const {
    if (lhs_p) {
        lhs_p->inner_print(out, indent + 1);
    }
    for (size_t i = 0; i < indent; ++i) {
        out << "    ";
    }
    out << repr_val << '\n';
    if (rhs_p) {
        rhs_p->inner_print(out, indent + 1);
    }
}
