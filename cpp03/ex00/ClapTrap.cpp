/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:47:03 by asalo             #+#    #+#             */
/*   Updated: 2024/12/17 11:47:05 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) {
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
	std::cout << GC
	<< "============================================================="
	<< RES << std::endl;
	std::cout << GB << "ClapTrap constructor call" << RES << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << RB << "ClapTrap destructor call" << RES << std::endl;
	std::cout << GC
	<< "=============================================================="
	<< RES << std::endl;
}

ClapTrap::ClapTrap( ClapTrap &src ) {
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
}

ClapTrap	&ClapTrap::operator=( ClapTrap &copy ) {
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void	ClapTrap::attack ( const std::string &target ) {
	if (this->energyPoints > 0) {
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	}
}

void	ClapTrap::takeDamage ( unsigned int amount ) {
	if (this->energyPoints > 0) {
		this->hitPoints -= amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap" << this->name << " is out of energy!" << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->energyPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	}
}
