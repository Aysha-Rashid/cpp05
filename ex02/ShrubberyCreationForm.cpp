#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const int signedGrade, const int executeGrade) : _name(name), _gradeSigned(signedGrade), _gradeExecute(executeGrade), _signed(0)
{
	check(*this);
	// why should we not catch exception here?
		// it would mean that an invalid Form is created
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}