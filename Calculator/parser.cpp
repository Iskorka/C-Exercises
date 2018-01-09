#include "parser.h"


Parser::Parser()
{
    m_output.push_back(NConstants::EMPTY_STRING);
}

Parser::Parser(const Parser &parser)
{
    this->m_operators = parser.m_operators;
    this->m_output = parser.m_output;
}

Parser &Parser::operator =(const Parser &parser)
{
    if (this == &parser)
    {
        return *this;
    }

    else
    {
        this->m_operators = parser.m_operators;
        this->m_output = parser.m_output;
    }

    return *this;
}

void Parser::convertToPostfix(std::string &input)
{
    int outputIndex = 0;

    for (uint i=0; i<input.length(); ++i)
    {
        if (isNumber(input[i]))
        {
            parseNumber(outputIndex, input, i);
        }

        else if ((m_operators.empty() && isOperator(input[i])) ||
                  isInputPriorityHigher(input[i]))
        {
            m_operators.push(input[i]);
        }

        else if  (isInputPriorityLower(input[i]) || isInputPriorityEquals(input[i]))
        {
            pushToOutput(outputIndex, m_operators.top());

            m_operators.pop();
            m_operators.push(input[i]);
        }

        else if ((isOperator(input[i]) && NConstants::OPEN_PARENTHESES == m_operators.top()) ||
                 (NConstants::OPEN_PARENTHESES == input[i]))
        {
            m_operators.push(input[i]);
        }

        else if (NConstants::CLOSE_PARENTHESES == input[i])
        {
            parseClosingParentheses(outputIndex);
        }

        else if (NConstants::CARROT == input[i])
        {
            parseCarrotOperator(outputIndex, input, i);
        }

        else
        {
            throw std::runtime_error(NConstants::INVALID_INPUT_ERROR);
        }
    }

    while (!m_operators.empty())
    {
        pushToOutput(outputIndex, m_operators.top());
        m_operators.pop();
    }

    m_output.pop_back();
}

const std::vector<std::string> &Parser::getParsedOutput() const
{
    return m_output;
}

Parser::~Parser()
{

}

bool Parser::isNumber(const char &token) const
{
    return ((NConstants::ZERO_CHAR <= token &&
             NConstants::NINE_CHAR >= token) ||
             NConstants::DOT == token);
}

bool Parser::isLowPriority(const char &token) const
{
    return (NConstants::PLUS == token  || NConstants::MINUS == token);
}

bool Parser::isHighPriority(const char &token) const
{
    return (NConstants::MULTIPLY == token || NConstants::DIVIDE == token);
}

bool Parser::isOperator(const char &token) const
{
    return (isLowPriority(token) || isHighPriority(token) || NConstants::CARROT == token);
}

bool Parser::isInputPriorityEquals(const char &token) const
{
    return ((isLowPriority(token) && isLowPriority(m_operators.top())) ||
            (isHighPriority(token) && isHighPriority(m_operators.top())));
}

bool Parser::isInputPriorityLower(const char &token) const
{
    return (isLowPriority(token) && isHighPriority(m_operators.top()));
}

bool Parser::isInputPriorityHigher(const char &token) const
{
    return (isHighPriority(token) && isLowPriority(m_operators.top()));
}

void Parser::pushToOutput(int &outputIndex, char &input)
{
    m_output[outputIndex] += input;
    m_output.push_back(NConstants::EMPTY_STRING);
    ++outputIndex;
}

void Parser::parseNumber(int &outputIndex, std::string &input, int inputIndex)
{
    if (isNumber(input[inputIndex+1]))
    {
       m_output[outputIndex] += input[inputIndex];
    }

    else if (!isNumber(input[inputIndex+1]))
    {
        pushToOutput(outputIndex, input[inputIndex]);
    }
}

void Parser::parseCarrotOperator(int &outputIndex, std::string &input, int inputIndex)
{
    if (isLowPriority(m_operators.top()) || isHighPriority(m_operators.top()))
    {
        m_operators.push(input[inputIndex]);
    }

    else if (m_operators.top() == NConstants::CARROT)
    {
        pushToOutput(outputIndex, m_operators.top());
        m_operators.pop();
    }
}

void Parser::parseClosingParentheses(int &outputIndex)
{
    while (m_operators.top() != NConstants::OPEN_PARENTHESES)
    {
        pushToOutput(outputIndex, m_operators.top());
        m_operators.pop();
    }
    m_operators.pop();
}
