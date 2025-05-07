#include "Serializer.hpp"
#include <iostream>

int main() {
    Serializer::Data original;
    original.s1 = "Good";
    original.s2 = "Bad";
    original.number = 404;

    std::cout << "Original Data:" << std::endl;
    std::cout << "address: " << &original << std::endl;
    std::cout << "s1: " << original.s1 << std::endl;
    std::cout << "n: " << original.number << std::endl;
    std::cout << "s2: " << original.s2 << std::endl;

    uintptr_t serialized = Serializer::serialize(&original);
    Serializer::Data* deserialized = Serializer::deserialize(serialized);


    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "address: " << deserialized << std::endl;
    std::cout << "s1: " << deserialized->s1 << std::endl;
    std::cout << "n: " << deserialized->number << std::endl;
    std::cout << "s2: " << deserialized->s2 << std::endl;

    // Check pointer equality
    if (deserialized == &original) {
        std::cout << "\nSuccess: Deserialized pointer matches original!" << std::endl;
    } else {
        std::cout << "\nError: Pointer mismatch!" << std::endl;
    }

    return 0;
}
