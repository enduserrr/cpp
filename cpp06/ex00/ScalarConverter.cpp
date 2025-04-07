/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:09:58 by asalo             #+#    #+#             */
/*   Updated: 2025/04/07 18:27:53 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(const std::string &literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal) {
    return (literal == "-inf" || literal == "+inf" || literal == "nan" ||
            literal == "-inff" || literal == "+inff" || literal == "nanf");
}

void ScalarConverter::printChar(double value) {
    if (value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    if (value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(float value, const std::string& literal) {
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
    } else if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value, const std::string &literal) {
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "double: -inf" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "double: +inf" << std::endl;
    } else if (literal == "nan" || literal == "nanf") {
        std::cout << "double: nan" << std::endl;
    } else {
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal) {
    if (literal.empty()) {
        std::cout << "Error: empty input" << std::endl;
        return;
    }

    // Handle char literal
    if (isCharLiteral(literal)) {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // Check if it's a pseudo literal first
    if (isPseudoLiteral(literal)) {
        double value = 0;
        if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
        else if (literal == "+inf" || literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else
            value = std::numeric_limits<double>::quiet_NaN();

        printChar(value);
        printInt(value);
        printFloat(static_cast<float>(value), literal);
        printDouble(value, literal);
        return;
    }

    // Convert string to double as base type
    char* end;
    double value = std::strtod(literal.c_str(), &end);

    // Check if conversion failed or if there's trailing characters (except 'f')
    if (*end != '\0' && (*end != 'f' || *(end + 1) != '\0')) {
        std::cout << "Error: invalid input" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(static_cast<float>(value), literal);
    printDouble(value, literal);
}
