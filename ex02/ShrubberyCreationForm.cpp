#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}


void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw std::runtime_error("Form is not signed!");
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();

    // Write shrubbery ASCII art to a file
    std::ofstream outFile(_target + "_shrubbery");
    if (!outFile)
        throw std::ios_base::failure("Failed to open file.");

    outFile << "       _-_\n"
            << "    /~~   ~~\\\n"
            << " /~~         ~~\\\n"
            << "{               }\n"
            << " \\  _-     -_  /\n"
            << "   ~  \\\\ //  ~\n"
            << "_- -   | | _- _\n"
            << "  _ -  | |   -_\n"
            << "      // \\\\\n";

    outFile.close();
    std::cout << "Shrubbery has been planted in " << _target + "_shrubbery" << std::endl;
}