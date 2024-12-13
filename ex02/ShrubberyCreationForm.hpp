#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
    public:
        // ShrubberyCreationForm(const std::string &target)
        //     : Form("Shrubbery Creation", 145, 137), _target(target) {}
        ShrubberyCreationForm(const std::string name, const int signedGrade, const int executeGrade) ;
        ShrubberyCreationForm(ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();

        void execute() const override;
        // {
        //     if (!this.getSigned())
        //         throw std::runtime_error("Form is not signed!");
        //      std::cout << "Planting a shrubbery in " << _target << std::endl;
        // }

    private:
        std::string _target;
};

#endif