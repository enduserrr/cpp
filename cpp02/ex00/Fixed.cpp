/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:25:27 by asalo             #+#    #+#             */
/*   Updated: 2024/09/19 11:36:21 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractBitCount = 8;

Fixed::Fixed() : fixedPointNbr(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment constructor called\n";
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Deconstructor called\n";
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (fixedPointNbr);
}

void Fixed::setRawBits(int const raw) {
	fixedPointNbr = raw;
}
