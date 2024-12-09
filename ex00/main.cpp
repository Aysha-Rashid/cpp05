#include "Bureaucrat.hpp"

int main()
{
    // try {
        Bureaucrat bureaucrat1("Alice", 0);
        std::cout << bureaucrat1;

        bureaucrat1.increment();
        std::cout << bureaucrat1;

        // std::cout << "After increment: " << bureaucrat1;

        // std::cout << "\n";
        // Bureaucrat bureaucrat2("Bob", 149);
        // std::cout << bureaucrat2;

        // bureaucrat2.decrementGrade();
        // std::cout << "After decrement: " << bureaucrat2;

        // std::cout << "\n";
        // Bureaucrat bureaucrat3("Charlie", 151);  // Should throw an exception
    // }
    // catch (std::exception &error) {
    //     std::cerr << "\nException caught: " << error.what();
    // }
    // dude.getName();
    // dude.getGrade();
}