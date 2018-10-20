/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:12:38 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/01 15:12:40 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

static int		_checkAmount_count = 0;

int		Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << _totalAmount
			  << ";deposits:" <<  _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

Account::Account()
{
	_amount = 0;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_totalNbDeposits += _nbDeposits;
	_totalNbWithdrawals += _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" <<std::endl;
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_totalNbDeposits += _nbDeposits;
	_totalNbWithdrawals += _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" <<std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" <<std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << ";deposits:" << deposit << ";amount:" << _amount<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawals:";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	if (!checkAmount())
	{
		std::cout << "refused" << std::endl;
		_amount += withdrawal;
		_totalAmount += withdrawal;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

int Account::checkAmount() const
{
	_checkAmount_count++;
	if (_amount < 0)
		return (0);
	else
		return (1);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits << ";withdrawals:"<< _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp()
{
	std::time_t		t = std::time(0);
	std::tm*		now = std::localtime(&t);

	std::cout << "[" << (now->tm_year + 1900);
	(now->tm_mon < 9) ? std::cout << '0' : 0;
	std::cout << (now->tm_mon + 1);
	(now->tm_mday < 10) ? std::cout <<'0' : 0;
	std::cout << now->tm_mday << '_';
	(now->tm_hour < 10) ? std::cout << '0' : 0;
	std::cout << now->tm_hour;
	(now->tm_min < 10) ? std::cout << '0' : 0;
	std::cout << now->tm_min;
	(now->tm_sec < 10) ? std::cout << '0' : 0;
	std::cout << now->tm_sec << "] ";
}
