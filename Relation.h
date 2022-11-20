//
// Created by Rebek on 11/1/2022.
//

#ifndef PROJECT_1_RELATION_H
#define PROJECT_1_RELATION_H
#include "Tuple.h"
#include "Header.h"
#include <set>

class Relation {
private:
    std::string name;
    Header attributes;
    std::set<Tuple> tuples;
    std::vector<int> matching;
    bool addedTuple = false;
public:
    Relation();
    Relation(std::string name, Header header);
    ~Relation() = default;

    void SetHeader(Header header) {attributes = header;}
    void SetName(std::string id) {name = id;}
    void AddTuple(Tuple to_add);

    unsigned int GetTupleSize() {return tuples.size();}
    std::string GetName() {return name;}
    std::set<Tuple> GetTuples() {return tuples;}
    Header GetHeader() {return attributes;}
    int GetHeaderSize() {return attributes.GetSize();}
    bool AddedTuple() {return addedTuple;}
    std::string To_String();

    Relation* Select(int index, std::string selector);
    Relation* SelectTwo(int index1, int index2);
    Relation* Project(std::vector<unsigned int> indices);
    Relation* Rename(int index, std::string newAttribute);
    Relation* NaturalJoin(Relation* to_join);
    void Union(Relation* relation);

    Tuple JoinTuples(Tuple tuple1, Tuple tuple2);
    bool CanJoin(Tuple tuple1, Tuple tuple2);
};


#endif //PROJECT_1_RELATION_H
