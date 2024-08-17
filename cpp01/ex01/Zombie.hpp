/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:42:30 by asalo             #+#    #+#             */
/*   Updated: 2024/08/15 08:42:32 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define RED	"\033[1;91m"
# define RES	"\033[0m"

class Zombie
{
	private:
		std::string	_Name;

	public:
		Zombie();
		Zombie(std::string Name);
		~Zombie();
		void	announce(void) const;
};

Zombie	*newZombie(std::string Name);
void	randomChump(std::string Name);

#endif
