#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int signedGrade, const int executeGrade) : _name(name), _gradeSigned(signedGrade), _gradeExecute(executeGrade), _signed(0)
{
	check(*this);
	// why should we not catch exception here?
		// it would mean that an invalid AForm is created
	std::cout << "Default AForm constructor called" << std::endl;
}
AForm::AForm(AForm &copy) : _name(copy._name), _gradeSigned(copy._gradeSigned), _gradeExecute(copy._gradeExecute), _signed(copy._signed)
{
	check(copy);
	std::cout << "Copy AForm Constuctor is being called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	check(copy);
	if (this == &copy)
		return *this;
	const_cast<std::string&>(this->_name) = copy._name;
	const_cast<int&>(this->_gradeSigned) = copy._gradeSigned;
	const_cast<int&>(this->_gradeExecute) = copy._gradeExecute;
	this->_signed = copy._signed;
	std::cout << "Copy AForm Assignment Constructor is Called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Default AForm destructor called" << std::endl;
}
void AForm::check(const AForm &copy)
{
	if (copy._gradeSigned > 150)
		throw AForm::GradeTooLowException();
	else if (copy._gradeSigned < 1)
		throw AForm::GradeTooHighException();
	if (copy._gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (copy._gradeExecute > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const{ return(this->_name); }
int AForm::getGradeSigned() const{ return(this->_gradeSigned); }
int AForm::getExecute() const{ return(this->_gradeExecute); }
bool AForm::getSigned() const { return(this->_signed); }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    // Check if the Bureaucrat's grade is high enough to sign
    if (bureaucrat.getGrade() > this->_gradeSigned)
        throw GradeTooLowException();  // Bureaucrat's grade is too low to sign the form

    // Mark the form as signed
    this->_signed = true;

    // Print success message
    std::cout << bureaucrat.getName() << " successfully signed " << this->_name << std::endl;
}


const char* AForm::GradeTooHighException::what() const throw ()
{
	return (" --- Grade too high to sign this AForm ---");
}

const char* AForm::GradeTooLowException::what() const throw ()
{
	return (" --- Grade too Low to sign this AForm ---");
}

std::ostream &operator<<(std::ostream &out,  AForm &AForm)
{
	out << AForm.getName() << ", needs to have sign grade:  " << AForm.getGradeSigned() << 
		 " to sign the AForm and have the execute grade: " 
		<< AForm.getExecute()  << " to execute the AForm " << std::endl;
	return out;
}
