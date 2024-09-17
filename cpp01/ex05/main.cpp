/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:19:42 by asalo             #+#    #+#             */
/*   Updated: 2024/09/17 09:19:44 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl    Harl;

    Harl.complain("debug");
    Harl.complain("info");
    Harl.complain("warning");
    Harl.complain("error");
}
