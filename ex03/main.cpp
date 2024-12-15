#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrfp;
	AForm* rrfs;
	AForm* rrfr;
	rrfp = someRandomIntern.makeForm("Presidential pardon", "Bender");
	rrfs = someRandomIntern.makeForm("shrubbery creation", "beauty");
	rrfr = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrfp;
	std::cout << *rrfs;
	delete rrfp;
	delete rrfs;
	delete rrfr;
	return 0;
}
