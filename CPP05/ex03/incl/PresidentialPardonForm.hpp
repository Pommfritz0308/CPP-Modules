#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &old);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& old);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
		virtual void action() const;
};

#endif
