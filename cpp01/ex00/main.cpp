/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:42:08 by asalo             #+#    #+#             */
/*   Updated: 2024/08/15 08:42:10 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int nbr;

    std::cout << "Enter a number of Zombies to create (int): ";
    std::cin >> nbr;
    std::cin.ignore();
    if (std::cin.fail()) {
        std::cout << "Incorrect input"
        << std::endl;
    } else {
        std::string name[nbr];
        for (int i = 0; i < nbr;) {
            std::cout << "Name of the Zombie # "
            << i + 1 << "/" << nbr << ": ";
            getline(std::cin, name[i]);
            i++;
        }
        std::cout
        << "-----------------------------------------------------------"
        << std::endl;
        randomChump(name[rand() % nbr]);
    }
    return (0);
}
