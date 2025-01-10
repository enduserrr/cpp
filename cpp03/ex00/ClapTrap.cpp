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

ClapTrap::ClapTrap() : _name("Dude"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << name << " Constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
	std::cout << "ClapTrap " << _name << " copied to: " << src._name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
	std::cout << "ClapTrap " << copy._name << " is assigned to " << copy._name << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void	ClapTrap::Attack (const std::string &target) {
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no more energy" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no more hitpoints" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage" << std::endl;
	this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage (unsigned int amount) {
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead already" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage" << std::endl;
	if (this->_hitPoints < amount) {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is dead" << std::endl;
	} else {
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return ;
    }
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is out of hitpoints!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " got repaired for " << amount << " hit points" << std::endl;
    this->_energyPoints -= 1;
    this->_hitPoints += amount;
}

std::string ClapTrap::getName() {
    return _name;
}

unsigned int ClapTrap::getHitpoints() {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() {
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() {
    return _attackDamage;
}

void ClapTrap::setName(std::string name) {
    _name = name;
}

void ClapTrap::setHitpoints(unsigned int hitpoints) {
    _hitPoints = hitpoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    _attackDamage = attackDamage;
}
