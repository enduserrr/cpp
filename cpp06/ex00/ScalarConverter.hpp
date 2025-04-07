/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:10:00 by asalo             #+#    #+#             */
/*   Updated: 2025/04/07 18:54:44 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class  ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src); //Copy
        ScalarConverter& operator=(const ScalarConverter& src); //Assignement operator
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
