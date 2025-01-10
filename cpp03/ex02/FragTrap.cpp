/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:42:20 by asalo             #+#    #+#             */
/*   Updated: 2025/01/07 12:42:22 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Constructed" << std::endl;
    this->setHitpoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " Constructed" << std::endl;
    this->setHitpoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &src) {
    FragTrap::setHitpoints(src._hitPoints);
    FragTrap::setEnergyPoints(src._energyPoints);
    FragTrap::setAttackDamage(src._attackDamage);
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
    std::cout << "FragTrap assignment operator call" << std::endl;
    if (this != &copy) {
        ClapTrap::operator=(copy);
    }
    return (*this);
}

FragTrap:: ~FragTrap() {
	std::cout << "FragTrap " << this->getName() << " destroyed" << std::endl;
}

void FragTrap:: Attack(std::string const &target) {
    if (this->getHitpoints() == 0 || this->getEnergyPoints() == 0)
    {
        std::cout<< this->getName() << " can't attack" << std::endl;
        return ;
    }
    std::cout<< this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage" << std::endl;
    this->_energyPoints = this->_energyPoints - 1;
}


void FragTrap:: highFiveGuys() {
    if (this->getHitpoints() == 0)
        std::cout << "FragTrap " << this->getName() << " is dead and does nothing" << std::endl;
    else
        std::cout << "FragTrap " << this->getName() << " is giving a high five!!!!" << std::endl;
}
