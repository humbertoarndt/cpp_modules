/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:06:39 by harndt            #+#    #+#             */
/*   Updated: 2023/07/20 13:10:44 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define SHOW_MSG true

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
	if (this != &rhs)
		*this = rhs;
	return (*this);
}