/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:03:16 by asalo             #+#    #+#             */
/*   Updated: 2024/09/16 10:03:20 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanB.hpp"

HumanB::HumanB(std::string n) {
    this->weapon = NULL;
    name = n;
}
void HumanB::setWeapon(Weapon &a) {
    this->weapon = &a;
}
void HumanB::attack() {
    if(!weapon) {
        std::cout << " No Weapon, unable to attack"<< std::endl;
    }
    else {
        std:: cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
}
