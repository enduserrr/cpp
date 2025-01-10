/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:21:19 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 09:21:29 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# define BRAIN_NUMBER_IDEAS 100

# define BRAIN_NUMBER_IDEAS 100

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain( void );
		Brain( const Brain & );
		Brain& operator=( const Brain & );
		~Brain( void );

	std::string const	*getIdeas( void ) const;
	void				setIdeas( std::string );
};

#endif
