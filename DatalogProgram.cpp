//
// Created by Rebek on 10/5/2022.
//

#include "DatalogProgram.h"

DatalogProgram::DatalogProgram() {

}

void DatalogProgram::AddScheme(Predicate *scheme) {
    schemes.push_back(scheme);
}

void DatalogProgram::AddFact(Predicate *fact) {
    facts.push_back(fact);
}

void DatalogProgram::AddRule(Rule *rule) {
    rules.push_back(rule);
}

void DatalogProgram::AddQuery(Predicate *query) {
    queries.push_back(query);
}

void DatalogProgram::AddDomain(std::string fact) {
    domain.insert(fact);
}

std::string DatalogProgram::toString() {
    std::string datalogProgram = "Schemes(" + std::to_string(schemes.size()) + "):\n";
    for (unsigned int i = 0; i < schemes.size(); i++) {
        datalogProgram += "  " + schemes.at(i)->toString() + "\n";
    }

    datalogProgram += "Facts(" + std::to_string(facts.size()) + "):\n";
    for (unsigned int i = 0; i < facts.size(); i++) {
        datalogProgram += "  " + facts.at(i)->toString() + "." + "\n";
    }

    datalogProgram += "Rules(" + std::to_string(rules.size()) + "):\n";
    for (unsigned int i = 0; i < rules.size(); i++) {
        datalogProgram += "  " + rules.at(i)->to_String() + "\n";
    }

    datalogProgram += "Queries(" + std::to_string(queries.size()) + "):\n";
    for (unsigned int i = 0; i < queries.size(); i++) {
        datalogProgram += "  " + queries.at(i)->toString() + "?" + "\n";
    }

    datalogProgram += "Domain(" + std::to_string(domain.size()) + "):\n";
    for (it = domain.begin(); it != domain.end(); it++) {
        datalogProgram += "  " + *it + "\n";
    }
    datalogProgram.pop_back();

    return datalogProgram;
}

std::vector<Predicate *> DatalogProgram::GetSchemes() {
    return schemes;
}

std::vector<Predicate *> DatalogProgram::GetFacts() {
    return facts;
}

std::vector<Predicate *> DatalogProgram::GetQueries() {
    return queries;
}

std::vector<Rule *> DatalogProgram::GetRules() {
    return rules;
}



