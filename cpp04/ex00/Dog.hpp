#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &copy);
		Dog &operator=(Dog const &copy);
		~Dog();

	virtual void	makeSound() const;
};

#endif
