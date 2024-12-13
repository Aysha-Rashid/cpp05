#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
    public:
        // RobotomyRequestForm(const std::string &target)
        //     : Form("Shrubbery Creation", 145, 137), _target(target) {}
        RobotomyRequestForm(const std::string name, const int signedGrade, const int executeGrade) ;
        RobotomyRequestForm(RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();

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