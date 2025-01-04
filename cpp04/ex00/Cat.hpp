/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:07:53 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:07:55 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : virtual public Animal
{
	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);
		void operator=(Cat const &cat);
		void	makeSound(void) const;
};

#endif
