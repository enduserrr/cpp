/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:02:07 by asalo             #+#    #+#             */
/*   Updated: 2024/09/16 10:02:09 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Weapon.hpp"

Weapon::Weapon(std::string a)
{
    this->_type = a;
}

Weapon:: ~Weapon() {}

std::string& Weapon::GetType()
{
    std::string& t = _type;
    return(t);
}

void Weapon::SetType(std::string str)
{
  this->_type = str;
}
