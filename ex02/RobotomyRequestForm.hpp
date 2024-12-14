#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "RobotomyRequestForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
    public:
        // RobotomyRequestForm(const std::string &target)
        //     : Form("Shrubbery Creation", 145, 137), _target(target) {}
        RobotomyRequestForm(const std::string name) ;
        RobotomyRequestForm(RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
        // {
        //     if (!this.getSigned())
        //         throw std::runtime_error("Form is not signed!");
        //      std::cout << "Planting a shrubbery in " << _target << std::endl;
        // }

    private:
        std::string _target;
};

std::ostream &operator<<(std::ostream &out,  RobotomyRequestForm &RobotomyRequestForm);

#endif