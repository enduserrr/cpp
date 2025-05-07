#include "Fixed.hpp"

Fixed::Fixed( void ) :  _rawBits(0) {
    std::cout << GC << "Default constructor call" << RES << std::endl;
}

Fixed::~Fixed( void ) {
    std::cout << GC << "Destructor call" << RES << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << GC << "Copy constructor call" << RES << std::endl;
    *this = fixed;
}

Fixed   &Fixed::operator=(const Fixed &fixed2) {
    std::cout << GC << "Assignment operator call" << RES << std::endl;
    this->setRawBits(fixed2.getRawBits());
	return (*this);
}

int Fixed::getRawBits( void ) const {
    return (_rawBits);
}

void    Fixed::setRawBits(int const raw)/*test const after fixed*/ {
    this->_rawBits = raw;
}

Fixed::Fixed(const int intNb) {
    std::cout << GC << "Int constructor call" << RES << std::endl;
    this->_rawBits = (intNb << Fixed::_bits);
}

Fixed::Fixed(const float floatNb) {
    std::cout << GC << "Float constructor call" << RES << std::endl;
    this->_rawBits = std::roundf(floatNb * (1 << Fixed::_bits));
}

float   Fixed::toFloat( void ) const {
    return ((float)this->_rawBits / (float)(1 << Fixed::_bits));
}

int Fixed::toInt( void ) const {
    return (this->_rawBits >> Fixed::_bits);
}

std::ostream    &operator<<(std::ostream &stream, Fixed const &fixed) {
    stream << fixed.toFloat();
    return (stream);
}
