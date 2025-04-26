/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:21:12 by asalo             #+#    #+#             */
/*   Updated: 2025/04/23 10:36:29 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> // For strtod, atoi
#include <limits> // For numeric_limits
#include <algorithm> // For std::find

// Helper function to trim leading/trailing whitespace
static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// Private copy constructor and assignment operator to prevent copying
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) { (void)other; return *this; }


bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year, month, day;
    char dash1, dash2;

    std::istringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-' || !ss.eof()) {
         return false;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) {
            return false;
        }
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    // Basic check for very early dates potentially before Bitcoin existed
    if (year < 2009) {
         // Technically valid date, but outside typical Bitcoin range.
         // The getRate logic will handle dates before the first DB entry.
    }

    return true;
}

bool BitcoinExchange::isValidDbRate(const std::string& rateStr, double& rate) const {
    char* end;
    rate = std::strtod(rateStr.c_str(), &end);
    return end != rateStr.c_str() && *end == '\0' && rate >= 0.0;
}


void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream dbFile(filename.c_str());
    if (!dbFile.is_open()) {
        throw DatabaseLoadException("Error: could not open database file.");
    }

    std::string line;
    std::getline(dbFile, line); // Skip header

    if (trim(line) != "date,exchange_rate") {
         // Handle case where header might be missing or different,
         // but for this exercise assume it's present and correct.
         // Rewind or process the first line if needed, but simpler to assume skip.
         // If the first line was actually data:
         // dbFile.seekg(0, std::ios::beg);
         // std::cerr << "Warning: Database header missing or incorrect." << std::endl;
    }


    while (std::getline(dbFile, line)) {
        std::stringstream ss(line);
        std::string dateStr;
        std::string rateStr;
        double rateValue;

        if (std::getline(ss, dateStr, ',') && std::getline(ss, rateStr)) {
             dateStr = trim(dateStr);
             rateStr = trim(rateStr);
            if (isValidDate(dateStr) && isValidDbRate(rateStr, rateValue)) {
                _exchangeRates[dateStr] = rateValue;
            } else {
                 // Optionally warn about invalid lines in DB
                 // std::cerr << "Warning: Invalid database line skipped: " << line << std::endl;
            }
        }
    }

    if (_exchangeRates.empty()) {
        throw DatabaseLoadException("Error: database is empty or contains no valid data.");
    }
}


void BitcoinExchange::initDatabase(const std::string& filename) {
    try {
        loadDatabase(filename);
    } catch (const std::exception& e) {
        throw; // Rethrow to be caught in main
    }
}

double BitcoinExchange::getRateForDate(const std::string& date) const {
    if (_exchangeRates.empty()) {
         throw DateNotFoundException("Error: Database not loaded or empty.");
    }

    // Find the first element that is not less than the target date
    std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);

    // Case 1: Exact match found
    if (it != _exchangeRates.end() && it->first == date) {
        return it->second;
    }

    // Case 2: Input date is before the first date in the database
    if (it == _exchangeRates.begin()) {
        throw DateNotFoundException("Error: no data available for or before this date => " + date);
    }

    // Case 3: No exact match, need the closest *earlier* date.
    // lower_bound gave us the first element *greater* than date (or end()).
    // We need the element just before it.
    --it; // Move to the previous element (guaranteed to exist because it != begin())
    return it->second;
}

// const char *BitcoinExchange::DateNotFoundException::what() const throw() {
//     return "Grade is too high";
// }

// const char *BitcoinExchange::DatabaseLoadException::what() const throw() {
//     return "Grade is too low";
// }