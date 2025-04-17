/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:04:42 by asalo             #+#    #+#             */
/*   Updated: 2025/04/15 10:40:20 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Base.hpp"
#define WB "\033[1;97m"
#define RES "\033[0m"

int main() {
    // Seed random number gen
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Test with pointers
    std::cout << WB << "Testing with pointers:" << RES << std::endl;
    for (int i = 0; i < 4; i++) {
        Base* ptr = generate();
        std::cout << "Object " << i + 1 << ": ";
        identify(ptr);
        delete ptr;
    }

    // Test with references
    std::cout << WB << "\nTesting with references:" << RES << std::endl;
    for (int i = 0; i < 4; i++) {
        Base* ptr = generate();
        std::cout << "Object " << i + 1 << ": ";
        identify(*ptr);
        delete ptr;
    }

    // Comparison of pointer and reference
    std::cout << WB << "\nPointer vs Reference" << RES << std::endl;
    Base* testPtr = generate();
    std::cout << "Pointer identify: ";
    identify(testPtr);
    std::cout << "Reference identify: ";
    identify(*testPtr);

    // Known type verification
    std::cout << WB << "\nKnown type verification" << RES << std::endl;
    A aObj;
    B bObj;
    C cObj;
    std::cout << "Known A object - pointer: ";
    identify(&aObj);
    std::cout << "Known A object - reference: ";
    identify(aObj);
    std::cout << "Known B object - pointer: ";
    identify(&bObj);
    std::cout << "Known B object - reference: ";
    identify(bObj);
    std::cout << "Known C object - pointer: ";
    identify(&cObj);
    std::cout << "Known C object - reference: ";
    identify(cObj);

    // Null pointer handling
    std::cout << WB << "\nNull pointer handling" << RES << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Null pointer identify: ";
    identify(nullPtr);

    delete testPtr;

    return 0;
}
