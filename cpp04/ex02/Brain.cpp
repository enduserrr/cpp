/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:21:39 by asalo             #+#    #+#             */
/*   Updated: 2025/01/10 09:21:40 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain created!" << std::endl;
	this->setIdeas("");
}

Brain::~Brain() {
	std::cout << "Brain destroyed!" << std::endl;
}

Brain::Brain(const Brain &n) {
	std::cout << "Brain Copy called!" << std::endl;
	for(int i = 0; i < 100 ; i++)
		ideas[i] = n.ideas[i];
}

Brain &Brain::operator=(const Brain &n) {
	std::cout << "Brain Copy assigment called!\n";

	if ( this != &n )
		return *this;
	for(int i = 0; i < 100 ;i++)
		this->ideas[i] = n.ideas[i];
	return *this;
}

std::string const *Brain::getIdeas() const {
    return ideas;
}

void Brain::setIdeas(std::string idea) {
    if (idea.empty())
        idea = "zzzzzzz...zzzzzzz";
    for (int i = 0; i < 100; i++)
        ideas[i] = idea;
}
