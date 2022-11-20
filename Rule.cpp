//
// Created by Rebek on 10/5/2022.
//

#include "Rule.h"

Rule::Rule(Predicate* headPredicate) {
   head = headPredicate;
}

void Rule::SetHead(std::string name) {
    head->SetId(name);
}

void Rule::AddBodyPredicate(Predicate* body) {
    rules.push_back(body);
}

std::string Rule::to_String() {
    std::string rule = head->toString() + " :- ";
    for (unsigned int i = 0; i < rules.size(); i++) {
        rule += rules.at(i)->toString();
        if (i != rules.size() - 1) {
            rule += ",";
        }
    }
    return rule + ".";
}


