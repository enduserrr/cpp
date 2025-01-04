/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:08:21 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:08:23 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) {
	this->_type ="undefined";
	std::cout << "Animal Constructor call" << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "Animal Destructor call" << std::endl;
}

Animal::Animal(Animal const &copy) {
	this->_type = copy._type;
	std::cout << "Animal Copy Constructor call" << std::endl;
}

void	Animal::operator=(Animal const &animal) {
	if (this != &animal)
	{
		this->_type = animal._type;
		std::cout << "Animal Operator call" << std::endl;
	}
}

void Animal::makeSound( void ) const {
	std::cout << "MakeSound of a generic anima (moo moo)l" << std::endl;
}

std::string	Animal::getType( void ) const {
	return (this->_type);
}
