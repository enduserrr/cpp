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
 *
 *				To make a class un-instantiable at least one of the
 *				member functions must be pure virtual.
 *
 *				Pure Virtual: A function declared with = 0 in a base class
 *				that must be implemented by derived classes.
 *
 *				Un-instantiable Class: A class that can't be instantiated directly.
 *				They are called abstract classes to implement all of it's pure virtual
 *				functions (remains abstract as an object(an instance) can't be created).
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

	virtual void makeSound() const = 0;/*pure virtual*/
	std::string getType() const;
	void setType(std::string);
	void printAddress() const;
};
#endif
