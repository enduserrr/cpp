/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:44:48 by asalo             #+#    #+#             */
/*   Updated: 2025/05/06 18:45:06 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"
#include <iostream> // For std::cerr, std::endl
#include <stdexcept> // For std::exception

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input sequence provided. Usage: ./PmergeMe <positive_integer_sequence>" << std::endl;
        return 1;
    }
    // Check for "-h" or "--help" (optional, not required by subject)
/*     std::string first_arg = argv[1];
    if (first_arg == "-h" || first_arg == "--help") {
        std::cout << "Usage: ./PmergeMe <positive_integer_sequence>" << std::endl;
        std::cout << "Sorts a sequence of positive integers using the Ford-Johnson algorithm." << std::endl;
        return 0;
    } */
    PmergeMe sorter;
    try {
        sorter.sortAndReport(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl; // Error messages from PmergeMe printed to cerr
        return 1;
    }
    return 0;
}