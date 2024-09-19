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

Weapon::Weapon(std::string a) {
    this->type = a;
}

Weapon:: ~Weapon() {
}

std::string& Weapon::getType() {
    std::string& t = type;
    return(t);
}

void Weapon::setType(std::string str) {
  this->type = str;
}
