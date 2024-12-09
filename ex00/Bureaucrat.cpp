#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    try
    {
        CheckHighOrLow(_grade);
    }
    catch (const std::exception &e) {
        std::cout << "Exception Caught : " << e.what() << std::endl;
    }

    // why should we not catch exception here?
        // it would mean that an invalid bureaucrat is created
    std::cout << "Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
    try
    {
        CheckHighOrLow(copy._grade);
    }
    catch (const std::exception &e) {
        std::cout << "Exception Caught : " << e.what() << std::endl;
    }  
    std::cout << "Bureaucrat Copy Constuctor is being called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    try
    {
        CheckHighOrLow(copy._grade);
    }
    catch (const std::exception &e) {
        std::cout << "Exception Caught : " << e.what() << std::endl;
    }  
    if (this == &copy)
		return *this;
	this->_grade = copy._grade;
    std::cout << "Bureaucrat Copy Assignment Constructor is Called" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) { return (this->_name);}

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

std::ostream &operator<<(std::ostream &out,  Bureaucrat &Bureaucrat)
{
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
    return out;
}