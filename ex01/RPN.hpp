#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::runtime_error;
using std::stack;
using std::string;

class RPN
{
private:
    stack<int> numbers;

    bool isOperator(const string &token);
    bool isValidNumber(const string &token);
    int applyOperation(int a, int b, char op);

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const string &expression);
};
