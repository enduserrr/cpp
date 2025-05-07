#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern &Intern::operator=(const Intern &src) {
    (void)src;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    for (int i = 0; i < 3; ++i) {
        if (formName == _forms[i]) {
            AForm* form = (this->*_makeForm[i])(target);
            return form;
        }
    }
    std::cout << "Error: Form name '" << formName << "' is not recognized." << std::endl;
    return NULL;
}

AForm* Intern::makePresidentialPardonForm(std::string target) {
    std::cout << "Intern creates " << target << " Presidential Pardon Form" << std::endl;
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string target) {
    std::cout << "Intern creates " << target << " Robotomy Form" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeshrubberyCreationForm(std::string target) {
    std::cout << "Intern creates " << target << " Shrubbery Form" << std::endl;
    return new ShrubberyCreationForm(target);
}
