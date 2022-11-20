//
// Created by Rebek on 9/21/2022.
//

#include "BlockCommentAutomaton.h"

void BlockCommentAutomaton::S0(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S1(const std::string &input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S2(const std::string &input) {
    if (index == input.size()) {
        type = UNDEFINED;
    }
    else if (input[index] != '|') {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S3(input);
    }
}

void BlockCommentAutomaton::S3(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
    }
    else {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}

