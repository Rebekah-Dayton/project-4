//
// Created by Rebek on 10/5/2022.
//

#include "Predicate.h"

Predicate::Predicate(std::string name) {
    id = name;
}

void Predicate::AddParameter(std::string newParameter) {
    Parameter* parameter = new Parameter(newParameter);
    parameters.push_back(parameter);
}

std::string Predicate::toString() {
    std::string predicate = id + "(";
    for (unsigned int i = 0; i < parameters.size(); i++) {
        predicate += parameters.at(i)->GetParameter();
        if (i != parameters.size() - 1) {
            predicate += + ",";
        }
    }
    return predicate + ")";
}


Predicate::Predicate() = default;
