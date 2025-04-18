/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:44:27 by asalo             #+#    #+#             */
/*   Updated: 2025/04/18 20:18:39 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Base.hpp"
#include <exception>

Base* generate(void) {
    int choise = std::rand() % 3;
    switch (choise) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();

        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (p == nullptr) {
        std::cout << "it's a nullptr..." << std::endl;
        return ;
    }
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

//Could be without (void) as in c++ as unused expression is discarded automatically in c++
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (...) {}
}