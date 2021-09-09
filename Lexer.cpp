//
// Created by Chandler Rowe on 9/9/21.
//

#include "Lexer.h"

Lexer::Lexer(const int index) {
    text = "";
    this->index = index;
}

Lexer::Lexer(const std::string &fileName, const int index) {
    ReadFile(fileName);
    this->index = index;
}

void Lexer::ReadFile(const std::string &fileName) {
    std::string line;
    std::ifstream inf(fileName);
    if (!inf.is_open()) {
        text = fileName;
        return;
    }
    while (getline(inf, line)) {
        text += line + "\n";
    }
    inf.close();
}

std::string Lexer::ProcessText() {
    return text;
}

Lexer::~Lexer() = default;
