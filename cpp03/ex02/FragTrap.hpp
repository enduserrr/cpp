/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:26:46 by asalo             #+#    #+#             */
/*   Updated: 2024/12/28 11:26:48 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap();

	public:
		FragTrap(std::string name);
		FragTrap(FragTrap &src);

		FragTrap	&operator=(ClapTrap &rhs);/*rhs?*/

		void	highFivesGuys( void );
		~FragTrap();
};

#endif
