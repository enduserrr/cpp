/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:42:46 by asalo             #+#    #+#             */
/*   Updated: 2024/08/15 08:42:47 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
	: _Name("Zombie") {
	return ;
}

Zombie::Zombie(std::string name)
	: _Name(name) {
	return ;
}

Zombie::~Zombie() {
	std::cout << _Name << " is dead" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
