/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:06:52 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:06:53 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) {
    this->_type = "dog";
    std::cout << "Dog Constructor call" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal() {
    this->_type = copy._type;
    std::cout << "Dog Copy Constructor call" << std::endl;
}

Dog::~Dog( void ) {
    std::cout << "Dog Destructor call" << std::endl;
}

void    Dog::operator=(Dog const &dog) {
    if (this != &dog) {
        this->_type = dog._type;
        std::cout << "Dog Operator Equal call" << std::endl;
    }
}

void    Dog::makeSound( void ) const {
    std::cout << "WOOF WOOF!" << std::endl;
}
