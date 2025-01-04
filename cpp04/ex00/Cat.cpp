/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:17:38 by asalo             #+#    #+#             */
/*   Updated: 2025/01/03 09:17:40 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) {
    this->_type = "cat";
    std::cout << "Cat Constructor call" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal() {
    this->_type = copy._type;
    std::cout << "Cat Copy Constructor call" << std::endl;
}

Cat::~Cat( void ) {
    std::cout << "Destructor call" << std::endl;
}

void    Cat::operator=(Cat const &cat) {
    if (this != &cat) {
        this->_type = cat._type;
        std::cout << "Cat Operator call" << std::endl;
    }
}

void    Cat::makeSound( void ) const {
    std::cout << "MEOW MEOW!" << std::endl;
}
