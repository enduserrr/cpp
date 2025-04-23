/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:03 by asalo             #+#    #+#             */
/*   Updated: 2025/04/19 12:14:12 by asalo            #   ####.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define WB "\033[1;97m"
#define RES "\033[0m"
#define GREY_B "\033[1;90m"

#define MAX_VAL 50

template <typename T>
void printArrayInfo(const std::string& name, const Array<T>& arr) {
    std::cout << name << " [Size: " << arr.size() << "] = { ";
    if (arr.size() == 0) {
        std::cout << "(empty)";
    } else {
        for (unsigned int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
        }
    }
    std::cout << " }" << std::endl;
}


int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << RES << WB << "# DEFAULT CONSTRUCTION" << GREY_B << std::endl;
    Array<int> a0;
    printArrayInfo("a0", a0);
    std::cout << "__________________________________________________________" << std::endl;

    std::cout << RES << WB << "# SIZE CONSTRUCTION" << GREY_B << std::endl;
    Array<int> a1(5);
    for (unsigned int i = 0; i < a1.size(); ++i) {
        a1[i] = std::rand() % MAX_VAL;
    }
    printArrayInfo("a1", a1);

    Array<std::string> a_str(3);
    a_str[0] = "alpha";
    a_str[1] = "beta";
    a_str[2] = "gamma";
    printArrayInfo("a_str", a_str);
    std::cout << "__________________________________________________________" << std::endl;

    std::cout << RES << WB << "# COPY & ASSIGNEMENT" << GREY_B << std::endl;
    Array<int> a2 = a1;
    printArrayInfo("a2 (copy of a1)", a2);

    Array<int> a3;
    a3 = a1;
    printArrayInfo("a3 (assigned from a1)", a3);

    std::cout << RES << "... modifying copies .." << GREY_B << std::endl;
    a2[0] = 1000;
    a3[1] = 2000;
    printArrayInfo("a1 (original)", a1);
    printArrayInfo("a2 (modified copy)", a2);
    printArrayInfo("a3 (modified assignment)", a3);
    std::cout << "__________________________________________________________" << std::endl;


    std::cout << RES << WB << "# SUBSCRIPT OPERATOR & BOUNDS" << GREY_B << std::endl;
    std::cout << "a1[2] = " << a1[2] << std::endl;

    try {
        std::cout << "Accessing a1[5] (out of bounds)... ";
        a1[5] = 99;
    } catch (const std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Accessing a0[0] (empty array)... ";
        a0[0] = 99;
    } catch (const std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    std::cout << "__________________________________________________________" << std::endl;

    std::cout << RES << WB << "# CONSTANT" << GREY_B << std::endl;
    const Array<int> const_a1 = a1;
    printArrayInfo("const_a1", const_a1);
    std::cout << "const_a1[1] = " << const_a1[1] << std::endl;
    std::cout << "__________________________________________________________" << std::endl;

    std::cout << RES << WB << WB << "# new int() vs new int[1]" << GREY_B << std::endl;
    int * tip_a = new int(); // Value-initialization
    std::cout << "*tip_a (new int()): " << *tip_a << std::endl;
    delete tip_a;
    Array<int> tip_b(1); // Default-initialization (int might be uninitialized)
    std::cout << "tip_b[0] (new int[1]): " << tip_b[0] << " (value depends on compiler/memory state)" << std::endl;
    std::cout << "__________________________________________________________" << std::endl;

    return 0;
}

/* #define MAX_VAL 750
int main(int, char**) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */
