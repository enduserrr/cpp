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

Zombie	*newZombie(std::string Name);
void	randomChump(std::string Name);

int	main(void) {
	std::cout << RED
    << "Zombies (in stack)" << RES << std::endl;
	Zombie	z1("Zombie_The_1st");
	Zombie	z2("Zombie_The_2nd");
	Zombie	z3("Zombie_The_3rd");
	z1.announce();
	z2.announce();
	z3.announce();
	randomChump("randomChump");
	// std::cout << std::endl;
	std::cout << RED
    << "new Zombies (in heap)" << RES << std::endl;
	Zombie	*new_z;
	new_z = newZombie("new_Zombie");
	new_z->announce();
	delete(new_z);
	return (0);
}
