#include "calculator.h"

Calculator::Calculator()
{

}

void Calculator::execute()
{
    std::string input;
    std::cin>>input;

    m_stringParser.convertToPostfix(input);
    m_input = m_stringParser.getParsedOutput();

    calculate();

    std::cout << m_calculationStack.top() << std::endl;
}

Calculator::~Calculator()
{

}

void Calculator::calculate()
{
    for (uint i=0; i<m_input.size(); ++i)
    {
        if (!isOperator(m_input[i]))
        {
            m_calculationStack.push(std::stod(m_input[i]));
        }

        else
        {
            operateOnStack(m_input[i][0]);
        }
    }
}

bool Calculator::isOperator(const std::string &token) const
{
    return (token[0] == NConstants::PLUS || token[0] == NConstants::MINUS ||
            token[0] == NConstants::MULTIPLY || token[0] == NConstants::DIVIDE ||
            token[0] == NConstants::CARROT);
}

void Calculator::operateOnStack(const char operation)
{
    double tmp1 = m_calculationStack.top();
    m_calculationStack.pop();
    double tmp2 = m_calculationStack.top();
    m_calculationStack.pop();

    switch (operation)
    {
        case NConstants::PLUS:
            m_calculationStack.push(tmp1+tmp2);
            break;

        case NConstants::MINUS:
            m_calculationStack.push(tmp2-tmp1);
            break;

        case NConstants::MULTIPLY:
            m_calculationStack.push(tmp1*tmp2);
            break;

        case NConstants::DIVIDE:
            m_calculationStack.push(tmp2/tmp1);
            break;

        case NConstants::CARROT:
            m_calculationStack.push(pow(tmp2, tmp1));
            break;

        default:
            throw std::runtime_error(NConstants::NO_SUCH_OPERATION_ERROR);
            break;
    }
}
