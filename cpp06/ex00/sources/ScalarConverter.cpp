/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:23:01 by harndt            #+#    #+#             */
/*   Updated: 2023/06/29 18:50:30 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define SHOW_MSG true

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Converter:: Converter object
 * 
 */
ScalarConverter::ScalarConverter(void)
{
	if (SHOW_MSG == true)
		LOG("🔄 Default constructor called.");
	return ;
}

/**
 * @brief Construct a new Scalar Converter:: Scalar Converter object
 * 
 * @param src The ScalarConverter object to copy.
 */
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	if (SHOW_MSG == true)
		LOG("🔄 Copy constructor called.");
	(void)src;
	return ;
}

/**
 * @brief Destroy the Converter:: Converter object
 * 
 */
ScalarConverter::~ScalarConverter(void)
{
	if (SHOW_MSG == true)
		LOG("🔄 Destructor called.");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return ScalarConverter& A pointer to the assigned ScalarConverter object.
 */
ScalarConverter & ScalarConverter::operator = (ScalarConverter const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🔄 Assignment operator called.");
	(void)rhs;
	return (*this);
}

// =============================================================================
// Member Function
// =============================================================================

void	ScalarConverter::convert(void)
{
	LOG("convertido!");
}