/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:50:35 by asalo             #+#    #+#             */
/*   Updated: 2025/04/19 13:27:48 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Iter.hpp"
#include <iostream>

#define REV_BLD_GREY    "\033[1;90;107m"
#define RES             "\033[0m"

static void	plusTen(int &a)
{
	a += 10;
}

static void	upperCase(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::string str[] = {"this", "is", "truly", "it,", "dang"};

	std::cout << REV_BLD_GREY << "\nBEFORE ITER:" << RES << std::endl;
	std::cout << "Int array= ";
	for (size_t i = 0; i < 5; i++)
		std::cout << arr[i] << "|";
	std::cout << std::endl;
	std::cout << "String array: ";
	for (size_t i = 0; i < 5; i++)
		std::cout << str[i] << " ";
	std::cout << std::endl;
	iter(arr, 5, plusTen);
	iter(str, 5, upperCase);
	std::cout << REV_BLD_GREY << "\nAFTER ITER:" << RES << std::endl;
	std::cout << "Int array= ";
	for (size_t i = 0; i < 5; i++)
		std::cout << arr[i] << "|";
	std::cout << std::endl;
	std::cout << "String array: ";
	for (size_t i = 0; i < 5; i++)
		std::cout << str[i] << " ";
	return (0);
}