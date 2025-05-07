#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

// int main()
// {
//     std::cout << WB << "START:" << GB << std::endl;
// 	FragTrap frag1("FragTrap");
//     std::cout << RES << std::endl;
// 	frag1.Attack("a random enemy");
// 	frag1.takeDamage(12);
// 	frag1.beRepaired(12);
//     std::cout << frag1.getName() << " has " << frag1.getHitpoints() << " hit points left" << std::endl;
//     std::cout << std::endl;
// 	frag1.highFiveGuys();
//     std::cout << RB << std::endl;
// 	return (0);
// }

int main()
{
    std::cout << WB << "START:" << GB << std::endl;
    ClapTrap clap1("Guy");
    ScavTrap scav1("Dude");
    FragTrap frag1("Buddy");
    std::cout << RES << std::endl;

    scav1.guardGate();
    std::cout << std::endl;
    clap1.Attack(scav1.getName());
    scav1.takeDamage(clap1.getAttackDamage());
    std::cout << scav1.getName() << " has " << scav1.getHitpoints() << " hit points left" << std::endl;
    std::cout << std::endl;
    clap1.setAttackDamage(110);
    clap1.Attack(scav1.getName());
    scav1.takeDamage(clap1.getAttackDamage());
    frag1.highFiveGuys();
    std::cout << std::endl;
    clap1.Attack(frag1.getName());
    frag1.takeDamage(clap1.getAttackDamage());
    std::cout << RB << std::endl;
    return (0);
}
