/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:41:56 by asalo             #+#    #+#             */
/*   Updated: 2024/08/14 12:41:58 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN	"\033[92m"
#define RED		"\033[91m"
#define GREY	"\033[90m"
#define RES		"\033[0m"
#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

/**
 * @brief	Member Functions: Operate on an instance of a class, having access to
 *			the instance specific data. Able to modify the state of the object
 *			they belong to.
 *			- Called on an instance of the class.

 *			Static Member Functions: Operate on the class itself. Unable to access
 *			non-static member variables or the 'this' pointer as they aren't
 *			associated with any particular instance of the class. Able to access
 *			static memver vars shared accross all the class's instances.
 *			- Called on the class itself.
*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Constructor (empty input)*/
Account::Account( void ) {};

/* Constructor, init vals and track the nb of accounts */
Account::Account(int initial_deposit)
	: _nbDeposits(0), _nbWithdrawals(0), _amount(initial_deposit) {
		Account::_totalAmount += _amount;
		_accountIndex = Account::_nbAccounts++;
		_displayTimestamp();
		std::cout
		<< "index:\t" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "created"
		<<std::endl;
}

/* Destructor for Account object, Cleans up when object destroyed */
Account::~Account( void ) {
    _displayTimestamp();
    std::cout
    << "index:\t" << this->_accountIndex << ";"
    << "amount:" << this->checkAmount() << ";" << RED
	<< "closed" << RES
    << std::endl;
}

/* Static member function, total account nb */
int Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
}

/* Static member functions,total money in an account */
int	Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}

/* Static member function */
int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

/* Static member function */
int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

/* Static member function */
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << GREEN
	<< "accounts:\t" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals()
	<< RES << std::endl;
}

/* Member function */
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout <<
	"index:\t" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";" <<
	"deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout
	<< "amount:" << this->checkAmount() << ";"
	<< "nb_deposits:" << this->_nbDeposits
	<< std::endl;
}

/* Member function */
bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout
	<< "index:\t" << this->_accountIndex << ";"
	<< "p_amount:" << this->checkAmount() << ";";
	if (this->checkAmount() < withdrawal) {
		std::cout
		<< "withdrawal:refused"
		<< std::endl;
		return (false);
	}
	else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
		return (true);
	}
}

/* Member function */
int		Account::checkAmount( void ) const {
	return (this->_amount);
}

/* Member function */
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
	<< "index:\t" << this->_accountIndex << ";"
	<< "amount:" << this->checkAmount() << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

/* Static member function */
void	Account::_displayTimestamp( void )
{
	time_t now = std::time(NULL);
	struct tm timenow = *std::localtime(&now);

	std::cout << GREY
	<< "[" << timenow.tm_year + 1900
	<< std::setfill('0') << std::setw(2) << timenow.tm_mon + 1
	<< std::setfill('0') << std::setw(2) << timenow.tm_mday << "_"
	<< std::setfill('0') << std::setw(2) << timenow.tm_hour
	<< std::setfill('0') << std::setw(2) << timenow.tm_min
	<< std::setfill('0') << std::setw(2) << timenow.tm_sec
	<< "] "
	<< RES;
}
