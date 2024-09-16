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
    this->W = NULL;
    name = n;
}
void HumanB::setWeapon(Weapon &a) {
    this->W = &a;
}
void HumanB::attack() {
    if(!W) {
        std::cout << " No Weapon, unable to attack"<< std::endl;
    }
    else {
        std:: cout << name << " attacks with their " << W->getType() << std::endl;
    }
}
