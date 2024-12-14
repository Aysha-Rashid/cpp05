#ifndef INTERN_HPPP
#define INTERN_HPPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;

class Intern : public AForm
{
    private:
        std::string _target;

    public:
        Intern();
        Intern &operator=(const Intern &copy);
        ~Intern();

        AForm *makeForm(std::string form, std::string target);        
        // void execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &out,  Intern &Intern);

#endif