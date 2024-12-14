#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private :
        std::string _target;
    public:
        // ShrubberyCreationForm(const std::string &target)
        //     : Form("Shrubbery Creation", 145, 137), _target(target) {}
        ShrubberyCreationForm(const std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
        // {
        //     if (!this.getSigned())
        //         throw std::runtime_error("Form is not signed!");
        //      std::cout << "Planting a shrubbery in " << _target << std::endl;
        // }

};

std::ostream &operator<<(std::ostream &out,  ShrubberyCreationForm &ShrubberyCreationForm);

#endif