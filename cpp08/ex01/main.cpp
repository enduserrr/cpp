/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:27:08 by asalo             #+#    #+#             */
/*   Updated: 2025/04/22 09:04:14 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <iostream>

#define WB      "\033[1;97m"
#define RES     "\033[0m"
#define GREY_B  "\033[1;90m"

int main() {
    std::cout << WB << "# 5 SPANS" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest Span: " << RES GREY_B << sp.shortestSpan() << RES << std::endl;
    std::cout << "Longest Span: " << RES GREY_B << sp.longestSpan() << RES <<std::endl;
    std::cout << "____________________________________________________" << std::endl;


    std::cout << WB << "# A LOT OF SPANS" << RES << std::endl;
    Span largeSpan(10);
    for (int i = 0; i < 10; i++) {
        largeSpan.addNumber(i);
    }
    std::cout << "Shortest Span: " << RES GREY_B << largeSpan.shortestSpan() << RES << std::endl;
    std::cout << "Longest Span: " << RES GREY_B << largeSpan.longestSpan() << RES << std::endl;
    std::cout << "____________________________________________________" << std::endl;

    std::cout << WB << "# RANGE\n" << RES GREY_B;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; arr[i++];) {
        std::cout << arr[i] << " ";
    }
    std::cout << RES << "\n____________________________________________________" << std::endl;

    std::cout << WB << "# ADD TO SPAN\n" << RES;
    Span sp2(5);
    sp2.addRange(arr, arr + 5);
    std::cout << "Shortest Span: " << RES GREY_B << sp2.shortestSpan() << RES << std::endl;
    std::cout << "Longest Span: " << RES GREY_B << sp2.longestSpan() << RES << std::endl;
    std::cout << RES << "____________________________________________________" << std::endl;

    return 0;
}