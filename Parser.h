//
// Created by Rebek on 10/4/2022.
//

#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"

class Parser {
private:
    DatalogProgram program;
    std::vector<Token> tokens;
    unsigned int currentToken;

    void ParseDatalogProgram();

    void ParseSchemeList();
    void ParseFactList();
    void ParseRuleList();
    void ParseQueryList();

    void ParseScheme();
    void ParseFact();
    void ParseRule();
    void ParseQuery();

    Predicate* ParseHeadPredicate();
    void ParsePredicate(Rule* rule);
    Predicate* ParsePredicate();

    void ParsePredicateList(Rule* rule);
    void ParseParameterList(Predicate* predicate);
    void ParseStringList(Predicate* factPredicate);
    void ParseIdList(Predicate* predicate);
    void ParseParameter(Predicate* predicate);

    void Match(TokenType toMatch);

public:
    explicit Parser(std::vector<Token*> tokenList);
    ~Parser()= default;

    void Parse();
    DatalogProgram GetDatalogProgram() {return program;}
};


#endif //PROJECT_1_PARSER_H
