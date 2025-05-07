/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:21:24 by asalo             #+#    #+#             */
/*   Updated: 2025/05/07 12:28:55 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BITCOINEXCHANGE_HPP
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

#endif