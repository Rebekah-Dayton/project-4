//
// Created by Rebek on 11/1/2022.
//

#include "Database.h"

void Database::AddTable(std::string id, Relation *relation) {
    tables.insert(std::pair<std::string, Relation*>(id, relation));
}

std::string Database::To_String() {
    std::string string = "";
    for (const auto &entry: tables) {
        string += "table name: " + entry.first + "\n";
        string += "Table Relation: " + entry.second->GetName() + "\n";
        string += entry.second->To_String() + "\n";
    }
    return string;
}

void Database::SetTable(std::string name, Tuple tuple) {
    for (auto it=tables.begin(); it!=tables.end(); ++it) {
        if (it->second->GetName() == name) {
            it->second->AddTuple(tuple);
        }
    }
}

Relation *Database::GetTable(std::string table) {
    for (auto it=tables.begin(); it!=tables.end(); ++it) {
        if (it->first == table) {
            return it->second;
        }
    }
    return nullptr;
}


