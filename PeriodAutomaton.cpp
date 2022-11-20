//
// Created by Rebek on 9/20/2022.
//

#include "PeriodAutomaton.h"

void PeriodAutomaton::S0(const std::string &input) {
    if (input[index] == '.') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
