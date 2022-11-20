//
// Created by Rebek on 10/5/2022.
//

#ifndef PROJECT_1_PREDICATE_H
#define PROJECT_1_PREDICATE_H
#include <iostream>
#include <vector>
#include "Parameter.h"
#include "Token.h"

class Predicate {
private:
    std::string id;
    std::vector<Parameter*> parameters;

public:
    explicit Predicate(std::string name);
    Predicate();
    ~Predicate() = default;

    void SetId(std::string name) {id = name;}
    void AddParameter(std::string newParameter);

    std::string GetId() {return id;}
    std::string GetParam(int index) {return parameters.at(index)->GetParameter();}
    std::string toString();
    int GetSize() {return parameters.size();}
};


#endif //PROJECT_1_PREDICATE_H
