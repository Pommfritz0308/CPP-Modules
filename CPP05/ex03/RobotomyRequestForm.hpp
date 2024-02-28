#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &old);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& old);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
		virtual void action() const;
};

#endif
