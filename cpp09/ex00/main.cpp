/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:19:32 by asalo             #+#    #+#             */
/*   Updated: 2025/05/02 18:10:14 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> // strtod
#include <exception> // std::exception
#include <algorithm> // std::find
#include "BitcoinExchange.hpp"

#define RED     "\033[0;91m"
#define GB      "\033[1;90m"
#define GC      "\033[3;90m"
#define WB      "\u001b[41;1m"
#define RES     "\033[0m"
#define YELLOW  "\033[0;93m"

static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (std::string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

bool isValidInputDate(const std::string& date) {
     if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    int year, month, day;
    // Use sscanf for potentially more robust parsing than istringstream here
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) return false;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    if (year < 2009)
        return false;

    return true;
}

bool isValidInputValue(const std::string& valueStr, double& value) {
    if (valueStr.empty()) {
         return false;
    }

    char* end;
    value = std::strtod(valueStr.c_str(), &end);

    // Check if conversion failed or if there were trailing non-numeric chars (excluding whitespace handled by trim)
    if (end == valueStr.c_str() || *end != '\0') {
        return false;
    }
    if (value < 0) {
        std::cerr << RED << "Error" << RES GC << ": not a positive number." << RES << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << RED << "Error" << RES GC << ": too large a number." << RES << std::endl;
        return false;
    }
    return true;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr <<  RED << "Error" << RES GC << ": Usage: " << argv[0] << " <input_file.txt>" << RES << std::endl;
        // std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    const char* inputFilename = argv[1];
    const std::string dbFilename = "data.csv";

    BitcoinExchange btcDb;
    try {
        btcDb.initDatabase(dbFilename);
    } catch (const std::exception& e) {
        std::cerr << RED << "Error initializing data" << RES GC << ": " << e.what() << RES << std::endl;
        return 1;
    }

    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << RED << "Error" << RES GC << ": could not open file." << RES << std::endl;
        return 1;
    }

    std::string line;
    bool firstLine = true; // Flag to check the header

    while (std::getline(inputFile, line)) {
        std::string trimmedLine = trim(line);
        if (trimmedLine.empty()) {// Skip empty lines
            continue;
        }
        if (firstLine) {
            firstLine = false;
            if (trimmedLine != "date | value") {
                std::cerr << YELLOW << "Warning" << RES GC << ": Input file header invalid or missing. Expected 'date | value'" << RES << std::endl;
                continue;
            }
            continue;
        }

        std::string dateStr;
        std::string valueStr;
        size_t delimiterPos = trimmedLine.find('|');

        if (delimiterPos == std::string::npos) {
             std::cerr << RED << "Error" << RES GC << ": bad input => " << trimmedLine << RES << std::endl;
             continue;
        }

        dateStr = trim(trimmedLine.substr(0, delimiterPos));
        if (delimiterPos + 1 < trimmedLine.length()) {
             valueStr = trim(trimmedLine.substr(delimiterPos + 1));
        } else {
             valueStr = "";
        }
        if (!isValidInputDate(dateStr)) {
            std::cerr << RED << "Error" << RES GC << ": bad input => " << trimmedLine << RES << std::endl;
            continue;
        }
        double value;
        if (!isValidInputValue(valueStr, value)) {
            // isValidInputValue prints specific errors (negative, too large)
            // If it returned false for other reasons (e.g., non-numeric, empty),
            // we might need a general "bad input" error here, but let's see
            // if the current structure covers the example cases.
            // Re-checking the example: "bad input" seems used for format errors.
            // Let's refine: if validation fails *and* no specific error was printed,
            // print the general "bad input".
            // We need isValidInputValue to signal *why* it failed.
            // Simpler approach: If date is valid but value is not (for any reason other than negative/too large),
            // it's likely a format issue.
            // Let's stick to the current logic: isValidInputValue prints specific errors.
            // If it returns false without printing (e.g., bad format), we need to catch that.

            // Let's modify isValidInputValue slightly to not print for format errors.
            // *Correction*: The current isValidInputValue *doesn't* print for format errors.
            // So, if it returns false, and the value wasn't < 0 or > 1000 (which print errors),
            // then it must be a format error.
             if (value >= 0 && value <= 1000) { // Check if it wasn't the range errors
                 std::cerr << RED << "Error" << RES GC << ": bad input => " << trimmedLine << RES << std::endl;
             }
            continue; // Skip processing this line
        }

        try {
            double rate = btcDb.getRateForDate(dateStr);
            double result = value * rate;

            std::cout << dateStr << " => " << value << " = " << result << std::endl;

        } catch (const BitcoinExchange::DateNotFoundException& e) {
             std::cerr << RED << "Error" << RES GC ": bad input => " << dateStr << RES << std::endl;
        }
         catch (const std::exception& e) {
            std::cerr << RED "Error processing line '" << RES GC << trimmedLine << "': " << e.what() << RES << std::endl;
        }
    }

    inputFile.close();
    return 0;
}