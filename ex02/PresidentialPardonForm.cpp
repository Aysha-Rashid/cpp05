#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm(_name, 25, 5)
{
	check(*this);
	// why should we not catch exception here?
		// it would mean that an invalid Form is created
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : _target(copy._target), _gradeSigned(copy._gradeSigned), _gradeExecute(copy._gradeExecute), _signed(copy._signed)
{
	check(copy);
	std::cout << "Copy PresidentialPardonForm Constuctor is being called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	check(copy);
	if (this == &copy)
		return *this;
	const_cast<std::string&>(this->_target) = copy._target;
	const_cast<int&>(this->_gradeSigned) = copy._gradeSigned;
	const_cast<int&>(this->_gradeExecute) = copy._gradeExecute;
	this->_signed = copy._signed;
	std::cout << "Copy PresidentialPardonForm Assignment Constructor is Called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}
void PresidentialPardonForm::check(const PresidentialPardonForm &copy)
{
	if (copy._gradeSigned > 150)
		throw PresidentialPardonForm::GradeTooLowException();
	else if (copy._gradeSigned < 1)
		throw PresidentialPardonForm::GradeTooHighException();
	if (copy._gradeExecute < 1)
		throw PresidentialPardonForm::GradeTooHighException();
	else if (copy._gradeExecute > 150)
		throw PresidentialPardonForm::GradeTooLowException();
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->_gradeSigned == 25 && this->_gradeExecute == 5)
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
