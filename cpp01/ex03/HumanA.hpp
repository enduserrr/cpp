/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:03:02 by asalo             #+#    #+#             */
/*   Updated: 2024/09/16 10:03:03 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;
    public:
        HumanA(std::string n ,Weapon& weapon);
        void attack();
};

#endif
