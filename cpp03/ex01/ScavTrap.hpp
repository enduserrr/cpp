/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:23:33 by asalo             #+#    #+#             */
/*   Updated: 2024/12/28 11:24:12 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @brief	Virtual inheritance ensures that a derived class inheriting from multiple
 *			base classes, only one shared instance of a common base class is created.
 *			Eliminates redundancy and ambiguity in accessing the base class
 *			and ensures destructors are called correctly and only once.
*/
class ScavTrap: virtual public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap&st);
		ScavTrap &operator=(const ScavTrap &sv);
		~ScavTrap();

		void guardGate();
		void Attack(std::string const & target);
};

#endif
