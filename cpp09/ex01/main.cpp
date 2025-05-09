#include "RPN.hpp"
#include <iostream>
#include <string>
#include <stdexcept> // For std::runtime_error

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    std::string expression = argv[1];

    try {
        int result = RPN::evaluate(expression);
        std::cout << result << std::endl;
    } catch (const std::runtime_error& ) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}