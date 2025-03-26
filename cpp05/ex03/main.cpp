/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:27:10 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 11:16:16 by asalo            ###   ########.fr       */
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
        Bureaucrat bob("Bob", 1);
        Intern intern;

        AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        AForm* form3 = intern.makeForm("presidential pardon", "Victim");
        AForm* form4 = intern.makeForm("NonExistentForm", "ErrorTarget");

        // Change to switch
        if (form1) {
            bob.signForm(*form1);
            bob.executeForm(*form1);
            delete form1;
        }
        if (form2) {
            bob.signForm(*form2);
            bob.executeForm(*form2);
            delete form2;
        }
        if (form3) {
            bob.signForm(*form3);
            bob.executeForm(*form3);
            delete form3;
        }
        if (form4)
            delete form4;

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
