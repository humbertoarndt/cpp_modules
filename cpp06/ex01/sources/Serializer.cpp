/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:13:15 by harndt            #+#    #+#             */
/*   Updated: 2023/07/05 21:00:41 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#define SHOW_MSG true

// =============================================================================
// Constructor and Destructors
// =============================================================================

/**
 * @brief Construct a new Serializer:: Serializer object
 * 
 */
Serializer::Serializer(void)
{
	if (SHOW_MSG == true)
		LOG("▶️ Default constructor called.");
	return ;
}

/**
 * @brief Construct a new Serializer:: Serializer object
 * 
 * @param src The Serializer object to copy.
 */
Serializer::Serializer(Serializer const &src)
{
	if (SHOW_MSG == true)
		LOG("▶️ Copy constructor called.");
	(void)src;
	return ;
}

/**
 * @brief Destroy the Serializer:: Serializer object
 * 
 */
Serializer::~Serializer(void)
{
	if (SHOW_MSG == true)
		LOG("▶️ Destructor called.");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Serializer& A pointer to the assigned Serializer object.
 */
Serializer & Serializer::operator = (Serializer const &rhs)
{
	if (SHOW_MSG == true)
		LOG("▶️ Assignment operator called.");
	(void)rhs;
	return (*this);
}

// =============================================================================
// Functions
// =============================================================================

/**
 * @brief Serializes a Data pointer.
 * 
 * @param ptr The Data pointer to be serialized.
 * @return uintptr_t The serialized Data pointer.
 */
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief Deserializes an uintptr_t.
 * 
 * @param raw The uintptr_t to be deserialized.
 * @return Data* The deserialized Data pointer.
 */
Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
