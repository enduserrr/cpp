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
	std::cout << "Dog Constructor call" << std::endl;
	this->type = "Dog";
	this->attribute = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy Constructor call" << std::endl;
	attribute = new Brain(*copy.attribute);
}

Dog& Dog::operator=(const Dog &copy) {
	std::cout << "Dog copy Assigment Operator call" << std::endl;
	if ( this != &copy) {
		this->type = copy.type;
		if(attribute)
			delete this->attribute;
		this->attribute = new Brain(*copy.getBrain());
	}
	return (*this);
}

Dog::~Dog() {
	delete this->attribute;
	std::cout << "Dog Destructor call" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "MIU MAU!" << std::endl;
}

Brain* Dog::getBrain() const {
	return (this->attribute);
}
