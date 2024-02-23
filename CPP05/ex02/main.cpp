#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static Bureaucrat* createAndPrintBureaucrat(const std::string& name, int grade) {
    try {
        Bureaucrat *b = new Bureaucrat(name, grade);
        std::cout << *b;
        return (b);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (NULL);
    }
}

int main (void)
{
    Bureaucrat *b0 = createAndPrintBureaucrat("b0", 1);
    Bureaucrat *b1 = createAndPrintBureaucrat("b1", 150);
    Bureaucrat *b2 = createAndPrintBureaucrat("b2", 50);

    AForm *f0 = new ShrubberyCreationForm("f0");
    AForm *f1 = new RobotomyRequestForm("f1");
    AForm *f2 = new PresidentialPardonForm("f2");

    try{
        f0->beSigned(*b0);
        std::cout << *f0;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        f1->beSigned(*b1);
        std::cout << *f1;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        f2->beSigned(*b2);
        std::cout << *f2;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    b0->executeForm(*f0);
    b1->executeForm(*f1);
    b2->executeForm(*f2);

    delete b0;
    delete b1;
    delete b2;
    delete f0;
    delete f1;
    delete f2;
}