/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:24:29 by asalo             #+#    #+#             */
/*   Updated: 2024/10/12 15:25:17 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

# define GC     "\033[3;90m"
# define RES    "\033[0m"

/**
 * @brief   Orthodox canonical class form consists of: default constructor,
 *          copy construtor, assignment operator & destructor.
 *
 *          Copy constructor: creates a new object as a copy of an existing obejct.
 *          (Creates and constructs a new instance of the class).
 *
 *          Assignment operator: copies the contents of already existing object
 *          into another existing object (both are already constructed).
*/
class Fixed
{
    private:
        int                 _rawBits;
        static const int    _bits = 8;

    public:
        Fixed();
        Fixed(const Fixed &fixed);
        ~Fixed();

        Fixed &operator=(const Fixed &fixed);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
