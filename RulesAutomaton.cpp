//
// Created by Chandler Rowe on 9/10/21.
//

#include "RulesAutomaton.h"

//
// Created by Chandler Rowe on 9/10/21.
//

#include "FactsAutomaton.h"

void FactsAutomaton::S0(const std::string &input) {
    if (input[index] == 'R') {
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S1(const std::string &input) {
    if (input[index] == 'U') {
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S2(const std::string &input) {
    if (input[index] == 'L') {
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S3(const std::string &input) {
    if (input[index] == 'E') {
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S4(const std::string &input) {
    if (input[index] == 'S') {
        index++;
        inputRead = 5;
    } else {
        Serr();
    }
}