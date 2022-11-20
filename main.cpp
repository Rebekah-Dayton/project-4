#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Parser.h"
#include "Interpreter.h"


int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    // TODO
    std::stringstream ss;
    std::string inputString;
    std::string filename = "please.txt"; //argv[1];
    std::ifstream input(filename);
    if (input.is_open()) {
        ss << input.rdbuf();
        inputString = ss.str();
        input.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }
    lexer->Run(inputString);

    Parser parser = Parser(lexer->GetTokens());
    parser.Parse();

    Interpreter interpreter(parser.GetDatalogProgram());
    interpreter.EvaluateRules();
    interpreter.EvaluateQueries();

    delete lexer;

    return 0;
}