#ifndef INTERN_HPP
#define INTERN_HPP
# include "Form.hpp"

struct t_forms
{
	std::string name;
	Form* (*func)(std::string target);
};

class Intern
{
	public:
		Intern();
		Intern(const Intern &old);
		Intern& operator=(const Intern& old);
		~Intern();

		Form* makeForm(std::string name, std::string target);
		
};
#endif
