//
// Created by Rebek on 11/1/2022.
//

#include "Tuple.h"

void Tuple::AddValue(std::string to_add) {
    values.push_back(to_add);
}

std::string Tuple::GetValue(int index) {
    return values.at(index);
}


std::string Tuple::ToString() {
    std::string tuple = "(";
    for (unsigned int i = 0; i < values.size(); i++) {
        tuple += values.at(i);
        if (i != values.size() - 1) {
            tuple += ", ";
        }
    }
    tuple += ")\n";
    return tuple;
}


