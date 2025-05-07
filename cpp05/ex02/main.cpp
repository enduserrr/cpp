#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bobby("Bobby", 30); // Able to sign and exec some forms
        Bureaucrat lowGrade("LowGrade", 140); // Able to sign Shrubbery, not exec

        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robo("Target");
        PresidentialPardonForm pardon("Victim");
        std::cout << bobby << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        std::cout << std::endl;
        lowGrade.signForm(shrub);
        bobby.executeForm(shrub);

        std::cout << std::endl;
        bobby.signForm(robo);
        bobby.executeForm(robo);

        std::cout << std::endl;
        bobby.signForm(pardon);
        bobby.executeForm(pardon);

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
