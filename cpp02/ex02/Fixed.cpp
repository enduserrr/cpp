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

Fixed::Fixed(const Fixed &f)
{
	std::cout << GC << "Copy constructor call" << RES << std::endl;
	*this = f;
}

Fixed	&Fixed::operator=(const Fixed &f2)
{
	std::cout << GC << "Assignement operator call" << RES << std::endl;
	this->setRawBits(f2.getRawBits());
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

std::ostream	&operator<<(std::ostream &stream, Fixed const &f)
{
	stream << f.toFloat();
	return (stream);
}

bool	Fixed::operator>(Fixed const &f) const
{
	if (this->_rawBits > f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &f) const
{
	if (this->_rawBits < f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &f) const
{
	if (this->_rawBits >= f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &f) const
{
	if (this->_rawBits <= f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &f) const
{
	if (this->_rawBits == f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &f) const
{
	if (this->_rawBits != f.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const &f)
{
	this->_rawBits += f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator-(Fixed const &f)
{
	this->_rawBits -= f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &f)
{
	this->_rawBits = (this->toFloat() * f.toFloat()) * (1 << _bits);
	return (*this);
}

Fixed	Fixed::operator/(Fixed const &f)
{
	this->_rawBits = (this->toFloat() / f.toFloat()) * (1 << _bits);
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
