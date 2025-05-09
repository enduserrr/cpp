#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

#define RED     "\033[0;91m"
#define RES     "\033[0m"


int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input sequence provided. Usage: ./PmergeMe <positive_integer_sequence>" << std::endl;
        return 1;
    }
    PmergeMe sorter;
    try {
        sorter.sortAndReport(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RES << std::endl; // Error messages from PmergeMe
        return 1;
    }
    return 0;
}