#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(name, 25, 5) , _target(name)
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 25, 5)
{
	this->_target = copy._target;
	std::cout << "Copy ShrubberyCreationForm Constuctor is being called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	std::cout << "Copy ShrubberyCreationForm Assignment Constructor is Called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    (void) executor;
    std::cout << "ShrubberyCreationForm cannot be executed" << std::endl;
}

// void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
// {
//     if (!this->beSigned(&executor))
//         throw std::runtime_error("Form is not signed!");
//     if (executor.getGrade() > getExecuteGrade())
//         throw GradeTooLowException();

//     // Write shrubbery ASCII art to a file
//     std::ofstream outFile(_target + "_shrubbery");
//     if (!outFile)
//         throw std::ios_base::failure("Failed to open file.");

//     outFile << "       _-_\n"
//             << "    /~~   ~~\\\n"
//             << " /~~         ~~\\\n"
//             << "{               }\n"
//             << " \\  _-     -_  /\n"
//             << "   ~  \\\\ //  ~\n"
//             << "_- -   | | _- _\n"
//             << "  _ -  | |   -_\n"
//             << "      // \\\\\n";

//     outFile.close();
//     std::cout << "Shrubbery has been planted in " << _target + "_shrubbery" << std::endl;
// }