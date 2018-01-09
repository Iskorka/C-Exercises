#ifndef PARSER_H
#define PARSER_H

#define uint unsigned int

#include <stack>
#include <vector>
#include "math.h"
#include "nconstants.h"

#include <iostream>

class Parser
{
public:
    Parser();
    Parser(const Parser &parser);

    Parser& operator =(const Parser &parser);

    void convertToPostfix(std::string &input);

    const std::vector<std::string>& getParsedOutput() const;

    ~Parser();

private:
    std::stack<char> m_operators;
    std::vector<std::string> m_output;

    bool isNumber(const char &token) const;
    bool isLowPriority(const char &token) const;
    bool isHighPriority(const char &token) const;
    bool isOperator(const char &token) const;
    bool isInputPriorityEquals(const char &token) const;
    bool isInputPriorityLower(const char &token) const;
    bool isInputPriorityHigher(const char &token) const;

    void pushToOutput(int &outputIndex, char &input);
    void parseNumber(int &outputIndex, std::string &input, int inputIndex);
    void parseCarrotOperator(int &outputIndex, std::string &input, int inputIndex);
    void parseClosingParentheses(int &outputIndex);
};

#endif // PARSER_H
