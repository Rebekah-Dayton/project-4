//
// Created by Rebek on 9/20/2022.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string &input) {
    if (input[index] == '|') {
        Serr();
    }
    else {
        S2(input);
    }
}

void CommentAutomaton::S2(const std::string &input) {
    if (index == input.size()) {
        //reached end of comment
    }
    else if (input[index] != '\n') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        //reached end of comment
    }
}
