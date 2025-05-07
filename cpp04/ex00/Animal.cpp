#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal Constructor call" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor call" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy Constructor call" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal &copy) {
	std::cout << "Animal copy Assigment call" << std::endl;
	if ( this != &copy)
		this->type = copy.type;
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "AYO!" << std::endl;
}

std::string	Animal::getType() const {
	return (this->type);
}

void	Animal::setType(std::string str) {
	this->type = str;
}
