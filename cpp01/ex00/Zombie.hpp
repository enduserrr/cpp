/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:42:30 by asalo             #+#    #+#             */
/*   Updated: 2024/08/15 08:42:32 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string _Name;
    public:
        Zombie();
        ~Zombie(){};
        void    announce( void );
        std::string getname();
        void    setname(std::string Name);
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif
