/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:34:07 by harndt            #+#    #+#             */
/*   Updated: 2023/07/05 20:37:45 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#define SHOW_MSG true

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Data:: Data object
 * 
 */
Data::Data(void) : _quote("pers aspera ad inferi")
{
	if (SHOW_MSG == true)
		LOG("📃 Default constructor called.")
	return ;
}

/**
 * @brief Construct a new Data:: Data object
 * 
 * @param src The object to be copied.
 */
Data::Data(Data const &src)
{
	if (SHOW_MSG == true)
		LOG("📃 Default constructor called.")
	this->setQuote(src.getQuote());
	return ;
}

/**
 * @brief Destroy the Data object
 * 
 */
Data::~Data(void)
{
	if (SHOW_MSG == true)
		LOG("📃 Destructor called.")
	return ;
}

// =============================================================================
// Operator overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Data& A pointer to the assigned Data object.
 */
Data & Data::operator = (Data const &rhs)
{
	if (SHOW_MSG == true)
		LOG("📃 Destructor called.")
	if (this != &rhs)
	this->setQuote(rhs.getQuote());
	return (*this);
}

// =============================================================================
// Get/Set
// =============================================================================

/**
 * @brief Gets the _quote attibute.
 * 
 * @return std::string _quote attribute.
 */
std::string	Data::getQuote(void) const
{
	return (this->_quote);
}

void	Data::setQuote(std::string const &quote)
{
	this->_quote = quote;
	LOG(">Quote updated.");
}