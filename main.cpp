#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: lexer <inputFile>" << std::endl;
        return 0;
    }

    Lexer* lexer = new Lexer();
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cout << "Could not open file." << std::endl;
        return 1;
    }
    std::ostringstream ss = std::ostringstream{};
    ss << inFile.rdbuf();
    std::string inp = ss.str();
    lexer->Run(inp);

    for (Token* token : *lexer->GetTokens()) {
        std::cout << token->ToString();
    }
    std::cout << "Total Tokens = " << lexer->GetTokens()->size();

    delete lexer;

    return 0;
}