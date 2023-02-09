#include <iostream>

#include "parser.hpp"

#include "tree/add.hpp"
#include "tree/div.hpp"
#include "tree/mul.hpp"
#include "tree/number.hpp"
#include "tree/sub.hpp"
#include "tree/variable.hpp"

using Token = Lexer::Token;

void throwInvalidCharError(Lexer &lexer, Token token);

ASTNode *Parser::parse()
{
    try
    {
        return expr();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid expression: " << e.what() << std::endl;
        return nullptr;
    }   
}

void Parser::next_token() { tok_ = lexer_.next_token(); }

ASTNode *Parser::expr() {
    // parse addition and subsctruction
    ASTNode *root = term();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '+':
                // Implement Add class and uncomment this line
                root = new Add(root, term());
                break;
            case '-':
                // Implement Sub class and uncomment this line
                root = new Sub(root, term());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::term() {
    // parse multiplication and division
    ASTNode *root = prim();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '*':
            {
                // Implement Mul class and uncomment this line
                root = new Mul(root, prim());
                break;
            }
            case '/':
            {
                // Implement Div class and uncomment this line
                root = new Div(root, prim());
                break;
            }
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::prim() {
    // parse numbers and names
    ASTNode *node = nullptr;
    next_token();
    switch (tok_) {
    case Token::Number:
        node = new Number(lexer_.get_number());
        break;
    case Token::Name:
        // Implement Variable class and uncomment this line
        node = new Variable(lexer_.get_name());
        break;
    case Token::Lbrace:
        node = expr();
        if (tok_ != Token::Rbrace)
        {
            throw std::runtime_error("')' is required after '('");
        }
        break;
    default:
        throwInvalidCharError(lexer_, tok_);
    }
    next_token();
    return node;
}

void throwInvalidCharError(Lexer &lexer, Token token)
{
    std::string invalid_token;
    switch (token)
    {
        case Token::Operator:
            invalid_token = lexer.get_operator();
            break;
        case Token::Number:
            invalid_token = lexer.get_number();
            break;
        case Token::Name:
            invalid_token = lexer.get_name();
            break;
        default:
            invalid_token = "unknown";
    }
    throw std::runtime_error("invalid character near '" +  invalid_token + "'");
}