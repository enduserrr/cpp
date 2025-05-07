#include"HumanB.hpp"

HumanB::HumanB(std::string n)
{
    this->_weapon = NULL;
    _name = n;
}
void HumanB::SetWeapon(Weapon &a)
{
    this->_weapon = &a;
}
void HumanB::Attack()
{
    if(!_weapon)
        std::cout << " No Weapon, unable to attack"<< std::endl;
    else
        std:: cout << _name << " attacks with their " << _weapon->GetType() << std::endl;
}
