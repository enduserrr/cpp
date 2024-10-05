/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:19:42 by asalo             #+#    #+#             */
/*   Updated: 2024/10/05 12:40:45 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl    Harl;

    Harl.Complain("debug");
    Harl.Complain("info");
    Harl.Complain("warning");
    Harl.Complain("error");
}
