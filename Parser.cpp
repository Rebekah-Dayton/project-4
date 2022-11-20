//
// Created by Rebek on 10/4/2022.
//

#include "Parser.h"

Parser::Parser(std::vector<Token*> tokenList) {
    currentToken = 0;
    for (unsigned int i = 0; i < tokenList.size(); i++) {
        if (tokenList.at(i)->GetType() != COMMENT) {
            tokens.push_back(*tokenList.at(i));
        }
    }
}

void Parser::Parse() {
    try {
       /* Check each token in the vector, if the
        * order of the tokens matches the grammar,
        * succeed, otherwise throw the token out
        * of place */
        ParseDatalogProgram();
        //std::cout << "Success!" << std::endl;
        //std::cout << program.toString();
    } catch (std::invalid_argument& error) {
        //print out error token
        std::cout << error.what();
    }
}

void Parser::ParseDatalogProgram() {
//SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    Match(SCHEMES);
    Match(COLON);
    ParseScheme();
    ParseSchemeList();
    Match(FACTS);
    Match(COLON);
    ParseFactList();
    Match(RULES);
    Match(COLON);
    ParseRuleList();
    Match(QUERIES);
    Match(COLON);
    ParseQuery();
    ParseQueryList();
    Match(EOF_TOKEN);
}

void Parser::ParseSchemeList() {
//schemeList	->	scheme schemeList | lambda
    if (tokens.at(currentToken).GetType() == ID) {
        ParseScheme();
        ParseSchemeList();
    }
}

void Parser::ParseFactList() {
//factList	->	fact factList | lambda
    if (tokens.at(currentToken).GetType() == ID) {
        ParseFact();
        ParseFactList();
    }
}

void Parser::ParseRuleList() {
//ruleList	->	rule ruleList | lambda
    if (tokens.at(currentToken).GetType() == ID) {
        ParseRule();
        ParseRuleList();
    }
}

void Parser::ParseQueryList() {
//queryList	->	query queryList | lambda
    if (tokens.at(currentToken).GetType() == ID) {
        ParseQuery();
        ParseQueryList();
    }
}

void Parser::ParseScheme() {
//scheme ->	ID LEFT_PAREN ID idList RIGHT_PAREN
    Match(ID);
    Predicate* schemePredicate = new Predicate(tokens.at(currentToken - 1).GetValue());
    Match(LEFT_PAREN);
    Match(ID);
    schemePredicate->AddParameter(tokens.at(currentToken - 1).GetValue());
    ParseIdList(schemePredicate);
    Match(RIGHT_PAREN);
    program.AddScheme(schemePredicate);
}

void Parser::ParseFact() {
//fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    Match(ID);
    Predicate* factPredicate = new Predicate(tokens.at(currentToken - 1).GetValue());
    Match(LEFT_PAREN);
    Match(STRING);
    factPredicate->AddParameter(tokens.at(currentToken - 1).GetValue());
    program.AddDomain(tokens.at(currentToken - 1).GetValue());
    ParseStringList(factPredicate);
    Match(RIGHT_PAREN);
    Match(PERIOD);
    program.AddFact(factPredicate);
}

void Parser::ParseRule() {
//rule -> headPredicate COLON_DASH predicate predicateList PERIOD
    Rule* rule = new Rule(ParseHeadPredicate());
    Match(COLON_DASH);
    ParsePredicate(rule);
    ParsePredicateList(rule);
    Match(PERIOD);
    program.AddRule(rule);
}

void Parser::ParseQuery() {
//query	-> predicate Q_MARK
    Predicate* query = ParsePredicate();
    Match(Q_MARK);
    program.AddQuery(query);
}

Predicate* Parser::ParseHeadPredicate() {
//headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    Match(ID);
    Predicate* head = new Predicate(tokens.at(currentToken - 1).GetValue());
    Match(LEFT_PAREN);
    Match(ID);
    head->AddParameter(tokens.at(currentToken - 1).GetValue());
    ParseIdList(head);
    Match(RIGHT_PAREN);
    return head;
}

void Parser::ParsePredicate(Rule* rule) {
//predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    Match(ID);
    Predicate* predicate = new Predicate(tokens.at(currentToken - 1).GetValue());
    Match(LEFT_PAREN);
    ParseParameter(predicate);
    ParseParameterList(predicate);
    Match(RIGHT_PAREN);
    rule->AddBodyPredicate(predicate);
}

Predicate* Parser::ParsePredicate() {
//predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    Match(ID);
    Predicate* predicate = new Predicate(tokens.at(currentToken - 1).GetValue());
    Match(LEFT_PAREN);
    ParseParameter(predicate);
    ParseParameterList(predicate);
    Match(RIGHT_PAREN);
    return predicate;
}

void Parser::ParsePredicateList(Rule* rule) {
//predicateList	->	COMMA predicate predicateList | lambda
    if (tokens.at(currentToken).GetType() == COMMA) {
        Match(COMMA);
        ParsePredicate(rule);
        ParsePredicateList(rule);
    }
}

void Parser::ParseParameterList(Predicate* predicate) {
//parameterList	-> 	COMMA parameter parameterList | lambda
    if (tokens.at(currentToken).GetType() == COMMA) {
        Match(COMMA);
        ParseParameter(predicate);
        ParseParameterList(predicate);
    }
}

void Parser::ParseStringList(Predicate* factPredicate) {
//stringList	-> 	COMMA STRING stringList | lambda
    if (tokens.at(currentToken).GetType() == COMMA) {
        Match(COMMA);
        Match(STRING);
        factPredicate->AddParameter(tokens.at(currentToken - 1).GetValue());
        program.AddDomain(tokens.at(currentToken - 1).GetValue());
        ParseStringList(factPredicate);
    }
}

void Parser::ParseIdList(Predicate* predicate) {
//idList  	-> 	COMMA ID idList | lambda
    if (tokens.at(currentToken).GetType() == COMMA) {
        Match(COMMA);
        Match(ID);
        predicate->AddParameter(tokens.at(currentToken - 1).GetValue());
        ParseIdList(predicate);
    }
}

void Parser::ParseParameter(Predicate* predicate) {
//parameter	->	STRING | ID
    if (tokens.at(currentToken).GetType() == STRING) {
        Match(STRING);
        predicate->AddParameter(tokens.at(currentToken - 1).GetValue());
    }
    else if (tokens.at(currentToken).GetType() == ID) {
        Match(ID);
        predicate->AddParameter(tokens.at(currentToken - 1).GetValue());
    }
}

void Parser::Match(TokenType toMatch) {
    if (toMatch == tokens[currentToken].GetType()) {
        if (currentToken < (tokens.size() - 1)) {
            currentToken++;
        }
    }
    else {
        std::string error = "Failure!\n  " + tokens.at(currentToken).toString();
        throw std::invalid_argument(error);
    }
}




