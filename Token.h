#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>

enum TokenType {
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    EOF_TOKEN,
    UNDEFINED, COLON
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType type;
    int lineNumber;
    std::string value;
public:
    Token(TokenType type, std::string description, int line);

    TokenType GetType() {return type;}
    std::string GetValue() {return value;}
    std::string typeToString(TokenType type);

    std::string toString() {
        return "(" + typeToString(type) + ",\"" + value + "\"," + std::to_string(lineNumber) + ")";
    }
    // TODO: add other needed methods
};

#endif // TOKEN_H

