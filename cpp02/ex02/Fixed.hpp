/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:57:54 by asalo             #+#    #+#             */
/*   Updated: 2024/10/11 16:57:56 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

# define GC     "\033[3;90m"
# define RES    "\033[0m"

/**
 * @brief   Overloading an operator:
 *
 *          Comparison & arithmetic operators:
 *
 *          Static member funcs (min & max):
*/

class Fixed
{
    private:
        int                 _rawBits;
        static const int    _bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int int_nb);
        Fixed(const float float_nb);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        Fixed   &operator=(Fixed const &fixed);

        bool    operator>(Fixed const &fixed) const;
        bool    operator<(Fixed const &fixed) const;
        bool    operator>=(Fixed const &fixed) const;
        bool    operator<=(Fixed const &fixed) const;
        bool    operator==(Fixed const &fixed) const;
        bool    operator!=(Fixed const &fixed) const;

        Fixed   operator+(Fixed const &fixed);
        Fixed   operator-(Fixed const &fixed);
        Fixed   operator*(Fixed const &fixed);
        Fixed   operator/(Fixed const &fixed);

        Fixed   operator++();
        Fixed   operator++(int);
        Fixed   operator--();
        Fixed   operator--(int);

        static  Fixed const &min(Fixed const &a, Fixed const &b);
        static  Fixed const &max(Fixed const &a, Fixed const &b);
        static  Fixed &min(Fixed &a, Fixed &b);
        static  Fixed &max(Fixed &a, Fixed &b);
};

std::ostream    &operator<<(std::ostream &stream, Fixed const &fixed);

#endif
