#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Constructed" << std::endl;
    ScavTrap::setHitpoints(100);
    ScavTrap::setEnergyPoints(50);
    ScavTrap::setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " Constructed" << std::endl;
    ScavTrap::setHitpoints(100);
    ScavTrap::setEnergyPoints(50);
    ScavTrap::setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
    ScavTrap::setHitpoints(copy._hitPoints);
    ScavTrap::setEnergyPoints(copy._energyPoints);
    ScavTrap::setAttackDamage(copy._attackDamage);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
    std::cout << "ScavTrap assignment operator call" << std::endl;
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout <<"ScavTrap destructor call" << std::endl;
}

void ScavTrap::guardGate( void ) {
    if (this->getHitpoints() == 0)
        std::cout << "ScavTrap " << this->getName( ) << " is dead. Unable to Guard Gate" << std::endl;
    else
	    std::cout << "ScavTrap " << this->getName() <<" is Guarding the Gate" << std::endl;
}

void ScavTrap::Attack(std::string const &target) {
    if (this->getHitpoints() == 0 || this->getEnergyPoints() == 0) {
        std::cout << "ScavTrap " << this->getName() << " can't attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage" << std::endl;
    this->_energyPoints = this->_energyPoints - 1;
}
