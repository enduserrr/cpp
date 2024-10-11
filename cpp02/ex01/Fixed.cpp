/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:44 by asalo             #+#    #+#             */
/*   Updated: 2024/09/21 11:14:03 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() :  _rawBits(0)
{
    std::cout << GC << "Default constructor call" << RES << std::endl;
}

Fixed::~Fixed()
{
    std::cout << GC << "Destructor call" << RES << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << GC << "Copy constructor call" << RES << std::endl;
    *this = fixed;
}

Fixed   &Fixed::operator=(const Fixed &fixed2)/*test const after fixed*/
{
    std::cout << GC << "Assignement operator call" << RES << std::endl;
    this->setRawBits(fixed2.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
    return (_rawBits);
}

void    Fixed::setRawBits(int const raw)/*test const after fixed*/
{
    this->_rawBits = raw;
}

Fixed::Fixed(const int intNb)
{
    std::cout << GC << "Int constructor call" << RES << std::endl;
    this->_rawBits = (intNb << Fixed::_bits);
}

Fixed::Fixed(const float floatNb)
{
    std::cout << GC << "Float constructor call" << RES << std::endl;
    this->_rawBits = std::roundf(floatNb * (1 << Fixed::_bits));
}

float   Fixed::toFloat(void) const
{
    return ((float)this->_rawBits / (float)(1 << Fixed::_bits));
}

int Fixed::toInt(void) const
{
    return (this->_rawBits >> Fixed::_bits);
}

std::ostream    &operator<<(std::ostream &strm, Fixed const &fixed)
{
    strm << fixed.toFloat();
    return (strm);
}
