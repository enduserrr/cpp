/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:26:32 by asalo             #+#    #+#             */
/*   Updated: 2024/12/28 11:26:34 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->setName( name );
	this->setHitPoints( 100 );
	this->setEnergyPoints( 100 );
	this->setAttackDamage( 30 );
	std::cout << WB << "FragTrap " << GC << name << " constructed" << RES << std::endl;

}

FragTrap::FragTrap(FragTrap &src) : ClapTrap(src) {
	*this = src;
}

FragTrap &FragTrap::operator=(ClapTrap &rhs) {
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << WB << "FragTrap " << GC << this->getName() << " requests a high five!" << RES << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << WB << "FragTrap " << GC << this->getName() << " is destructed!" << RES << std::endl;
}
