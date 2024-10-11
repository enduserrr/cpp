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
# define WB     "\033[1;97m"
# define GB     "\033[1;95m"
# define BB     "\033[1;96m"
# define YB     "\033[1;93m"
# define RB     "\033[1;91m"
# define RES    "\033[0m"

class Fixed
{
    private:
        int                 _rawBits;
        static const int    _bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &f);
        Fixed(const int int_nb);
        Fixed(const float float_nb);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        Fixed   &operator=(Fixed const &f2);

        bool    operator>(Fixed const &f) const;
        bool    operator<(Fixed const &f) const;
        bool    operator>=(Fixed const &f) const;
        bool    operator<=(Fixed const &f) const;
        bool    operator==(Fixed const &f) const;
        bool    operator!=(Fixed const &f) const;

        Fixed   operator+(Fixed const &f);
        Fixed   operator-(Fixed const &f);
        Fixed   operator*(Fixed const &f);
        Fixed   operator/(Fixed const &f);

        Fixed   operator++();
        Fixed   operator++(int);
        Fixed   operator--();
        Fixed   operator--(int);

        static  Fixed const &min(Fixed const &a, Fixed const &b);
        static  Fixed const &max(Fixed const &a, Fixed const &b);
        static  Fixed &min(Fixed &a, Fixed &b);
        static  Fixed &max(Fixed &a, Fixed &b);
};

std::ostream    &operator<<(std::ostream &stream, Fixed const &f);;

#endif
