/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:09:29 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:09:30 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
    public:
        WrongCat( void );
        WrongCat(WrongCat const &copy);
        ~WrongCat( void );
        void    operator=(WrongCat const &cat);/*deep copy/copy assignement operator*/
        void    makeSound( void ) const;
};

#endif
