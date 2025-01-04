/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:13:33 by asalo             #+#    #+#             */
/*   Updated: 2024/09/21 11:13:35 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define GC     "\033[3;90m"
# define RES    "\033[0m"

class   Fixed
{
    private:
        int                 _rawBits;
        static const int    _bits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int intNb);
        Fixed(const float floatNb);

        Fixed   &operator=(const Fixed &fixed);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream    &operator<<(std::ostream &stream, Fixed const &fixed);

#endif
