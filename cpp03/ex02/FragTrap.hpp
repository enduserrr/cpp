/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:42:32 by asalo             #+#    #+#             */
/*   Updated: 2025/01/07 12:42:34 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

/**
 * @brief	Virtual inheritance ensures that a derived class inheriting from multiple
 *			base classes, only one shared instance of a common base class is created.
 *			Eliminates redundancy and ambiguity in accessing the base class
 *			and ensures destructors are called correctly and only once.
*/
class FragTrap: virtual public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		FragTrap &operator=(const FragTrap &copy);
		~FragTrap();

		void Attack(std::string const &target);

		void highFiveGuys();
};

#endif
