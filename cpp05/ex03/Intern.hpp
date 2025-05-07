#ifndef INTERN_HPP
#define INTERN_HPP


#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:
        AForm* (Intern::*_makeForm[3])(std::string target) = {&Intern::makePresidentialPardonForm,
                                                                &Intern::makeRobotomyRequestForm,
                                                                &Intern::makeshrubberyCreationForm};

    public:
        const std::string _forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

        Intern();
        Intern(const Intern &src);
        ~Intern();

        Intern &operator=(const Intern &src);

        AForm *makeForm(const std::string& formName, const std::string& target);

        AForm *makePresidentialPardonForm(std::string target);
        AForm *makeRobotomyRequestForm(std::string target);
        AForm *makeshrubberyCreationForm(std::string target);

};

#endif
