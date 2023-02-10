#pragma once

#include "astnode.hpp"

class Variable : public ASTNode
{
    public:
        explicit Variable(const std::string& val);
            
        std::string value() const;

    private:
        std::string val_;
};