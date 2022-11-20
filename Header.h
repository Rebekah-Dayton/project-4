//
// Created by Rebek on 11/1/2022.
//

#ifndef PROJECT_1_HEADER_H
#define PROJECT_1_HEADER_H
#include <iostream>
#include <vector>

class Header {
private:
    std::vector<std::string> attributes;
public:
    Header(std::string value);

    Header();

    void AddAttribute(std::string to_add);
    std::string GetAttribute(int index);
    void SetAttribute(int index, std::string attribute);
    std::string ToString();
    int GetSize();
    int FindAttribute(std::string attribute);
};


#endif //PROJECT_1_HEADER_H
