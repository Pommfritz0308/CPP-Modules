#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int _gradeToSign, int _gradeToExecute) : _name(name), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute), _signed(false)
{
	std::cout << "Form constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}
Form::Form(const Form &old) : _name(old._name), _gradeToSign(old._gradeToSign), _gradeToExecute(old._gradeToExecute), _signed(false)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& old)
{
	if (this != &old)
	{
		_signed = old._signed;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << " form status: " << f.getSigned() << " grade to sign: " << f.getGradeToSign() 
		<< " grade to execute: " << f.getGradeToExecute() << std::endl;
	return os;
}