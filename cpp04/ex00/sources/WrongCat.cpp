/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:27:28 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 17:44:06 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Wrong Cat:: Wrong Cat object
 * 
 */
WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	if (SHOW_MSG == true)
		LOG("❌🐈 Default constructor called");
	return ;
}

/**
 * @brief Construct a new Wrong Cat:: Wrong Cat object
 * 
 * @param src The Wrong Cat object to be copied.
 */
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	if (SHOW_MSG == true)
		LOG("❌🐈 Copy constructor called");
	this->_type = src.getType();
	return ;
}

/**
 * @brief Destroy the Wrong Cat:: Wrong Cat object
 * 
 */
WrongCat::~WrongCat(void)
{
	if (SHOW_MSG == true)
		LOG("❌🐈 Destructor called");
	return ;
}

// =============================================================================
// OPERATORS OVERLOAD
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return WrongCat& A pointer to the assigned WrongCat object.
 */
WrongCat & WrongCat::operator = (WrongCat const &rhs)
{
	if (SHOW_MSG == true)
		LOG("❌🐈 Assignment operator called");
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Prints a string.
 * 
 */
void	WrongCat::makeSound(void) const
{
	LOG("Not a meow");
}
