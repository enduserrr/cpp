#include "Fixed.hpp"

Fixed::Fixed( void ) {
	this->_rawBits = 0;
	std::cout << GC << "Default constructor call" << RES << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << GC << "Copy constructor call" << RES << std::endl;
	*this = fixed;
}

Fixed::~Fixed( void ) {
	std::cout << GC << "Destructor call" << RES << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << GC << "Assignment operator call" << RES << std::endl;
	setRawBits(fixed.getRawBits());
	return (*this);
}

int Fixed::getRawBits( void ) const {
	std::cout << GC <<"getRawBits member func call" << RES << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}
