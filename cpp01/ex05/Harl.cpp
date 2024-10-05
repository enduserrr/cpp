/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:19:55 by asalo             #+#    #+#             */
/*   Updated: 2024/10/05 12:39:27 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::_debug( void )
{
    std::cout << WB << "\n[ DEBUG ]" << RES << std::endl;
    std::cout << GC << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RES << std::endl;
}

void    Harl::_info( void )
{
    std::cout << BB << "\n[ INFO ]" << RES << std::endl;
    std::cout << GC << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RES << std::endl;
}

void    Harl::_warning( void )
{
    std::cout << YB << "\n[ WARNING ]" << RES << std::endl;
    std::cout << GC << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RES << std::endl;
}

void    Harl::_error( void )
{
    std::cout << RB << "\n[ ERROR ]" << RES << std::endl;
    std::cout << GC << "This is unacceptable! I want to speak to the manager now." << RES << std::endl;
}

void Harl::Complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*f_ptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

    for(int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*f_ptr[i]) ();
            return ;
        }
    }
}
