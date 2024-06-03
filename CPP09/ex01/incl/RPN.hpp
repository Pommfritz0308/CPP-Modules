#ifndef R_P_N_HPP
#define R_P_N_HPP

#include <iostream>
#include <stack>
#include <cstring>

class RPN
{
    public:
        RPN();
        RPN(char **argv);
        RPN(const RPN &rpn);
        RPN &operator=(const RPN &rpn);
        ~RPN();

        float calculate();

    private:
        std::stack<float> _stack;
};

#endif