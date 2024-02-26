#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &old) : _name(old._name), _grade(old._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& old)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &old)
	{
		_grade = old._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return os;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	if (f.getSigned())
		std::cout << "Bureaucrat \"" << _name << "\" signed " << f.getName() << std::endl;
	else
		std::cout << "Bureaucrat \"" << _name << "\" couldn't sign " << f.getName() << " because the grade was too low" << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (form.getSigned())
	{
		if (_grade <= form.getGradeToExecute())
		{
			std::cout << GBOLD(_name) << GBOLD(" executes ") << GBOLD(form.getName()) << std::endl;
			form.action();
		}
		else
			std::cout << RBOLD(_name) << RBOLD(" couldn't execute ") << RBOLD(form.getName()) << RBOLD(" because the grade was too low") << std::endl;
	}
	else
		std::cout << RBOLD(_name) << RBOLD(" couldn't execute ") << RBOLD(form.getName()) << RBOLD(" because the form is not signed") << std::endl;
}