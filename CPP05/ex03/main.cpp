#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Form.hpp"

int main (void)
{
    Intern someRandomIntern;
    Form* rf;
    Form* scf;
    Form* ppf;
    Form* f;
    
    std::cout << BOLD("TEST: CREATE FORMS") << std::endl;
    try{
        rf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rf;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try{
        ppf = someRandomIntern.makeForm("presidential pardon request", "Bender");
        std::cout << *ppf;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try{
        scf = someRandomIntern.makeForm("shrubbery creation request", "Bender");
        std::cout << *scf;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try{
        f = someRandomIntern.makeForm("random request", "Bender");
        (void)f;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << BOLD("\nTEST: EXECUTE FORMS") << std::endl;
    Bureaucrat b("B0", 1);
    ppf->beSigned(b);
    ppf->execute(b);
    scf->beSigned(b);
    scf->execute(b);
    rf->beSigned(b);
    rf->execute(b);
    delete rf;
    delete scf;
    delete ppf;
}