#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	CheckHighOrLow(_grade);
	// why should we not catch exception here?
		// it would mean that an invalid bureaucrat is created
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}
Bureaucrat::Bureaucrat() : _name("default"), _grade(2)
{
	CheckHighOrLow(_grade);
	// why should we not catch exception here?
		// it would mean that an invalid bureaucrat is created
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	CheckHighOrLow(copy._grade);
	std::cout << "Copy Bureaucrat Constuctor is being called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return *this;
	CheckHighOrLow(copy._grade);
	this->_grade = copy._grade;
	std::cout << "Copy Bureaucrat Assignment Constructor is Called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName(void) { return (this->_name);}

int Bureaucrat::getGrade(void) { return (this->_grade);}

void Bureaucrat::CheckHighOrLow(int grade){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::increment() {
	try {
		CheckHighOrLow(_grade - 1);
		_grade--;
	} catch (const std::exception &e) {
		std::cout << "Increment failed: " << e.what() << std::endl;
	}
	
}

void Bureaucrat::decrement() {
	try {
		CheckHighOrLow(_grade + 1);
		_grade++;
	} catch (const std::exception &e) {
		std::cout << "Decrement failed: " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
	return (" --- Grade too high ---");
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
	return (" --- Grade too Low ---");
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed form " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " could not sign form " << form.getName()
				  << " because: " << e.what() << std::endl;
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out,  Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return out;
}