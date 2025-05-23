#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

# define GC     "\033[3;90m"
# define RES    "\033[0m"

/**
 * @brief   Orthodox canonical class form consists of: default constructor,
 *          copy construtor, assignment operator & destructor.
 *
 *          Copy Constructor: creates a new object as a copy of an existing obejct.
 *          (Creates and constructs a new instance of the class).
 *
 *          Assignment Operator: copies the contents of already existing object
 *          into another existing object (both are already constructed).
 *          Static member funcs (min & max):
 *
 *          Overloaded Operator:
 *          Performins specified actions (like incrementing, calculations etc)
 *          to an instances of the class.
 *          (e.g. add _raw_Bits of current instance to the _rawBits of the Fixed object).
*/

class Fixed
{
    private:
        /* MEMBER VARIABLES */
        int                 _rawBits;
        static const int    _bits = 8;

    public:
        /* CONSTRUCTORS & DESTRUCTOR*/
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int int_nb);
        Fixed(const float float_nb);
        ~Fixed();

        /* MEMBER FUNCTION/METHODS */
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        /* OVERLOADED OPERATORS: */
        Fixed   &operator=(Fixed const &fixed);//Copy Assignement
        bool    operator>(Fixed const &fixed) const;//Comparison
        bool    operator<(Fixed const &fixed) const;//Comparison
        bool    operator>=(Fixed const &fixed) const;//Comparison
        bool    operator<=(Fixed const &fixed) const;//Comparison
        bool    operator==(Fixed const &fixed) const;//Comparison
        bool    operator!=(Fixed const &fixed) const;//Comparison
        Fixed   operator+(Fixed const &fixed);//Arithmetic
        Fixed   operator-(Fixed const &fixed);//Arithmetic
        Fixed   operator*(Fixed const &fixed);//Arithmetic
        Fixed   operator/(Fixed const &fixed);//Arithmetic
        Fixed   operator++();//Increment
        Fixed   operator++(int);//Increment
        Fixed   operator--();//Increment
        Fixed   operator--(int);//Increment

        /* STATIC MEMBER FUNCS */
        static  Fixed const &min(Fixed const &a, Fixed const &b);
        static  Fixed const &max(Fixed const &a, Fixed const &b);
        static  Fixed &min(Fixed &a, Fixed &b);
        static  Fixed &max(Fixed &a, Fixed &b);
};
/* STREAM INSERT */
std::ostream    &operator<<(std::ostream &stream, Fixed const &fixed);

#endif
