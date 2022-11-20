#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    this->type = type;
    value = description;
    lineNumber = line;
}

std::string Token::typeToString(TokenType type) {
    switch (type) {
        case COLON: return "COLON";
        case COLON_DASH: return "COLON_DASH";
        case COMMA: return "COMMA";
        case PERIOD: return "PERIOD";
        case Q_MARK: return "Q_MARK";
        case LEFT_PAREN: return "LEFT_PAREN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case MULTIPLY: return "MULTIPLY";
        case ADD: return "ADD";
        case SCHEMES: return "SCHEMES";
        case FACTS: return "FACTS";
        case RULES: return "RULES";
        case QUERIES: return "QUERIES";
        case ID: return "ID";
        case STRING: return "STRING";
        case COMMENT: return "COMMENT";
        case EOF_TOKEN: return "EOF";
        case UNDEFINED: return "UNDEFINED";
    }
    return "ERROR";
}
