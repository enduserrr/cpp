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

int main()
{
    ClapTrap claptrap("enemy");
    ClapTrap claptrap1("sir");

    claptrap.Attack(claptrap1.getName());
    claptrap1.takeDamage(claptrap.getAttackDamage());
    claptrap1.beRepaired(3);

    return 0;
}
