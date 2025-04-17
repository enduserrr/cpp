/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:50:35 by asalo             #+#    #+#             */
/*   Updated: 2025/04/17 12:06:36 by asalo            ###   ########.fr       */
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
	std::string str[] = {"test", "case", "for", "42", "kocaeli"};

	std::cout << REV_BLD_GREY << "#**************#" << RES << std::endl;
	std::cout << "Before iter :" << std::endl;
	std::cout << "Integer array	= " << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cout << arr[i] << " " << std::endl;
	std::cout << std::endl;
	std::cout << "String array = " << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cout << str[i] << " " << std::endl;
	std::cout << std::endl;
	std::cout << REV_BLD_GREY << "#**************#" << RES << std::endl;
	iter(arr, 5, plusTen);
	iter(str, 5, upperCase);
	std::cout << "After iter :" << std::endl;
	std::cout << "Integer array = " << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cout << arr[i] << " " << std::endl;
	std::cout << std::endl;
	std::cout << "String array = " << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cout << str[i] << " " << std::endl;
	std::cout << std::endl;
	std::cout << REV_BLD_GREY << "#**************#" << RES << std::endl;
	return (0);
}