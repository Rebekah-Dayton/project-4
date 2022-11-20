//
// Created by Rebek on 10/5/2022.
//

#ifndef PROJECT_1_RULE_H
#define PROJECT_1_RULE_H
#include <iostream>
#include <vector>
#include "Predicate.h"

class Rule {
private:
    Predicate* head;
    std::vector<Predicate*> rules;

public:
    Rule(Predicate* headPredicate);

    void SetHead(std::string name);
    void AddBodyPredicate(Predicate* body);
    std::vector<Predicate*> GetRuleBody() {return rules;}
    Predicate* GetHead() {return head;}
    std::string to_String();
};


#endif //PROJECT_1_RULE_H
