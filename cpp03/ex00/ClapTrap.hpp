/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:47:26 by asalo             #+#    #+#             */
/*   Updated: 2024/12/17 11:47:28 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

# define RED	"\033[1;91m"
# define RES	"\033[0m"

class ClapTrap
{
	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;

	public:
		ClapTrap( std::string name );
		ClapTrap( ClapTrap &src ); // copy constructor
		ClapTrap& operator=( ClapTrap &cop ); // copy operator
		~ClapTrap( void );
		void attack ( const std::string& target );
		void takeDamage ( unsigned int amount );
		void beRepaired ( unsigned int amount );
};

#endif
