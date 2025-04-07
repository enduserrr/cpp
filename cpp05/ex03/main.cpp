/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:27:10 by asalo             #+#    #+#             */
/*   Updated: 2025/04/07 12:08:31 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bobby("Bobby", 1);
        Intern intern;
        for (int i = 0; i < 3; i++) {
            std::cout << std::endl;
            AForm* form = intern.makeForm(intern._forms[i], "Bender");
            if (form) {
                bobby.signForm(*form);
                bobby.executeForm(*form);
                delete form;
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat sir("Sir", 149);
        Intern intern2;
        AForm* inval = intern2.makeForm("Invalid Form", "You");
        if (inval) {
            sir.signForm(*inval);
            sir.executeForm(*inval);
            delete inval;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
