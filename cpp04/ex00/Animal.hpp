/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:08:30 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 09:22:23 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

/**
 * @brief	Member function makeSound is virtual allowing specific calls
 *			when making a call to makeSound with a pointer to base class.
 *
 * @attention	Avoid errors:
 *				Deleting an object of polymorphic class type ‘Animal’
 *				which has a non-virtual destructor may cause undefined behavior
 *				[-Werror=delete-non-virtual-dtor].
 *
 *				=> The destructor should be declared as 'virtual'
 *				for deleting a pointer to a derived class.
 */

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal &copy);
		virtual ~Animal();

	void makeSound() const;
	std::string getType() const;
	void setType(std::string);
	void printAddress() const;
};
#endif
