/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:09:00 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:09:01 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	this->_type ="undefined";
	std::cout << "WrongAnimal Constructor call" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal Destructor call" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) {
	this->_type = copy._type;
	std::cout << "WrongAnimal Copy Constructor call" << std::endl;
}

void	WrongAnimal::operator=(WrongAnimal const &animal) {
	this->_type = animal._type;
	std::cout << "WrongAnimal operator call" << std::endl;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "MakeSound of a generic Wronganimal (choo choo)" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return (this->_type);
}
