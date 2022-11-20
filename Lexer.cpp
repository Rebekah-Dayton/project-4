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
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "BlockCommentAutomaton.h"
#include <cctype>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for (unsigned int i = 0; i < automata.size(); i++) {
        delete automata.at(i);
    }
    automata.clear();
    for (unsigned int i = 0; i < tokens.size(); i++) {
        delete tokens.at(i);
    }
    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new AddAutomaton());
    // TODO: Add the other needed automata here
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new BlockCommentAutomaton());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    // While there are more characters to tokenize
    char space = input[0];
    if(isspace(space)) {
        if(space == '\n') {
            lineNumber++;
        }
        input.erase(0,1);
    }
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);
        space = input[0];

        // TODO: you need to handle whitespace in between tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for (unsigned int i = 0; i < automata.size(); i++) {
            int inputRead = automata[i]->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
            }
        }
        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        else if (isspace(space)) {
            if(space == '\n') {
                lineNumber++;
            }
            input.erase(0,1);
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            maxRead = 1;
                Token* newToken = new Token(UNDEFINED, input.substr(0,maxRead), lineNumber);
                tokens.push_back(newToken);
        }
        // Update `input` by removing characters read to create Token
        input.erase(input.begin(), input.begin() + maxRead);
    }
    tokens.push_back(new Token(EOF_TOKEN, "", lineNumber));
    //PrintLexer();
}

void Lexer::PrintLexer() {
    for (unsigned int i = 0; i < tokens.size(); i++) {
        std::cout << tokens.at(i)->toString() << std::endl;
    }
    std::cout << "Total Tokens = " << tokens.size();
}
