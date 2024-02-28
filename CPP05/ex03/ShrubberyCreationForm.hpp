#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <fstream>
class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &old);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& old);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
		virtual void action() const;
};

#endif
