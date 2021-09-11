//
// Created by Chandler Rowe on 9/10/21.
//

#include "QueriesAutomaton.h"

void QueriesAutomaton::S0(const std::string &input) {
    if (input[index] == 'Q') {
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S1(const std::string &input) {
    if (input[index] == 'U') {
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S2(const std::string &input) {
    if (input[index] == 'E') {
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S3(const std::string &input) {
    if (input[index] == 'R') {
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S4(const std::string &input) {
    if (input[index] == 'I') {
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S5(const std::string &input) {
    if (input[index] == 'E') {
        index++;
        S6(input);
    }
}
void QueriesAutomaton::S6(const std::string &input) {
    if (input[index] == 'S') {
        index++;
        inputRead = 7;
    }
    else {
        Serr();
    }
}