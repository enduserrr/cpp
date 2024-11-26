/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:58:10 by asalo             #+#    #+#             */
/*   Updated: 2024/10/11 16:58:13 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << GC << "Default constructor call" << RES << std::endl;
}

Fixed::~Fixed()
{
    std::cout << GC << "Default destructor call" << RES << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << GC << "Copy constructor call" << RES << std::endl;
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << GC << "Assignment operator call" << RES << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

Fixed::Fixed(const int integer)
{
	std::cout << GC << "Int constructor call" << RES << std::endl;
	this->setRawBits(integer << Fixed::_bits);
}

Fixed::Fixed(const float floating_point)
{
	std::cout << GC << "Float constructor call" << RES << std::endl;
	this->setRawBits(std::roundf(floating_point * (1 << Fixed::_bits)));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_bits);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	if (this->_rawBits > fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	if (this->_rawBits < fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	if (this->_rawBits >= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	if (this->_rawBits <= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	if (this->_rawBits == fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	if (this->_rawBits != fixed.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const &fixed)
{
	this->_rawBits += fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator-(Fixed const &fixed)
{
	this->_rawBits -= fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &fixed)
{
	this->_rawBits = (this->toFloat() * fixed.toFloat()) * (1 << _bits);
	return (*this);
}

Fixed	Fixed::operator/(Fixed const &fixed)
{
	if (fixed.getRawBits() == 0){
		std::cerr << "Can't divide by zero..." << std::endl;
		return Fixed(0);
	}
	this->_rawBits = (this->toFloat() / fixed.toFloat()) * (1 << _bits);
	return (*this);
}

Fixed	Fixed::operator++()
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}
