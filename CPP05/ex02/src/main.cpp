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
    Bureaucrat *b1 = createAndPrintBureaucrat("b1", 5);
    Bureaucrat *b2 = createAndPrintBureaucrat("b2", 6);

    AForm *f0 = new ShrubberyCreationForm("f0");
    AForm *f1 = new PresidentialPardonForm("f1");
    AForm *f2 = new RobotomyRequestForm("f2");

    try{
        std::cout << *f0;
        f0->beSigned(*b0);
        std::cout << *f0;
    }
    catch (std::exception &e)
    {
        std::cout << RBOLD(f0->getName()) << RBOLD(" cannot sign...") << std::endl;
        std::cout << RBOLD(e.what()) << std::endl;
    }
    try{
        std::cout << *f1;
        f1->beSigned(*b1);
        std::cout << *f1;
    }
    catch (std::exception &e)
    {
        std::cout << RBOLD(f1->getName()) << RBOLD(" cannot sign...") << std::endl;
        std::cout << RBOLD(e.what()) << std::endl;
    }
    try{
        std::cout << *f2;
        f2->beSigned(*b2);
        std::cout << *f2;
    }
    catch (std::exception &e)
    {
        std::cout << RBOLD(f2->getName()) << RBOLD(" cannot sign...") << std::endl;
        std::cout << RBOLD(e.what()) << std::endl;
    }

    std::cout << BOLD("\nTESTING BUREAUCRAT EXECUTE FORM:") << std::endl;
    b0->executeForm(*f0);
    b1->executeForm(*f1);
    b2->executeForm(*f2);

    std::cout << BOLD("\nTESTING EXECUTE FORM:") << std::endl;
    try
    {
        f0->execute(*b0);
    }
    catch(const std::exception& e)
    {
        std::cout << RBOLD(e.what()) << '\n';
    }
    try
    {
        f1->execute(*b2);
    }
    catch(const std::exception& e)
    {
        std::cout << RBOLD(e.what()) << '\n';
    }

    try
    {
        f2->execute(*b1);
    }
    catch(const std::exception& e)
    {
        std::cout << RBOLD(e.what()) << '\n';
    }

    delete b0;
    delete b1;
    delete b2;
    delete f0;
    delete f1;
    delete f2;
}