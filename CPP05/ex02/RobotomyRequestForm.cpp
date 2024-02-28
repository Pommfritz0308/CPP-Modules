#include "RobotomyRequestForm.hpp"
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &old) : AForm(old)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& old)
{
	if (this != &old)
	{
		AForm::operator=(old);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::action() const
{
	std::cout << YBOLD("Bzzzz...Brrrr...Whirrr...Skurrr") << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2 == 0)
		std::cout << YBOLD(AForm::getName()) << YBOLD(" has been robotomized") << std::endl;
	else
		std::cout << RBOLD(AForm::getName()) << RBOLD(" robotomization failed") << std::endl;
}
