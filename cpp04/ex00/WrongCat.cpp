/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:09:14 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:09:15 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
    this->_type = "WrongCat";
    std::cout << "WrongCat Constructor call" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal() {
    this->_type = copy._type;
}

WrongCat::~WrongCat( void ) {
    std::cout << "WrongCat Destructor call" << std::endl;
}

void    WrongCat::operator=(WrongCat const &cat) {
    if (this != &cat) {
        this->_type = cat._type;
        std::cout << "WrongCat Operator call" << std::endl;
    }
}

void    WrongCat::makeSound( void ) const {
    std::cout << "WrongCat soubnds (SWOOSH)" << std::endl;
}
