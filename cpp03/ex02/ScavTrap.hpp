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

class ScavTrap : public ClapTrap {
	private:
		ScavTrap();

	public:
		ScavTrap( std::string name );
		~ScavTrap( void );
		ScavTrap( ScavTrap &src); // copy constructor
		ScavTrap& operator=( ScavTrap &cop); // copy operator
		void guardGate( void );
		void attack ( const std::string& target );
};

#endif
