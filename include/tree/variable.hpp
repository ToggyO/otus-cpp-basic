#pragma once

#include "astnode.hpp"

class Variable : public ASTNode
{
    public:
        Variable(std::string val);
            
        std::string value() const;

    private:
        std::string val_;
};