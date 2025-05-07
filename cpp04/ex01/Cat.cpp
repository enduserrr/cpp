#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
	this->attribute = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat copy created" << std::endl;
	attribute = new Brain(*copy.attribute);
}

Cat& Cat::operator=(const Cat &copy) {
	std::cout << "Cat copy Assigment Operator call" << std::endl;
	if ( this != &copy) {
		this->type = copy.type;
		if(attribute)
			delete this->attribute;
		this->attribute = new Brain(*copy.getBrain());
	}
	return (*this);
}

Cat::~Cat() {
	delete this->attribute;
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "MIU MAU" << std::endl;
}

Brain* Cat::getBrain() const {
	return (this->attribute);
}
