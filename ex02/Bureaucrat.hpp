#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat();
        Bureaucrat(Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();


        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw ();
        };


        const std::string getName(void);
        int getGrade(void);
        void increment(void);
        void decrement(void);
        void CheckHighOrLow(int grade);
        void signForm(Form &form); // should check if the form is signed or not
        void executeForm(AForm const & form);
};
std::ostream &operator<<(std::ostream &out,  Bureaucrat &Bureaucrat);

#endif