//
// Created by Chandler Rowe on 9/9/21.
//
#include "Lexer.h"
#include <iostream>

int main() {

    Lexer lexer("testing.txt");
    std::cout << lexer.ProcessText();

    return 0;
}
