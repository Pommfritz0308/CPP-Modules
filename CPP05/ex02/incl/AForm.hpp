#ifndef A_FORM_HPP
#define A_FORM_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, int _gradeToSign, int _gradeToExecute);
		AForm(const AForm &old);
		AForm& operator=(const AForm& old);
		virtual ~AForm();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;

	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
