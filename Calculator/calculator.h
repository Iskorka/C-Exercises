#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "parser.h"

class Calculator
{
public:
    Calculator();

    void execute();

    ~Calculator();

private:
    Calculator(const Calculator &calculator);
    Calculator& operator=(const Calculator &calculator);

    Parser m_stringParser;
    std::vector<std::string> m_input;
    std::stack<double> m_calculationStack;

    void calculate();
    bool isOperator(const std::string &token) const;
    void operateOnStack(const char operation);
};

#endif // CALCULATOR_H
