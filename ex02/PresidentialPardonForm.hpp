#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
    public:
        // PresidentialPardonForm(const std::string &target)
        //     : Form("Shrubbery Creation", 145, 137), _target(target) {}
        PresidentialPardonForm(const std::string name, const int signedGrade, const int executeGrade);
        PresidentialPardonForm(PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();

        void execute() const;
        // {
        //     if (!this.getSigned())
        //         throw std::runtime_error("Form is not signed!");
        //      std::cout << "Planting a shrubbery in " << _target << std::endl;
        // }

    private:
        std::string _target;
};

#endif