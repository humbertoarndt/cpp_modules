/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:23:01 by harndt            #+#    #+#             */
/*   Updated: 2023/06/26 16:48:57 by harndt           ###   ########.fr       */
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
// Member Function
// =============================================================================

void	ScalarConverter::convert(void)
{
	LOG("convertido!");
}