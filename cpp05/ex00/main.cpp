/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:51 by asalo             #+#    #+#             */
/*   Updated: 2025/04/06 17:32:00 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat sir("Sir", 50);
        std::cout << sir << std::endl;

        sir.incrementGrade();
        std::cout << sir << std::endl;

        sir.decrementGrade();
        std::cout << sir << std::endl;

        Bureaucrat bobby("Bobby", 1);
        std::cout << bobby << std::endl;
        bobby.incrementGrade(); //Grade too high
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat dummy("Dummy", 150);
        Bureaucrat champ("Champ", 1);
        std::cout << dummy << std::endl;
        std::cout << champ << std::endl;
        // Try a grade too low
        dummy.decrementGrade();
        champ.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {// Try creating with inval grade (too low)
        Bureaucrat inval("Inval", 0);
        std::cout << inval << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {// Try creating with inval grade (too low)
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
