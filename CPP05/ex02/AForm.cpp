#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int _gradeToSign, int _gradeToExecute) : _name(name), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute), _signed(false)
{
	std::cout << "AForm constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm &old) : _name(old._name), _gradeToSign(old._gradeToSign), _gradeToExecute(old._gradeToExecute), _signed(false)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& old)
{
	if (this != &old)
	{
		_signed = old._signed;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << " form status: " << f.getSigned() << " grade to sign: " << f.getGradeToSign() 
		<< " grade to execute: " << f.getGradeToExecute() << std::endl;
	return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= _gradeToExecute && _signed == true)
		action();
	else if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	else if (_signed == false)
		throw FormNotSignedException();
}