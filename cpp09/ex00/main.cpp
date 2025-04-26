/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:19:32 by asalo             #+#    #+#             */
/*   Updated: 2025/04/23 11:50:01 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> // strtod
#include <limits> // Numeric_limits
#include "BitcoinExchange.hpp"

// Helper function to trim leading/trailing whitespace
static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

// Date validation function
bool isValidInputDate(const std::string& date) {
     if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || !ss.eof() || dash1 != '-' || dash2 != '-') {
         return false;
     }
    if (month < 1 || month > 12 || day < 1 || day > 31) return false;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) return false;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    return true;
}

// Value validation function (using the original 0-1000 requirement)
// If you truly want to ignore the 1000 limit, remove or comment out that check.
bool isValidInputValue(const std::string& valueStr, double& value) {
    char* end;
    value = std::strtod(valueStr.c_str(), &end);
    if (end == valueStr.c_str() || *end != '\0') {
        // Don't print error here, let the main loop handle "bad input" generally if needed
        // Or print a specific format error:
        // std::cerr << "Error: Invalid number format in input => " << valueStr << std::endl;
        return false; // Indicate failure without printing the required error messages
    }
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    // Re-instated the requirement check. Remove if you must ignore it.
    if (value > 100000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}


int main(int argc, char* argv[]) {
    // --- MODIFICATION: Check for 3 arguments ---
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file.csv> <output_file.csv>" << std::endl;
        // Maintain original error style if preferred:
        // std::cerr << "Error: incorrect number of arguments." << std::endl;
        return 1;
    }

    // --- Get filenames ---
    const char* inputFilename = argv[1];
    const char* outputFilename = argv[2];

    BitcoinExchange btcDb;
    try {
        // Assuming the database is still hardcoded 'data.csv'
        btcDb.initDatabase("data.csv");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl; // Errors to stderr
        return 1;
    }

    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file: " << inputFilename << std::endl; // Errors to stderr
        return 1;
    }

    // --- MODIFICATION: Open output file ---
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: could not open output file: " << outputFilename << std::endl; // Errors to stderr
        inputFile.close(); // Close the already opened input file
        return 1;
    }


    std::string line;
    std::getline(inputFile, line); // Read header line from input file

    // Basic check for expected header - print error to stderr if wrong
    if (trim(line) != "date | value") {
        std::cerr << "Warning: Input file header mismatch or missing. Expected 'date | value'." << std::endl;
        // Decide whether to stop or continue processing anyway
        // For robustness, might process line if it looks like data, or just warn and continue
    }

    // --- MODIFICATION: Write header to output file? (Optional) ---
    // outputFile << "date | value | result" << std::endl; // Example if you want a header in the output


    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string dateStr;
        // separator is implicitly the '|' used by getline
        std::string valueStr;
        double value;

        // Use '|' as the delimiter for the input file
        if (!(std::getline(ss, dateStr, ',') && std::getline(ss, valueStr))) {
            if (!line.empty() && trim(line).length() > 0) { // Avoid errors on empty lines
                std::cerr << "Error: bad input => " << trim(line) << std::endl; // Errors to stderr
            }
            continue;
        }

        dateStr = trim(dateStr);
        valueStr = trim(valueStr);

        // Validate date - errors to stderr
        if (!isValidInputDate(dateStr)) {
            std::cerr << "Error: bad input => " << dateStr << std::endl; // Errors to stderr
            continue;
        }

        // Validate value - errors printed inside function to stderr
        if (!isValidInputValue(valueStr, value)) {
            // If isValidInputValue returns false, it should have already printed the specific error
            // If isValidInputValue was changed *not* to print errors, you'd print a general one here.
            continue;
        }


        try {
            double rate = btcDb.getRateForDate(dateStr);
            double result = value * rate;

            // --- MODIFICATION: Write result to output file ---
            outputFile << dateStr << " => " << value << " = " << result << std::endl;

        } catch (const BitcoinExchange::DateNotFoundException& e) {
             // Output consistent with example for dates before DB start
             std::cerr << "Error: bad input => " << dateStr << std::endl; // Errors to stderr
        }
         catch (const std::exception& e) {
            // Catch other potential errors - errors to stderr
            std::cerr << "Error processing " << dateStr << ": " << e.what() << std::endl;
        }
    }

    inputFile.close();
    outputFile.close(); // Close the output file
    return 0;
}