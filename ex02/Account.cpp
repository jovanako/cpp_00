/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:24:07 by jkovacev          #+#    #+#             */
/*   Updated: 2026/02/05 21:57:38 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// [19920104_091532]

void Account::_displayTimestamp(void) {
	std::string timestamp;
	
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now);
	
	timestamp = std::string(buffer);
	std::cout << "[" << timestamp << "] ";
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;	
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

// [19920104_091532] index:0;amount:42;created

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0) {

	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
		      << "created" << std::endl;
}

// [19920104_091532] index:0;amount:47;closed

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl; 
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1

void Account::makeDeposit(int deposit) {
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";
	if (withdrawal > _amount) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	
	std::cout << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount << ";"
			  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const {
	return _amount;
}

// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}