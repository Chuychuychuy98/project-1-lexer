#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    // TODO: add the other types of tokens
    UNDEFINED
};

class Token
{
private:
    TokenType type;
    std::string description;
    int line;

public:
    Token(TokenType type, std::string description, int line);
    std::string ToString() {
        return "(type, " + description + ", " + std::to_string(line) + ")\n";
    }

    // TODO: add other needed methods
};

#endif // TOKEN_H

