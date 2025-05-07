#include"Weapon.hpp"

Weapon::Weapon(std::string a)
{
    this->_type = a;
}

Weapon:: ~Weapon() {}

std::string& Weapon::GetType()
{
    std::string& t = _type;
    return(t);
}

void Weapon::SetType(std::string str)
{
  this->_type = str;
}
