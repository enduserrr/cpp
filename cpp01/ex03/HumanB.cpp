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

HumanB::HumanB(std::string n)
{
    this->_weapon = NULL;
    _name = n;
}
void HumanB::SetWeapon(Weapon &a)
{
    this->_weapon = &a;
}
void HumanB::Attack()
{
    if(!_weapon)
        std::cout << " No Weapon, unable to attack"<< std::endl;
    else
        std:: cout << _name << " attacks with their " << _weapon->GetType() << std::endl;
}
