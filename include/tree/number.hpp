#pragma once

#include <string>

#include "astnode.hpp"

class Number : public ASTNode {
  public:
    Number(int val);

    int value() const;

  private:
    int val_;
};
