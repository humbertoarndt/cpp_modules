/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:39:57 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 17:45:22 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Wrong Animal:: Wrong Animal object
 * 
 */
WrongAnimal::WrongAnimal(void) : _type("WrongUndefined")
{
	if (SHOW_MSG == true)
		LOG("❌🧬 Default constructor called");
	return ;
}

/**
 * @brief Construct a new Wrong Animal:: Wrong Animal object
 * 
 * @param type The Wrong Animal '_type'
 */
WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{
	if (SHOW_MSG == true)
		LOG("❌🧬 String constructor called");
	return ;
}

/**
 * @brief Construct a new Wrong Animal:: Wrong Animal object
 * 
 * @param src The Wrong Animal object to be copied.
 */
WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	if (SHOW_MSG == true)
		LOG("❌🧬 Copy constructor called");
	this->_type = src.getType();
	return ;
}

/**
 * @brief Destroy the Wrong Animal:: Wrong Animal object
 * 
 */
WrongAnimal::~WrongAnimal(void)
{
	if (SHOW_MSG == true)
		LOG("❌🧬 Destructor called");
	return ;
}

// =============================================================================
// OPERATOR
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return WrongAnimal& A pointer to the assigned WrongAnimal object.
 */
WrongAnimal & WrongAnimal::operator = (WrongAnimal const &rhs)
{
	if (SHOW_MSG == true)
		LOG("❌🧬 Assignment operator called");
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Gets the '_type' attributes.
 * 
 * @return std::string '_type'
 */
std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

/**
 * @brief Prints a string.
 * 
 */
void	WrongAnimal::makeSound(void) const
{
	LOG("Not ahah.wav");
}
