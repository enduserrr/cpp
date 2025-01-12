/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:06:52 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 09:23:03 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy created" << std::endl;
}

Dog& Dog::operator=(const Dog &copy) {
	std::cout << "Dog copy Assigment Operator call" << std::endl;
	if ( this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "WOOF WOOF!" << std::endl;
}
