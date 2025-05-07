#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat Consturctor call" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy Constructor call" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &copy) {
	std::cout << "WrongCat copy Assigment Operator call" << std::endl;
	if ( this != &copy)
		this->type = copy.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor call" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "SHHHHHHHHHHHHHHHHHHHHHH" << std::endl;
}
