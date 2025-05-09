/* #ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <exception>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, double> _exchangeRates;

    BitcoinExchange(const BitcoinExchange& src);
    BitcoinExchange& operator=(const BitcoinExchange& src);

    void loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date) const;
    bool isValidDbRate(const std::string& rateStr, double& rate) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void initDatabase(const std::string& filename);
    double getRateForDate(const std::string& date) const;

    class DatabaseLoadException : public std::runtime_error {
    public:
        DatabaseLoadException(const std::string& msg) : std::runtime_error(msg) {}
    };

    class DateNotFoundException : public std::runtime_error {
      public:
        DateNotFoundException(const std::string& msg) : std::runtime_error(msg) {}
    };
};

#endif */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string> // Added for std::string
#include <map>
#include <exception>
#include <stdexcept>
#include <sstream> // For istringstream in existing isValidDate

// Forward declare the trim function if it's a non-member static in BitcoinExchange.cpp
// Or ensure it's defined before use if it becomes a public static member.
// For simplicity, assuming it's a non-member static in BitcoinExchange.cpp as per your snippet.

class BitcoinExchange {
private:
    std::map<std::string, double> _exchangeRates;

    // Unchanged private methods
    BitcoinExchange(const BitcoinExchange& src);
    BitcoinExchange& operator=(const BitcoinExchange& src);
    void loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date) const; // For DB loading
    bool isValidDbRate(const std::string& rateStr, double& rate) const; // For DB loading

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void initDatabase(const std::string& filename);
    double getRateForDate(const std::string& date) const; // Existing method

    // New methods for input file line validation
    void validateInputLineDate(const std::string& dateStr) const;
    double parseAndValidateInputLineValue(const std::string& valueStr) const;

    // Existing Exception classes
    class DatabaseLoadException : public std::runtime_error {
    public:
        DatabaseLoadException(const std::string& msg) : std::runtime_error(msg) {}
    };

    class DateNotFoundException : public std::runtime_error {
      public:
        DateNotFoundException(const std::string& msg) : std::runtime_error(msg) {}
    };

    // New Exception classes for input line validation
    class InvalidInputDateException : public std::runtime_error {
    public:
        InvalidInputDateException(const std::string& msg) : std::runtime_error(msg) {}
    };

    class InvalidInputValueException : public std::runtime_error { // For general parsing errors
    public:
        InvalidInputValueException(const std::string& msg) : std::runtime_error(msg) {}
    };

    class NonPositiveValueException : public std::runtime_error { // Specific value error
    public:
        NonPositiveValueException(const std::string& msg) : std::runtime_error(msg) {}
    };

    class ValueTooLargeException : public std::runtime_error { // Specific value error
    public:
        ValueTooLargeException(const std::string& msg) : std::runtime_error(msg) {}
    };
};

#endif