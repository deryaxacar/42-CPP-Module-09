#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : numbers(other.numbers) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        numbers = other.numbers;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const string &token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidNumber(const string &token)
{
    return (token.length() == 1 && token[0] >= '0' && token[0] <= '9');
}

int RPN::applyOperation(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        if (b == 0)
            throw runtime_error("Error: Division by zero.");
        return a / b;
    }

    throw runtime_error("Error: Invalid operator.");
}

int RPN::evaluate(const string &expression)
{
    std::istringstream ss(expression);
    string token;

    while (ss >> token)
    {
        if (isValidNumber(token))
            numbers.push(std::atoi(token.c_str()));

        else if (isOperator(token))
        {
            if (numbers.size() < 2)
                throw runtime_error("Error: Not enough numbers for operation.");

            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            numbers.pop();

            numbers.push(applyOperation(a, b, token[0]));
        }

        else
            throw runtime_error("Error");
    }

    if (numbers.size() != 1)
        throw runtime_error("Error: Too many numbers left after operations.");

    return numbers.top();
}
