/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:27:10 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 10:50:53 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form form1("Application", 60, 70); // Grade to sign: 60
        Form form2("Promotion", 40, 50);  // Grade to sign: 40

        std::cout << bob << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        bob.signForm(form1); // Bob's grade (50) is not high enough to sign form1 (60)
        bob.signForm(form2); // Bob's grade (50) *is* high enough to sign form2 (40)

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        Bureaucrat alice("Alice", 30);
        std::cout << alice << std::endl;
        alice.signForm(form1); // Alice's grade (30) *is* high enough to sign form1 (60)
        std::cout << form1 << std::endl;

        //Test grade too high
        Form form3("grade to high", 0, 50);
        std::cout << form3 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat lowGrade("LowGrade", 150);
        Form form4("test grade low", 149, 50);
        lowGrade.signForm(form4);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
