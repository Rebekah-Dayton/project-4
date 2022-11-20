//
// Created by Rebek on 10/5/2022.
//

#ifndef PROJECT_1_PARAMETER_H
#define PROJECT_1_PARAMETER_H
#include <iostream>

class Parameter {
private:
    std::string p;
public:
    explicit Parameter(std::string parameter) {p = parameter;}
    ~Parameter() = default;

    std::string GetParameter() {return p;}
};


#endif //PROJECT_1_PARAMETER_H
