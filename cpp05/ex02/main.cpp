/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:27:10 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 11:03:50 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 30); // Can sign and execute some forms
        Bureaucrat lowGrade("LowGrade", 140); // Can sign Shrubbery but not execute

        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robo("Target");
        PresidentialPardonForm pardon("Victim");

        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        lowGrade.signForm(shrub);
        bob.executeForm(shrub); //Bob's grade to low

        bob.signForm(robo);
        bob.executeForm(robo);

        bob.signForm(pardon);
        bob.executeForm(pardon);

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
