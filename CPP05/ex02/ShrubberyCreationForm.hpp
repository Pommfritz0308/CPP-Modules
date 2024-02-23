#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>
class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &old);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& old);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
		void action() const;
};

#endif
