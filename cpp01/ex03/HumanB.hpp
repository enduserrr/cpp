/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:03:38 by asalo             #+#    #+#             */
/*   Updated: 2024/09/16 10:03:41 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB
{
    private:
        std:: string    _name;
        Weapon          *_weapon;
    public :
        HumanB(std:: string n);
        void Attack();
        void SetWeapon(Weapon &a);

};

#endif
