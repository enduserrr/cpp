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
	std::cout << "WrongAnimal created!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destroyed!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal Copy called!" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy) {
	std::cout << "WrongAnimal Copy assigment called!" << std::endl;
	if ( this != &copy)
		this->type = copy.type;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "I am a Wrong animal!" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}
