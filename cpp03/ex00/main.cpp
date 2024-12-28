/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:44:27 by asalo             #+#    #+#             */
/*   Updated: 2024/12/17 11:46:40 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");
	claptrap.attack("the foe");
	claptrap.takeDamage(2);
	claptrap.beRepaired(2);
	return (0);
}
