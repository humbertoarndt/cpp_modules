/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:06:39 by harndt            #+#    #+#             */
/*   Updated: 2023/07/25 12:12:41 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define SHOW_MSG true
std::map<std::string, double>	BitcoinExchange::_map;

// =============================================================================
// Exceptions
// =============================================================================

const char	*BitcoinExchange::InvalidFileException::what(void) const throw()
{
	return (">Error: could not open file.");
}

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
	/* Size check */
	if (date.size() != 10)
		return (false);
	/* Month check */
	if (date[5] != '0' && date[5] != '1')
		return (false);
	/* Day check */
	if (date[8] > '3' || date[8] < '0') // Day check
		return (false);
	/* Only digits check */
	for (size_t i = 0; i < date.size(); i++)
	{
		if(!std::isdigit(date[i]) && date[i] != '-')
			return (false);
	}
	return (true);
}

/**
 * @brief Checks if the value is either a float ora positive integer between
 * 0 and 1000;
 * 
 * @param row The value to check.
 * @return true When value is ok.
 * @return false When value is not ok.
 */
static bool	checkValue(std::string value)
{
	int		i;
	double	nb;

	/* Positive check */
	i = -1;
	while (value[++i] == ' ')
		;
	if (value[i] == '-')
	{
		ERROR(">Error: not a positive number.");
		return (false);
	}

	/* Digitis check */
	i = -1;
	while (value[++i])
	{
		while (value[i] == ' ')
		{
			i++;
		}
			
		if (!std::isdigit(value[i]) && value[i] != '.')
		{
			ERROR(">Error: not a number.");
			return (false);
		}
	}
	
	/* Size check */
	std::istringstream(value) >> nb;
	if (nb > 1000)
	{
		ERROR(">Error: too large a number.");
			return (false);
	}
	return (true);
}

/**
 * @brief Checks if the separator '|' is in the rigth position, and if
 * the row only contain digits.
 * 
 * @param row The row to check.
 * @return true When row is ok.
 * @return false When row is not ok.
 */
static bool	checkSeparator(std::string row)
{
	/* '|' check */
	if (row.find('|') == std::string::npos)
		return (false);
	/* White space check */
	if (row[row.find('|') + 1] != ' ' || row[row.find('|') - 1] != ' ')
		return (false);
	/* Only digits check */
	for (size_t i = 0; i < row.size(); i++)
	{
		if(!std::isdigit(row[i]) && row[i] != '-' && 
			row[i] != '|' && row[i] != '.' && row[i] != ' ')
			return (false);
	}
	return (true);
}

/**
 * @brief Find a date in the database, or the closest and lower one.
 * 
 * @param date The target date to search for.
 * @return double The value in the date or closes and lower date.
 */
double	BitcoinExchange::findLower(const std::string &date)
{
	std::map<std::string, double>::const_iterator it = BitcoinExchange::_map.lower_bound(date);
	const std::string &returnDate = it->first;

	if (it == BitcoinExchange::_map.begin() || returnDate == date)
		return (it->second);
	--it;
	return (it->second);
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
		throw BitcoinExchange::InvalidFileException();
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

/**
 * @brief Calculates the value of bitcoin base on a file and a DB.
 * 
 * @param filename The file to read Date and Value from.
 */
void	BitcoinExchange::executeExchange(char *filename)
{
	std::ifstream	fs(filename);
	std::string		row;

	if (!fs.is_open())
		throw BitcoinExchange::InvalidFileException();
	std::getline(fs, row);
	
	if (row != "date | value")
	{
		ERROR(">Error: bad input => " << row);
		return ;
	}
	
	while (std::getline(fs, row))
	{
		std::string	date;
		std::string	value;
		double		dValue;
		double		closestValue;

		date = row.substr(0, row.find('|') - 1);
		value = row.substr(row.find('|') + 2, row.length());
		if (!checkDate(date) || !checkSeparator(row) || !checkValue(value))
		{
			ERROR(">Error: bad input => " << row);
				continue ;
		}
		
		dValue = atof(value.c_str());
		closestValue = findLower(date);
		LOG(date << " => " << dValue << " = " << closestValue * dValue);
		
		
	}
	
}