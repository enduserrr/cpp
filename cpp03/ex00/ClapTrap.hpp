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

# define GC     "\033[3;90m"
# define WB     "\033[1;97m"
# define GB     "\033[1;92m"
# define RB     "\033[1;91m"
# define RES    "\033[0m"

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
		ClapTrap& operator=( ClapTrap &copy ); // copy operator
		~ClapTrap( void );
		void attack ( const std::string& target );
		void takeDamage ( unsigned int amount );
		void beRepaired ( unsigned int amount );
};

#endif
