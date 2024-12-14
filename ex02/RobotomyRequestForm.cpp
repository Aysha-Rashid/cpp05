#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm(_name, 72, 45)
{
	check(*this);
	// why should we not catch exception here?
		// it would mean that an invalid Form is created
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}


void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->_gradeSigned == 72 && this->_gradeExecute == 45)
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		std::cout << "robotomy failed";
}
