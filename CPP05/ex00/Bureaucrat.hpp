#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &old);
		Bureaucrat& operator=(const Bureaucrat& old);
		~Bureaucrat();
		
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

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
