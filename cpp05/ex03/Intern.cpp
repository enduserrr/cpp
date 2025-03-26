/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:13:38 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 11:14:12 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    (void)src;
}

Intern &Intern::operator=(const Intern &src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    AForm* form = NULL;

    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    int formIndex = -1;
    for (int i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            formIndex = i;
            break;
        }
    }

    switch (formIndex) {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            std::cout << "Error: Form name '" << formName << "' is not recognized." << std::endl;
            return NULL;
    }

    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}
