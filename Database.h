//
// Created by Rebek on 11/1/2022.
//

#ifndef PROJECT_1_DATABASE_H
#define PROJECT_1_DATABASE_H
#include <map>
#include "Relation.h"

class Database {
private:
    std::map<std::string, Relation*> tables;
public:
    void AddTable(std::string id, Relation* relation);
    void SetTable(std::string name, Tuple tuple);
    std::string To_String();

    Relation* GetTable(std::string table);
};


#endif //PROJECT_1_DATABASE_H
