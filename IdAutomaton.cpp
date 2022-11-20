//
// Created by Rebek on 9/20/2022.
//

#include "IdAutomaton.h"
#include <cctype>

void IdAutomaton::S0(const std::string &input) {
    if (std::isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string &input) {
    if (std::isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        //do nothing
    }
}