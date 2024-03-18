#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &old)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = old;
}

Intern& Intern::operator=(const Intern& old)
{
	std::cout << "Intern assignation operator" << std::endl;
	(void)old;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

static Form* makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form* makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form* makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string name, std::string target)
{
	t_forms levels[3] = {{"robotomy request", &makeRobotomyRequestForm},
						{"presidential pardon request", &makePresidentialPardonForm},
						{"shrubbery creation request", &makeShrubberyCreationForm}};
	
	for (int i = 0; i < 3; i++)
	{
		if (levels[i].name == name)
		{
			std::cout << GBOLD("Intern creates ") << GBOLD(levels[i].name) << std::endl;
			return ((levels[i].func)(target));
		}
	}
	std::cout << RBOLD("Intern cannot create \"") << RBOLD(name) << RBOLD("\"") << std::endl;
	return (NULL);
}