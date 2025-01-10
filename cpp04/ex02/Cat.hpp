/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:07:53 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 09:22:40 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

// class Cat : virtual public Animal
// {
// 	private:
// 		Brain *_brain;

// 	public:
// 		Cat(void);
// 		Cat(Cat const &copy);
// 		~Cat(void);

// 		void operator=(Cat const &cat);
// 		void    makeSound() const;
// 		void	setIdea(std::string idea);
// 		std::string	getIdea(size_t i) const;
// };

class Cat : public Animal
{
	private:
		Brain	*attribute;

	public:
		Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &copy);
		~Cat();

	void makeSound() const;
	Brain *getBrain() const;
};

#endif
