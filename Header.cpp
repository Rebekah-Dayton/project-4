//
// Created by Rebek on 11/1/2022.
//

#include "Header.h"

void Header::AddAttribute(std::string to_add) {
    attributes.push_back(to_add);
}

std::string Header::GetAttribute(int index) {
    return attributes.at(index);
}

int Header::GetSize() {
    return attributes.size();
}

Header::Header(std::string value) {
    attributes.push_back(value);
}

std::string Header::ToString() {
    std::string header = "(";
    for (unsigned int i = 0; i < attributes.size(); i++) {
        header += attributes.at(i);
        if (i != attributes.size() - 1) {
            header += ", ";
        }
    }
    header += ")\n";
    return header;
}

int Header::FindAttribute(std::string attribute) {
    for (unsigned int i = 0; i < attributes.size(); i++) {
        if (attributes.at(i) == attribute) {
            return i;
        }
    }
    return -1;
}

void Header::SetAttribute(int index, std::string attribute) {
    attributes.at(index) = attribute;
}

Header::Header() = default;
