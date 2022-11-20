//
// Created by Rebek on 9/20/2022.
//

#include "QMarkAutomaton.h"

void QMarkAutomaton::S0(const std::string &input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
