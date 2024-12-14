#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try {
		Bureaucrat alice("Alice",44);
		Bureaucrat bob("Bob", 5);
		PresidentialPardonForm president("Confidential");
		RobotomyRequestForm robotomy("testing");

		president.execute(bob);
		robotomy.beSigned(alice);
		alice.executeForm(robotomy);
		// robotomy.execute(alice);
		// AForm form("Confidential", 3, 5); 

		// alice.signForm(form);
		// std::cout << form;

		// bob.signForm(form);

		// bob = alice; // wont even bother to come here after it caught the exception
		// bob.signForm(form);
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
