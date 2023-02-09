// OTUS C++ Basic course homework skeleton.
// Lexer using example

#include <iostream>

#include "lexer.hpp"
#include "parser.hpp"
#include "tree/astnode.hpp"

int main() {
    // TODO
    // Implement the next classes:
    // Add
    // Sub
    // Mul
    // Div
    // Variable

    // Without implementation that classes this application works only with numbers

    Lexer lexer(std::cin);
    Parser parser(lexer);

    ASTNode *ast = parser.parse();
    if (!ast) {
        return 1;
    }

    ast->print(std::cout);
    delete ast;

    return 0;
}
