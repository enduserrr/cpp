/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:07:31 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 09:23:15 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

// class Dog: virtual public Animal
// {
//     private:
//         Brain *_brain;

//     public:
//         Dog();
//         Dog(Dog const &copy);
//         ~Dog();

//         void    operator=(Dog const &dog);
//         void    makeSound() const;
// 		void	setIdea(std::string idea);
// 		std::string	getIdea(size_t i);
// };

class Dog : public Animal
{
	private:
		Brain	*attribute;

	public:
		Dog();
		Dog(Dog const &copy);
		Dog& operator=(Dog const &copy);
		~Dog();

	void	makeSound() const;
	Brain	*getBrain() const;
};

#endif
