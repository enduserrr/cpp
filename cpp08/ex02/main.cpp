/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:15:41 by asalo             #+#    #+#             */
/*   Updated: 2025/04/22 14:52:44 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define WB      "\033[1;97m"
#define RES     "\033[0m"
#define GREY_B  "\033[1;90m"


int main() {
    std::cout << WB << "# MUTANTSTACK" << RES GREY_B << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << RES << "Prev: " << GREY_B << mstack.top() << std::endl;
    mstack.pop();
    std::cout << RES << "Size: " << GREY_B << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(11);
    mstack.push(99);
    mstack.push(2);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "__________________________________________________________" << std::endl;
    std::cout << WB << "# LIST FOR REFERENCE" << RES GREY_B << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << RES << "Prev: " << GREY_B << list.back() << std::endl;
    list.pop_back();
    std::cout << RES << "Size: " << GREY_B << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    list.push_back(11);
    list.push_back(99);
    list.push_back(2);
    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();
    ++lit;
    --lit;

    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}