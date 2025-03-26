/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:51 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 10:25:53 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.decrementGrade();
        std::cout << bob << std::endl;

        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;

        // Attempt to increment above the highest grade
        alice.incrementGrade(); // Should throw GradeTooHighException
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat lowGrade("LowGrade", 150);
        std::cout << lowGrade << std::endl;

        // Attempt to decrement below the lowest grade
        lowGrade.decrementGrade(); // Should throw GradeTooLowException
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Attempt to create a bureaucrat with an invalid grade
        Bureaucrat invalid("Invalid", 0); // Should throw GradeTooHighException
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid2("Invalid2", 151); // Should throw GradeTooLowException
        std::cout << invalid2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
