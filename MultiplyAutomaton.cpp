//
// Created by Rebek on 9/20/2022.
//

#include "MultiplyAutomaton.h"

void MultiplyAutomaton::S0(const std::string &input) {
    if (input[index] == '*') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
