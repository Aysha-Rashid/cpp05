#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const int signedGrade, const int executeGrade) : _name(name), _gradeSigned(signedGrade), _gradeExecute(executeGrade), _signed(0)
{
	check(*this);
	// why should we not catch exception here?
		// it would mean that an invalid Form is created
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}