/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:08:45 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:08:48 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal( void );
        WrongAnimal(WrongAnimal const &copy);
        virtual ~WrongAnimal( void );
        void    operator=(WrongAnimal const &animal);
        void    makeSound( void ) const;
        std::string getType( void ) const;
};

#endif
