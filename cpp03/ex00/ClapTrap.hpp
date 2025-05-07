#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &copy);

		void	Attack (std::string const &target);
		void	takeDamage (unsigned int amount);
		void	beRepaired (unsigned int amount);

		std::string getName();
        unsigned int getHitpoints();
        unsigned int getEnergyPoints();
        unsigned int getAttackDamage();

        void	setName(std::string name);
        void	setHitpoints(unsigned int hitpoints);
        void	setEnergyPoints(unsigned int energyPoints);
        void	setAttackDamage(unsigned int attackDamage);
};

#endif
