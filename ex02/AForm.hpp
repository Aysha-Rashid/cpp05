#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        const int _gradeSigned;
        const int _gradeExecute;
        bool _signed;
        //
    public:
        Form(const std::string name, const int signedGrade, const int executeGrade) ;
        Form(Form &copy);
        Form &operator=(const Form &copy);
        virtual ~Form();

        virtual void execute() const = 0;  // Pure virtual function (makes Form abstract)

        void beSigned(Bureaucrat Bureaucrat);
        std::string getName() const;
        int getGradeSigned() const;
        int getExecute() const;
        bool getSigned();
        void check(const Form &copy);
        void execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };
        // exceptions for form to check if the grade if out of bound 
};

std::ostream &operator<<(std::ostream &out,  Form &Form);

#endif