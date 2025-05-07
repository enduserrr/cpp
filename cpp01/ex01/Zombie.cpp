#include "Zombie.hpp"

Zombie::Zombie() {
    _name = "default";
    std::cout << "Constructor call" << std:: endl;
}

void Zombie::Setname(std::string n) {
    _name = n;
}

Zombie::Zombie(std::string n) {
    _name = n;
    std::cout << "Constructor call" << std:: endl;
}

Zombie::~Zombie() {
    std::cout << "Destructor call" << std:: endl;
}

void Zombie::Announce() {
    std::cout << _name <<": BraiiiiiiinnnzzzZ..."<< std:: endl;
}
