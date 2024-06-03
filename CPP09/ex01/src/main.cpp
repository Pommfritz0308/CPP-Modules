#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: ./rpn <expression in reverse polish notation>" << std::endl;
        return 1;
    }
    try {
        RPN rpn(argv + 1);
        float result = rpn.calculate();
        std::cout << "RESULT: " << result << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}