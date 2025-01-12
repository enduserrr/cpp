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
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy created" << std::endl;
}

Cat& Cat::operator=(const Cat &copy) {
	std::cout << "Cat copy Assigment Operator call" << std::endl;
	if ( this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "MIU MAU" << std::endl;
}
