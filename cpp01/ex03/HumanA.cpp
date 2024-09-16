/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:02:44 by asalo             #+#    #+#             */
/*   Updated: 2024/09/16 10:02:46 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n , Weapon& a) : name(n) ,W(a) {
}

void HumanA:: attack() {
    std:: cout << name << " attacks with their " << W.getType() << std:: endl;
}
