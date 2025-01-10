/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:17:38 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 09:22:51 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor call" << std::endl;
	this->type = "Cat";
	this->attribute = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy Constructor call" << std::endl;
	attribute = new Brain(*copy.attribute);
}

Cat& Cat::operator=(const Cat &copy) {
	std::cout << "Cat copy Assigment Operator call" << std::endl;
	if ( this != &copy) {
		this->type = copy.type;
		if(attribute)
			delete this->attribute;
		this->attribute = new Brain(*copy.getBrain());
	}
	return (*this);
}

Cat::~Cat() {
	delete this->attribute;
	std::cout << "Cat Destructor call" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "MIU MAU!" << std::endl;
}

Brain* Cat::getBrain() const {
	return (this->attribute);
}
