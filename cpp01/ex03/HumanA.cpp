#include "HumanA.hpp"

HumanA::HumanA(std::string n , Weapon& a) : _name(n) , _weapon(a) {}

void HumanA:: Attack()
{
    std:: cout << _name << " attacks with their " << _weapon.GetType() << std:: endl;
}
