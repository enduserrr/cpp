// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <cstdlib> // strtod
// #include <exception> // std::exception
// #include <algorithm> // std::find
// #include "BitcoinExchange.hpp"

// #define RED     "\033[0;91m"
// #define GC      "\033[3;90m"
// #define RES     "\033[0m"
// #define YELLOW  "\033[0;93m"


// /**
//  * @brief   Removes leading & trailing whitespace from a given string.
// */
// static std::string trim(const std::string& str) {
//     size_t first = str.find_first_not_of(" \t\n\r\f\v");
//     if (std::string::npos == first) {
//         return "";
//     }
//     size_t last = str.find_last_not_of(" \t\n\r\f\v");
//     return str.substr(first, (last - first + 1));
// }

// /**
//  * @brief   Validates the given input date.
//  *          (length, separators, date format, leap years)
// */
// bool isValidInputDate(const std::string& date) {
//      if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
//         return false;
//     }
//     /**
//      * @details sscanf (string scan formatted) tries to match a pattern in
//      *          the format string against the input string.
//      * @returns 3 if all (year, month, day) are succesfully matched/validated.
//     */
//     int year, month, day;
//     if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
//         return false;
//     }

//     if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
//         return false;
//     }

//     if (month == 2) {
//         bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//         if (day > (isLeap ? 29 : 28)) return false;
//     } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
//         return false;
//     }

//     if (year < 2009)
//         return false;

//     return true;
// }

// /**
//  * @brief   Validates value representing quantity in the input.txt file.
// */
// bool isValidInputValue(const std::string& valueStr, double& value) {
//     if (valueStr.empty()) {
//          return false;
//     }

//     char* end;
//     value = std::strtod(valueStr.c_str(), &end);

//     // Check if conversion failed or if there were trailing non-numeric chars
//     if (end == valueStr.c_str() || *end != '\0') {
//         return false;
//     } // Has to be positive nb
//     if (value < 0) {
//         std::cerr << RED << "Error" << RES GC << ": not a positive number" << RES << std::endl;
//         return false;
//     } // Must be lower than 1000
//     if (value > 1000) {
//         std::cerr << RED << "Error" << RES GC << ": number too large" << RES << std::endl;
//         return false;
//     }
//     return true;
// }

// /**
//  * @brief   Init data base, open input file, rm whitespace & validate line by line, calls getRateForDate()
//  *          to get price from data.csv for the date and amount specified in input.txt.
// */
// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         std::cerr <<  RED << "Error" << RES GC << ": Usage: " << argv[0] << " <input_file.txt>" << RES << std::endl;
//         return 1;
//     }
//     const char* inputFilename = argv[1];
//     const std::string dbFilename = "data.csv";

//     BitcoinExchange btcDb;
//     try {
//         btcDb.initDatabase(dbFilename);
//     } catch (const std::exception& e) {
//         std::cerr << RED << "Error initializing data" << RES GC << ": " << e.what() << RES << std::endl;
//         return 1;
//     }

//     std::ifstream inputFile(inputFilename);
//     if (!inputFile.is_open()) {
//         std::cerr << RED << "Error" << RES GC << ": could not open file" << RES << std::endl;
//         return 1;
//     }

//     std::string line;
//     bool firstLine = true; // Flag to check the header

//     while (std::getline(inputFile, line)) {
//         std::string trimmedLine = trim(line);
//         if (trimmedLine.empty()) {// Skip empty lines
//             continue;
//         }
//         if (firstLine) {
//             firstLine = false;
//             if (trimmedLine != "date | value") {
//                 std::cerr << YELLOW << "Warning" << RES GC << ": Input file header invalid or missing. Expected 'date | value'" << RES << std::endl;
//                 continue;
//             }
//             continue;
//         }

//         std::string dateStr;
//         std::string valueStr;
//         size_t delimiterPos = trimmedLine.find('|');

//         if (delimiterPos == std::string::npos) {
//              std::cerr << RED << "Error" << RES GC << ": bad input => " << trimmedLine << RES << std::endl;
//              continue;
//         }

//         dateStr = trim(trimmedLine.substr(0, delimiterPos));
//         if (delimiterPos + 1 < trimmedLine.length()) {
//              valueStr = trim(trimmedLine.substr(delimiterPos + 1));
//         } else {
//              valueStr = "";
//         }
//         if (!isValidInputDate(dateStr)) {
//             std::cerr << RED << "Error" << RES GC << ": bad input => " << trimmedLine << RES << std::endl;
//             continue;
//         }
//         double value;
//         if (!isValidInputValue(valueStr, value)) {
//              if (value >= 0 && value <= 1000) {
//                  std::cerr << RED << "Error" << RES GC << ": bad input => " << trimmedLine << RES << std::endl;
//              }
//             continue; // Skip processing the line
//         }

//         try {
//             double rate = btcDb.getRateForDate(dateStr);
//             double result = value * rate;

//             std::cout << dateStr << " => " << value << " = " << result << std::endl;

//         } catch (const BitcoinExchange::DateNotFoundException& e) {
//              std::cerr << RED << "Error" << RES GC ": bad input => " << dateStr << RES << std::endl;
//         }
//          catch (const std::exception& e) {
//             std::cerr << RED "Error processing line '" << RES GC << trimmedLine << "': " << e.what() << RES << std::endl;
//         }
//     }

//     inputFile.close();
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib> // For std::strtod in main's trim (if any) or general utilities
#include <cstdio>  // For sscanf in main's trim (if any)
#include "BitcoinExchange.hpp" // Your BitcoinExchange class


#define RED "\033[91m"
#define GC "\033[2;90m"
#define YELLOW "\033[93m"
#define RES "\033[0m"


static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (std::string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << RED << "Error" << RES GC << ": Usage: " << argv[0] << " <input_file.txt>" << RES << std::endl;
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
    bool firstLine = true;

    while (std::getline(inputFile, line)) {
        std::string trimmedLine = trim(line);
        if (trimmedLine.empty()) { // Skip empty lines
            continue;
        }

        if (firstLine) {
            firstLine = false;
            if (trimmedLine == "data | value") { 
                continue;
            } else {
                std::cerr << YELLOW << "Warning" << RES GC << ": Input file header invalid or missing. Expected 'data | value'" << RES << std::endl;
            }
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

        try {
            btcDb.validateInputLineDate(dateStr);
            double value = btcDb.parseAndValidateInputLineValue(valueStr);
            double rate = btcDb.getRateForDate(dateStr); // Can throw DateNotFoundException
            double result = value * rate;

            std::cout << dateStr << " => " << value << " = " << result << std::endl;

        } catch (const BitcoinExchange::InvalidInputDateException& e) {
            // For any date validation error from validateInputLineDate
            std::cerr << RED << "Error" << RES GC << ": bad input => " << dateStr << RES << std::endl;
        } catch (const BitcoinExchange::NonPositiveValueException& e) {
            // Specific error message from parseAndValidateInputLineValue
            std::cerr << RED << "Error" << RES GC << ": " << e.what() << RES << std::endl;
        } catch (const BitcoinExchange::ValueTooLargeException& e) {
            // Specific error message from parseAndValidateInputLineValue
            std::cerr << RED << "Error" << RES GC << ": " << e.what() << RES << std::endl;
        } catch (const BitcoinExchange::InvalidInputValueException& e) {
            // For general value parsing errors (empty, not a number)
            std::cerr << RED << "Error" << RES GC << ": bad input => " << trimmedLine << RES << std::endl;
        } catch (const BitcoinExchange::DateNotFoundException& e) {
            // This is when getRateForDate itself can't find a rate (e.g., date too early for DB)
            // The original main.cpp printed "bad input => <dateStr>" for this.
            std::cerr << RED << "Error" << RES GC << ": bad input => " << dateStr << RES << std::endl;
        }
         catch (const std::exception& e) { // Catch-all for other unexpected errors
            std::cerr << RED << "Error processing line '" << RES GC << trimmedLine << "': " << e.what() << RES << std::endl;
        }
    }

    inputFile.close();
    return 0;
}