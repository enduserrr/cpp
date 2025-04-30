/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:27:08 by asalo             #+#    #+#             */
/*   Updated: 2025/04/30 17:37:45 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <iostream>

#define WB      "\033[1;97m"
#define RES     "\033[0m"
#define GREY_B  "\033[1;90m"

/**
 * @brief   Span class used as a container to store a fixed max number (N) of ints.
 *          Shortest Span = The smallest difference between any two nbs withing the span.
 *          Longest Span = The largest difference between any two nbs within the span.
 */
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


    std::cout << WB << "# ADD NUMBERS TO SPAN" << RES << std::endl;
    Span sp2(8); // Span with capacity for initial + added numbers
    sp2.addNumber(10);
    sp2.addNumber(11);
    sp2.addNumber(50);
    std::cout << GREY_B << "Before adding range" << RES << std::endl;
    std::cout << "Shortest Span: " << RES GREY_B << sp2.shortestSpan() << RES << std::endl;
    std::cout << "Longest Span: " << RES GREY_B << sp2.longestSpan() << RES << std::endl;
    std::cout << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    sp2.multiAdd(arr, arr + 5);
    std::cout << GREY_B << "After adding range" << RES << std::endl;
    std::cout << "Shortest Span: " << RES GREY_B << sp2.shortestSpan() << RES << std::endl;
    std::cout << "Longest Span: " << RES GREY_B << sp2.longestSpan() << RES << std::endl;
    std::cout << RES << "____________________________________________________" << std::endl;


    std::cout << WB << "# BIG SPAN" << RES << std::endl;
    try {
        Span bigSpan(100000);
        std::vector<int> toAdd;
        for (int i = 0; i < 99999; ++i) {
            toAdd.push_back(i);// More efficient than calling addNumber 11000 times
        }
        bigSpan.multiAdd(toAdd.begin(), toAdd.end());
        std::cout << "Shortest Span: " << RES GREY_B << bigSpan.shortestSpan() << RES << std::endl;
        std::cout << "Longest Span: " << RES GREY_B << bigSpan.longestSpan() << RES << std::endl;
        } catch (const std::exception& e) {
        std::cerr << "Error during Big span test: " << e.what() << std::endl;
    }
    std::cout << "____________________________________________________" << std::endl;

    return 0;
}