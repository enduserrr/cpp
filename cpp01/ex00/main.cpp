/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:42:08 by asalo             #+#    #+#             */
/*   Updated: 2024/08/15 08:42:10 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	std::cout << RED << "Zombies (in stack)" << RES << std::endl;
	Zombie	z1("Zombie_The_1st");
	Zombie	z2("Zombie_The_2nd");
	Zombie	z3("Zombie_The_3rd");

	z1.Announce();
	z2.Announce();
	z3.Announce();
	randomChump("randomChump");

	std::cout << RED << "New Zombie (in heap)" << RES << std::endl;
	Zombie	*newZ;
	newZ = newZombie("newZombie");
	newZ->Announce();
	delete(newZ);

	return (0);
}
