#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        const int _gradeSigned;
        const int _gradeExecute;
        bool _signed;
        //
    public:
        AForm(const std::string name, const int signedGrade, const int executeGrade) ;
        AForm(AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        // virtual void execute() const = 0;  // Pure virtual function (makes AForm abstract)

        void beSigned(const Bureaucrat &Bureaucrat);
        std::string getName() const;
        int getGradeSigned() const;
        int getExecute() const;
        bool getSigned() const;
        void check(const AForm &copy);
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };

        virtual void execute(Bureaucrat const & executor) const = 0;
        // exceptions for AForm to check if the grade if out of bound 
};

std::ostream &operator<<(std::ostream &out,  AForm &Form);

#endif