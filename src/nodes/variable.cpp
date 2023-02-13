#include "tree/variable.hpp"

Variable::Variable(const std::string& val)
    : ASTNode(val)
    , val_(val) {}

std::string Variable::value() const { return val_; }