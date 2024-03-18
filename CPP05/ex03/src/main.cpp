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
        std::cerr << RBOLD(e.what()) << std::endl;
    }
    try{
        ppf = someRandomIntern.makeForm("presidential pardon request", "Bender");
        std::cout << *ppf;

    }
    catch (std::exception &e)
    {
        std::cerr << RBOLD(e.what()) << std::endl;
    }
    try{
        scf = someRandomIntern.makeForm("shrubbery creation request", "Bender");
        std::cout << *scf;
    }
    catch (std::exception &e)
    {
        std::cerr << RBOLD(e.what()) << std::endl;
    }
    try{
        f = someRandomIntern.makeForm("random request", "Bender");
        (void)f;
    }
    catch (std::exception &e)
    {
        std::cerr << RBOLD(e.what()) << std::endl;
    }

    std::cout << BOLD("\nTEST: EXECUTE FORMS") << std::endl;
    Bureaucrat b("B0", 7);
    try{
        rf->beSigned(b);
        std::cout << *rf;
        rf->execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << RBOLD(e.what()) << std::endl;
    }
    try{
        ppf->beSigned(b);
        std::cout << *ppf;
        ppf->execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << RBOLD(e.what()) << std::endl;
    }
    try{
        scf->beSigned(b);
        std::cout << *scf;
        scf->execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << RBOLD(e.what()) << std::endl;
    }
    delete rf;
    delete ppf;
    delete scf;
}