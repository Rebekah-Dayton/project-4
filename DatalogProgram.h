//
// Created by Rebek on 10/5/2022.
//

#ifndef PROJECT_1_DATALOGPROGRAM_H
#define PROJECT_1_DATALOGPROGRAM_H
#include <set>
#include <iterator>
#include "Predicate.h"
#include "Rule.h"

class DatalogProgram {
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Rule*> rules;
    std::vector<Predicate*> queries;
    std::set<std::string> domain;
    std::set<std::string>::iterator it;

public:
    DatalogProgram();
    ~DatalogProgram() = default;

    void AddScheme(Predicate* scheme);
    void AddFact(Predicate* fact);
    void AddRule(Rule* rule);
    void AddQuery(Predicate* query);
    void AddDomain(std::string fact);

    std::vector<Predicate*> GetSchemes();
    std::vector<Predicate*> GetFacts();
    std::vector<Predicate*> GetQueries();
    std::vector<Rule*> GetRules();


    std::string toString();
};


#endif //PROJECT_1_DATALOGPROGRAM_H
