/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:03:30 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 12:03:32 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat Consturctor call" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy Constructor call" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &copy) {
	std::cout << "WrongCat copy Assigment operator call" << std::endl;
	if ( this != &copy)
		this->type = copy.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor call" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "invalid cat sounds" << std::endl;
}
