/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:08:21 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 09:22:08 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal Constructor call" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor call" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy Constructor call" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal &copy) {
	std::cout << "Animal copy Assignement Operator call" << std::endl;
	if ( this != &copy)
		this->type = copy.type;
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "AYO!!" << std::endl;
}

std::string	Animal::getType() const {
	return (this->type);
}

void	Animal::setType(std::string str) {
	this->type = str;
}

void	Animal::printAddress() const {
	std::cout << this << std::endl;
}
