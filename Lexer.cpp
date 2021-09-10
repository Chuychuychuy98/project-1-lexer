#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for (Automaton* automaton : automata) {
        delete automaton;
    }
    for (Token* token : tokens) {
        delete token;
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);

        while (std::isspace(input.at(0))) {
            if (input.at(0) == '\n') lineNumber++;
            input.erase(input.begin());
        }

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for(Automaton* automaton : automata) {
            int inputRead = automaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }
        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                tokens.push_back(newToken);
        }
        // No automaton accepted input
        else {
            maxRead = 1;
            Token* newToken = new Token(TokenType::UNDEFINED, "", lineNumber);
            tokens.push_back(newToken);
        }
        input.erase(input.begin(), input.begin() + maxRead);
    }
    //add end of file token to all tokens
    tokens.push_back(new Token(TokenType::END_OF_FILE, "", lineNumber));
    for (Token* token : tokens) {
        std::cout << token->ToString();
    }
}
