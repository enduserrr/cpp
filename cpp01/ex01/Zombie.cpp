/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:42:46 by asalo             #+#    #+#             */
/*   Updated: 2024/08/15 08:42:47 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    name = "default";
    std::cout << "Constructor call" << std:: endl;
}

void Zombie::setname(std::string n) {
    name = n;
}

Zombie::Zombie(std::string n) {
    name= n;
    std::cout << "Constructor call" << std:: endl;
}

Zombie::~Zombie() {
    std::cout << "Destructor call" << std:: endl;
}

void Zombie::announce() {
    std::cout << name <<": BraiiiiiiinnnzzzZ..."<< std:: endl;
}
