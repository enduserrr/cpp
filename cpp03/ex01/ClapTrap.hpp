/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:24:28 by asalo             #+#    #+#             */
/*   Updated: 2024/12/28 11:24:31 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

/**
 * @brief	'Protected' class members can be accessed by the class it self &
 *			it's derived child processes.
 *
 *			Unlike 'Private', 'Protected' members are inherited and accessible for
 *			derived classes while remaining inaccessible to external code.
*/
class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src); // copy constructor
		~ClapTrap( void );

		ClapTrap &operator=(const ClapTrap &copy); // copy operator

		void	Attack (std::string const &target);
		void	takeDamage (unsigned int amount);
		void	beRepaired (unsigned int amount);

		std::string getName();
        unsigned int getHitpoints();
        unsigned int getEnergyPoints();
        unsigned int getAttackDamage();

        void	setName(std::string name);
        void	setHitpoints(unsigned int hitpoints);
        void	setEnergyPoints(unsigned int energyPoints);
        void	setAttackDamage(unsigned int attackDamage);
};

#endif
