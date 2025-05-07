#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>

class  ScalarConverter {
    private:
        ScalarConverter();

        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();

    public:
        static void convert(const std::string& literal);
        static bool isCharLiteral(const std::string& literal);
        static bool isPseudoLiteral(const std::string& literal);
        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(float value, const std::string& literal);
        static void printDouble(double value, const std::string& literal);

};

#endif
