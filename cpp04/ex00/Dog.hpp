/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:07:31 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:07:33 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: virtual public Animal
{
    public:
        Dog( void );
        Dog(Dog const &copy);
        ~Dog( void );
        void    operator=(Dog const &dog);
        void    makeSound( void ) const;
};

#endif
