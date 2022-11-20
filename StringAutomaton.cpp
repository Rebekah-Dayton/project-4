//
// Created by Rebek on 9/20/2022.
//

#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string &input) {
    if (index == input.size()) {
        type = UNDEFINED;
    }
    else if (input[index] != '\'') {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void StringAutomaton::S2(const std::string &input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        //do nothing
    }
}
