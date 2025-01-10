/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:22:26 by asalo             #+#    #+#             */
/*   Updated: 2024/12/28 11:22:28 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ScavTrap scav1("Guy");
    ScavTrap scav2("Dude");

    std::cout << std::endl;
    scav2.guardGate();
    std::cout << std::endl;

    scav1.Attack(scav2.getName());
    scav2.takeDamage(scav1.getAttackDamage());

    std::cout << "\n" << scav1.getName() << " has " << scav1.getHitpoints() << " hit points left." << std::endl;
    std::cout << scav2.getName() << " has " << scav2.getHitpoints() << " hit points left." << std::endl;
    return (0);
}
