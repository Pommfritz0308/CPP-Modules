#include "RPN.hpp"

RPN::RPN() : _stack()
{
}

RPN::RPN(char **argv) : _stack()
{
    int i = 0;
    while (argv[i])
        i++;
    while (i-- > 0) {
        if (std::strlen(argv[i]) == 1 && std::isdigit(argv[i][0]))
        {
            _stack.push(static_cast<float>(argv[i][0] - '0'));
        }
        else if (std::strlen(argv[i]) == 1 && (argv[i][0] == '+' || argv[i][0] == '-' || argv[i][0] == '*' || argv[i][0] == '/'))
        {
            _stack.push(static_cast<float>(argv[i][0]));
        }
        else
            throw std::invalid_argument("Invalid expression.");
    }
}

RPN::RPN(const RPN &rpn) : _stack(rpn._stack)
{
}

RPN &RPN::operator=(const RPN &rpn)
{
    _stack = rpn._stack;
    return *this;
}

RPN::~RPN()
{
}

static float operation(float a, float b, char op)
{
switch (op)
    {
       case '+':
          return a + b;
       case '-':
          return a - b;
       case '*':
          return a * b;
       case '/':
          if(b == 0){
             throw std::invalid_argument("Division by zero.");
          }
          return a / b;
       default:
          throw std::invalid_argument("Invalid operator.");
    }
}

float RPN::calculate(void)
{
   float a, b;
   std::stack<float> temp;

   while(!_stack.empty()){
      float value = _stack.top();
      _stack.pop();

      if(value == '+' || value == '-' || value == '*' || value == '/'){
         if(temp.size() < 2) {
            throw std::runtime_error("Not enough operands for the operation.");
         }
         b = temp.top();
         temp.pop();
         a = temp.top();
         temp.pop();
         temp.push(operation(a, b, static_cast<char>(value)));
      }
      else{
         temp.push(value);
      }
   }
   if(temp.size() != 1) {
      throw std::runtime_error("The expression is not valid.");
   }
   return temp.top();
}
