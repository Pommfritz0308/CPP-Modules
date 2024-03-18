#include "Bureaucrat.hpp"

static void createAndPrintBureaucrat(const std::string& name, int grade) {
    try {
        std::cout << GBOLD("Creating Bureaucrat ") << GBOLD(name) << GBOLD(" with grade ") << grade << std::endl;
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
        std::cout << GBOLD("Creating Bureaucrat b3 with grade 1 and incrementing it") << std::endl;
        Bureaucrat b3("b3", 1);
        b3.incrementGrade();
        std::cout << b3;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}