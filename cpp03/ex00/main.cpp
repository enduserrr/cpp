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
