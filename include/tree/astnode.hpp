// OTUS C++ basic course homework.
// ASTNode

#pragma once

#include <cctype>
#include <iostream>
#include <string>

class ASTNode {
  public:
    explicit ASTNode(const std::string &repr);

    ASTNode(const std::string &repr, const ASTNode *lhs, const ASTNode *rhs);

    ASTNode(const ASTNode &other) = delete;

    ASTNode &operator=(const ASTNode &other) = delete;

    ~ASTNode();

    std::string repr() const { return repr_val; }

    void print(std::ostream &out) const;

  protected:
    const std::string repr_val;
    const ASTNode *lhs_p;
    const ASTNode *rhs_p;

  private:
    void inner_print(std::ostream &out, size_t indent) const;
};
