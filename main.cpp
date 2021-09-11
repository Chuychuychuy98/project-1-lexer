#include "Lexer.h"

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();
    std::string inp = ":-\n:\n,\n?\n.\n(\n)\n*\n+$";
    lexer->Run(inp);

    // TODO

    delete lexer;

    return 0;
}