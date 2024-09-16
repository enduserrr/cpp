/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:45:34 by asalo             #+#    #+#             */
/*   Updated: 2024/09/16 09:45:40 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define WB "\033[1;97m"
#define RES   "\033[0m"

/**
 * @brief   Reference is
 */

int main() {
    std::string str;
    str = "HI THIS IS BRAIN";

    std::string *strPtr;
    strPtr = &str;
    std::string& strRef = str;
    std::cout << WB << "ADDRESS:" << RES << std::endl;
    std::cout << "str: " << &str << std::endl;
    std::cout << "ptr: " << &strPtr << std::endl;
    std::cout << "ref: " << &strRef << std::endl;
    std::cout << WB << "VALUE:" << RES << std::endl;
    std:: cout << "str: " << str << std::endl;
    std:: cout << "ptr: " << *strPtr << std::endl;
    std:: cout << "ref: " << strRef << std::endl;
}
