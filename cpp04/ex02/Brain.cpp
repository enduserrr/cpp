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
	std::cout << "Brain creation done" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->setIdeas("");
	}
}

Brain::~Brain() {
	std::cout << "Brain destruction done" << std::endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy created" << std::endl;
	for(int i = 0; i < 100 ; i++)
		_ideas[i] = copy._ideas[i];
}

Brain &Brain::operator=(const Brain &copy) {
	std::cout << "Brain copy Assigment call" << std::endl;

	if (this != &copy)
		return (*this);
	for(int i = 0; i < 100 ;i++)
		this->_ideas[i] = copy._ideas[i];
	return (*this);
}

std::string const *Brain::getIdeas() const {
    return (_ideas);
}

void Brain::setIdeas(std::string idea) {
    if (idea.empty())
        idea = "";
    for (int i = 0; i < 100;) {
		if (_ideas[i].empty()) {
			_ideas[i] = idea;
			return ;
		} else {
			i++;
		}
	}
}
