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

int main()
{
    Zombie *Z;
    int	N = 5;

    Z = zombieHorde(N,"Zombie");
    for (size_t i = 0; i < N; i++) {
      std::cout << "Horde: " << i << "_";
      Z[i].Announce();
    }
    delete[] Z;
}
