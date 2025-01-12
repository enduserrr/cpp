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
 * @brief		Un-instantiable Class: A class that can't be instantiated directly.
 *				They are called abstract classes to implement all of it's pure virtual
 *				functions (remains abstract as an object(an instance) can't be created).
 *
 *				To make a class un-instantiable at least one of the
 *				member functions must be pure virtual.
 *
 *				Pure Virtual: A function declared with = 0 in a base class
 *				that must be implemented by derived classes.
 *
 *				Deep Copy: An object created by copying data of all variables,
 *				similar memory resources allocated, with the same values to the object.
 *				Need to explicitly define the copy constructor and assign dynamic memory.
 *				Also, required to dynamically allocate memory to the variables in the other constructors.
 *
 *				Virtual: declares the function as overridable in derived classes.
 *				Pure Virtual: declares the function as mandatory to override in derived classes.
 */

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string getType() const;
	void setType(std::string);
	void printAddress() const;
};
#endif
