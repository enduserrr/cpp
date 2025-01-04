/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:07:12 by asalo             #+#    #+#             */
/*   Updated: 2024/12/28 15:07:16 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) {
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap &src ) {
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
}

ClapTrap& ClapTrap::operator=( ClapTrap &cop ) {
	this->name = cop.name;
	this->hitPoints = cop.hitPoints;
	this->energyPoints = cop.energyPoints;
	this->attackDamage = cop.attackDamage;
	return (*this);
}

void ClapTrap::attack ( const std::string& target ) {
	if (this->energyPoints > 0) {
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	}
}

void ClapTrap::takeDamage ( unsigned int amount ) {
	if (this->energyPoints > 0) {
		this->hitPoints -= amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap" << this->name << " is out of energy!" << std::endl;
	}
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->energyPoints > 0) {
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	}
}

std::string ClapTrap::getName( void ) {
	return (this->name);
}

void ClapTrap::setName( std::string name ) {
	this->name = name;
}

int ClapTrap::getHitPoints( void ) {
	return (this->hitPoints);
}

void ClapTrap::setHitPoints( int hitPoints ) {
	this->hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints( void ) {
	return (this->energyPoints);
}

void ClapTrap::setEnergyPoints( int energyPoints ) {
	this->energyPoints = energyPoints;
}

int ClapTrap::getAttackDamage( void ) {
	return (this->attackDamage);
}

void ClapTrap::setAttackDamage( int attackDamage ) {
	this->attackDamage = attackDamage;
}
