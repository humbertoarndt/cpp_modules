/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:06:39 by harndt            #+#    #+#             */
/*   Updated: 2023/07/24 13:48:41 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define SHOW_MSG true
std::map<std::string, double>	BitcoinExchange::_map;

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Bitcoin Exchange:: Bitcoin Exchange object
 * 
 */
BitcoinExchange::BitcoinExchange(void)
{
	if (SHOW_MSG == true)
		LOG("Default Constructor Called.");
	return ;
}

/**
 * @brief Construct a new Bitcoin Exchange:: Bitcoin Exchange object
 * 
 * @param src The object to be copied.
 */
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	if (SHOW_MSG == true)
		LOG("Default Constructor Called.");
	*this = src;
	return ;
}

/**
 * @brief Destroy the Bitcoin Exchange:: Bitcoin Exchange object
 * 
 */
BitcoinExchange::~BitcoinExchange(void)
{
	if (SHOW_MSG == true)
		LOG("Destructor Called.");
	return ;
}

// =============================================================================
// Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return BitcoinExchange& A pointer to the assigned BitcoinExchange object.
 */
BitcoinExchange &BitcoinExchange::operator = (BitcoinExchange const &rhs)
{
	if (SHOW_MSG == true)
		LOG("Assignment Operator Called.");
	(void)rhs;
	return (*this);
}

// =============================================================================
// Member Functions
// =============================================================================

/**
 * @brief Checks if a date is in the YYYY-MM-DD format.
 * 
 * @param date The date to check.
 * @return true When date is in the YYYY-MM-DD format.
 * @return false When date isn't in the YYYY-MM-DD format.
 */
static bool	checkDate(std::string date)
{
	if (date.size() != 10)
		return (false);
	if (date[5] != '0' && date[5] != 1) // Month check
		return (false);
	if (date[8] > '3' || date[8] < '0') // Day check
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if(!std::isdigit(date[i]) && date[i] != '-')
			return (false);
	}
	return (true);
}

/**
 * @brief Reads and stores the values from 'data.csv' file in 
 * 'BitcoinExchange::_map'
 * 
 */
void	BitcoinExchange::readData(void)
{
	std::ifstream	data("./data/data.csv");
	std::string		row;
	
	if (!data.is_open())
		return ;
	std::getline(data, row);
	while (std::getline(data, row))
	{
		std::istringstream	iss(row);
		std::string			date;
		std::string			valueStr;

		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr))
			continue ;
		if (!checkDate(date))
			return ;
		double	value = atof(valueStr.c_str());
		BitcoinExchange::_map.insert(std::pair <std::string, double> (date, value));
	}
}

/**
 * @brief Prints all Keys and Values stored in BitcoinExchange::_map.
 * 
 */
void	BitcoinExchange::printMap(void)
{
	std::map<std::string, double>::iterator	it = BitcoinExchange::_map.begin();

	for (; it != BitcoinExchange::_map.end(); it++)
		LOG("Key: " << it->first << ", Value: " << it->second);
}