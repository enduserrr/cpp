/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:10:03 by asalo             #+#    #+#             */
/*   Updated: 2025/04/15 10:36:05 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"
#include <iostream>

int main() {
    Serializer::Data original;
    original.s1 = "Helo";
    original.n = 41;
    original.s2 = "World";

    // Original
    std::cout << "Original Data:" << std::endl;
    std::cout << "address: " << &original << std::endl;
    std::cout << "s1: " << original.s1 << std::endl;
    std::cout << "n: " << original.n << std::endl;
    std::cout << "s2: " << original.s2 << std::endl;

    // Serialize and deserialize
    uintptr_t serialized = Serializer::serialize(&original);
    Serializer::Data* deserialized = Serializer::deserialize(serialized);

    // Deserialized values
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "address: " << deserialized << std::endl;
    std::cout << "s1: " << deserialized->s1 << std::endl;
    std::cout << "n: " << deserialized->n << std::endl;
    std::cout << "s2: " << deserialized->s2 << std::endl;

    // Check pointer equality
    if (deserialized == &original) {
        std::cout << "\nSuccess: Deserialized pointer matches original!" << std::endl;
    } else {
        std::cout << "\nError: Pointer mismatch!" << std::endl;
    }

    return 0;
}
