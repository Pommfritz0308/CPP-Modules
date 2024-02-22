#include "Bureaucrat.hpp"

static void createAndPrintBureaucrat(const std::string& name, int grade) {
    try {
        Bureaucrat b(name, grade);
        std::cout << b;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    createAndPrintBureaucrat("b0", 1);
    createAndPrintBureaucrat("b1", 150);
    createAndPrintBureaucrat("b2", 151);
    try
    {
        Bureaucrat b5("b5", 1);
        b5.incrementGrade();
        std::cout << b5;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}