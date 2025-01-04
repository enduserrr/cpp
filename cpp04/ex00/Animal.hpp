/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:08:30 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:08:32 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream> /*into cpp file?*/
# include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		void 	operator=(Animal const &animal);
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
};

#endif
