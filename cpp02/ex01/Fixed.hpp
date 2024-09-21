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

#include <iostream>

class Fixed
{
    private:
        int _fixed_point_number; /*private var names with "_"*/
        static const int    _fract_bits_count;
    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed& other);
        Fixed &operator = (const Fixed &other);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const Raw); /*why const after data type*/
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator << (std::ostream &os, Fixed const &fixed);

#endif
