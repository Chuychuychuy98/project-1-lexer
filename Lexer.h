//
// Created by Chandler Rowe on 9/9/21.
//

#ifndef PROJECT_1_LEXER_LEXER_H
#define PROJECT_1_LEXER_LEXER_H

#include <string>
#include <fstream>

class Lexer {
public:
    Lexer(int index = 0);
    Lexer(const std::string &fileName, int index = 0);
    ~Lexer();
    std::string ProcessText();
    void ReadFile(const std::string &fileName);
private:
    std::string text;
    int index;
};


#endif //PROJECT_1_LEXER_LEXER_H
