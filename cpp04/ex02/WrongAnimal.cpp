/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:02:38 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 12:02:41 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal Constructor call" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor call" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal copy Constructor call" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	std::cout << "WrongAnimal copy Assigment Operator call" << std::endl;
	if ( this != &copy)
		this->type = copy.type;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "OOOOOEEEEEOEOEOEOEO" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}

void WrongAnimal::setType(std::string str) {
	this->type = str;
}

void WrongAnimal::printAddress() const {
	std::cout << this << std::endl;
}
