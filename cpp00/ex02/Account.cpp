/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:12:01 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 11:26:49 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// =============================================================================
// CONTRUCTOR AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Account:: Account object
 * 
 * @param initial_deposit Initial deposit to start class.
 */
Account::Account (int initial_deposit) :
		_accountIndex(Account::_nbAccounts++),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";";
	std::cout << "amount: " <<_amount << ";";
	std::cout << "created" << std::endl;
}

/**
 * @brief Construct a new Account:: Account object
 * 
 */
Account::Account (void) :
		_accountIndex(Account::_nbAccounts++),
		_amount(0),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	return ;
}

/**
 * @brief Destroy the Account:: Account object
 * 
 */
Account::~Account (void)
{
	Account::_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";";
	std::cout << "amount: " << _amount << ";";
	std::cout << "closed" << std::endl;
}

// =============================================================================
// GETTER FUNCTIONS
// =============================================================================

/**
 * @brief Get the number os accounts created.
 * 
 * @return int The number of existing accounts.
 */
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

/**
 * @brief Get the total amount an account holds
 * 
 * @return int The amount stored in an account.
 */
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

/**
 * @brief Get the total of deposits made into an account.
 * 
 * @return int The total number of deposits.
 */
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

/**
 * @brief Get the total of withdrawals made into an account.
 * 
 * @return int The total number of withdrawals.
 */
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

// =============================================================================
// FUNCTIONS
// =============================================================================

/**
 * @brief Displays the info from accounts.
 * 
 */
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "cccounts: " << Account::_nbAccounts << ";";
	std::cout << "total: " << Account::_totalAmount << ";";
	std::cout << "deposits: " << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals: " << Account::_totalNbWithdrawals;
	std::cout << std::endl;
}

/**
 * @brief Makes a deposit into an account.
 * 
 * @param deposit The value to deposit into an account.
 */
void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";";
	std::cout << "p_amount: " << _amount << ";";
	std::cout << "deposit: " << deposit << ";";
	std::cout << "amount: " << (_amount += deposit) << ";";
	std::cout << "nb_deposits: " << _nbDeposits++;
	std::cout << std::endl;
	
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

/**
 * @brief Withdrawals a value from an account.
 * 
 * @param withdrawal Value to withdrawal.
 * @return true On success
 * @return false On failure
 */
bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "pndex: " << _accountIndex << ";";
	std::cout << "p_amount: " << _amount << ";";
	std::cout << "withdrawal: ";
	
	if (checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	
	std::cout << withdrawal << ";";
	std::cout << "amount: " << (_amount -= withdrawal) << ";";
	std::cout << "nb_withdrawals: " << _nbWithdrawals++ << ";";
	std::cout << std::endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

/**
 * @brief Get the amount stored in an accuunt.
 * 
 * @return int 
 */
int		Account::checkAmount( void ) const
{
	return (_amount);
}

/**
 * @brief Displays the status from accounts.
 * 
 */
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";";
	std::cout << "amount: " << _amount << ";";
	std::cout << "deposits: " << _nbDeposits << ";";
	std::cout << "withdrawals: " << _nbAccounts << ";";
	std::cout << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/**
 * @brief Displays the correct timestamp.
 * 
 */
void	Account::_displayTimestamp( void )
{

	time_t	curr_time;
	tm *curr_tm;
	char	time_stamp[19];

	time(&curr_time);
	curr_tm = localtime(&curr_time);
	strftime(time_stamp, 19, "[%Y%m%d_%H%M%S] ", curr_tm);
	std::cout << time_stamp;
}
