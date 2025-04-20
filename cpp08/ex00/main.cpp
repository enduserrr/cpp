/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:55:57 by asalo             #+#    #+#             */
/*   Updated: 2025/04/20 12:26:40 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "EasyFind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <exception> // To catch exceptions
#include <iterator>

#define WB "\033[1;97m"
#define RED "\033[1;91m"
#define GR "\033[1;92m"
#define RES "\033[0m"
#define GC "\033[3;90m"

// Helper function to demonstrate finding and optionally modifying
template <typename T>
void testContainer(T& container, int valueToFind, const std::string& containerName) {
    std::cout << WB << "# Testing " << containerName << " #" << RES << std::endl;
    std::cout << "Container elements: ";
    // C++23 range-based for loop (using auto const&)
    for (auto const& elem : container) {
        std::cout << GC << elem << " ";
    }
     if (container.empty()) {
        std::cout << GC << "(empty)" << RES;
    }
    std::cout << std::endl;
    std::cout << RES << "Searching for value: " << GC << valueToFind << RES << std::endl;

    try {
        typename T::iterator it = easyFind(container, valueToFind);
        std::cout << GR << "OK!: found value: " << RES << *it << " at position (distance from begin): "
                  << std::distance(container.begin(), it) << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << RED << "FAIL: exception: " RES << e.what() << std::endl;
    } catch (const std::exception& e) { //std exception
        std::cerr << RED << "FAIL: enexpected standard exception: " << RES << e.what() << std::endl;
    } catch (...) { // non-standard exceptions
        std::cerr << RED << "FAIL: enknown exception type." << RES << std::endl;
    }
    //  std::cout << "-----------------------------" << std::endl << std::endl;
     std::cout << "__________________________________________________" << std::endl << std::endl;
}


int main() {
    //vector
    std::vector<int> myVector = {10, 20, 30, 40, 50};
    testContainer(myVector, 30, "std::vector (value exists)"); // OK
    testContainer(myVector, 10, "std::vector (first element)"); // OK
    testContainer(myVector, 50, "std::vector (last element)"); // OK
    testContainer(myVector, 99, "std::vector (value missing)"); // KO

    // list
    std::list<int> myList = {1, 2, 3, 4, 5, 3}; // Contains duplicate '3'
    testContainer(myList, 3, "std::list (value exists)"); // sHOULD find first '3'
    testContainer(myList, 1, "std::list (first element)"); //OK
    testContainer(myList, 5, "std::list (value before duplicate)"); // OK
    testContainer(myList, -5, "std::list (value missing)"); // KO

    // Degue = double ended queue (allows insert & del at both ends,
    // not alloced on contiguous mem locations => more efficient than vectors)
    std::deque<int> myDeque = {100, 200, 300};
    testContainer(myDeque, 200, "std::deque (value exists)"); // OK
    testContainer(myDeque, 400, "std::deque (value missing)"); // KO

    // empty vector & list
    std::vector<int> emptyVector;
    testContainer(emptyVector, 1, "Empty std::vector"); // KO

    std::list<int> emptyList;
    testContainer(emptyList, 0, "Empty std::list"); // KO

    return 0;
}