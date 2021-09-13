//
// Created by Chandler Rowe on 9/13/21.
//

#include "StringAutomaton.h"
#include <iostream>

void StringAutomaton::S0(const std::string &input) {
    if (input[index] == '\'') {
        index++;
        inputRead++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string &input) {
    if (input.size() < index) {
        Serr();
    }
    else if (input[index] == '\'') {
        index++;
        inputRead++;
        S2(input);
    }
    else {
        index++;
        inputRead++;
        S1(input);
    }
}

void StringAutomaton::S2(const std::string &input) {
    if (input.size() < index) {
       index++;
       inputRead++;
    }
    else if (input[index] == '\'' && inputRead > 1) {
        index++;
        inputRead++;
        S1(input);
    }
}