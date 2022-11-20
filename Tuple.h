//
// Created by Rebek on 11/1/2022.
//

#ifndef PROJECT_1_TUPLE_H
#define PROJECT_1_TUPLE_H
#include <vector>
#include <iostream>

class Tuple {
private:
    std::vector<std::string> values;

public:
    Tuple() = default;
    ~Tuple() = default;

    void AddValue(std::string to_add);
    std::string GetValue(int index);
    int GetSize() {return values.size();}
    std::string ToString();

    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }
};


#endif //PROJECT_1_TUPLE_H
